# **Mail Server with WireGuard and Linode Proxy**

This guide will set up a mail server on a local machine (Fedora) behind a restricted network. A **Linode VPS** (Ubuntu) will act as a proxy to forward traffic using **WireGuard** and **rinetd**. The webmail interface will be provided via **RainLoop** running in a Docker container.

---

## **Prerequisites**

- **Linode VPS** with a public IP: `<LINODE_PUBLIC_IP>`
- **Local Fedora Server** (mail server) without direct internet access.
- **Domain**: `<your-domain.com>` (e.g., `ion606.com`)
- Tools installed:
  - **Docker** and **Docker Compose**
  - **WireGuard**
  - **Postfix** and **Dovecot**
  - **Nginx**

---

# **1. Set Up WireGuard VPN**

WireGuard will create a private VPN tunnel between your Linode VPS and your local Fedora server.

---

## **1.1 Generate WireGuard Keys**

### On the **Linode VPS**:
```bash
wg genkey | tee linode-private.key | wg pubkey > linode-public.key
cat linode-private.key  # Save this for later
cat linode-public.key   # Save this for later
```

### On the **Local Server**:
```bash
wg genkey | tee local-private.key | wg pubkey > local-public.key
cat local-private.key  # Save this for later
cat local-public.key   # Save this for later
```

---

## **1.2 Configure WireGuard**

### On the **Linode VPS** (`/etc/wireguard/wg0.conf`):

```ini
[Interface]
PrivateKey = <LINODE_PRIVATE_KEY>
Address = 10.0.0.1/24
ListenPort = 51820

[Peer]
PublicKey = <LOCAL_PUBLIC_KEY>
AllowedIPs = 10.0.0.2/32
PersistentKeepalive = 25
```

### On the **Local Server** (`/etc/wireguard/wg0.conf`):

```ini
[Interface]
PrivateKey = <LOCAL_PRIVATE_KEY>
Address = 10.0.0.2/24

[Peer]
PublicKey = <LINODE_PUBLIC_KEY>
AllowedIPs = 10.0.0.1/32
Endpoint = <LINODE_PUBLIC_IP>:51820
PersistentKeepalive = 25
```

---

## **1.3 Start WireGuard**

### Enable and Start WireGuard on Both Servers:
```bash
sudo systemctl enable wg-quick@wg0
sudo systemctl start wg-quick@wg0
```

### Verify the Tunnel:
```bash
ping 10.0.0.1  # From local server
ping 10.0.0.2  # From Linode VPS
```

---

# **2. Forward Mail Traffic Using rinetd**

Install and configure `rinetd` on the Linode VPS to forward mail traffic to your local server.

### **Install rinetd**:
```bash
sudo apt update
sudo apt install rinetd -y
```

### **Configure rinetd**:
Edit `/etc/rinetd.conf`:
```plaintext
0.0.0.0 587 10.0.0.2 587
0.0.0.0 993 10.0.0.2 993
```

Restart `rinetd`:
```bash
sudo systemctl restart rinetd
```

---

# **3. Install and Configure Mail Server (Postfix + Dovecot)**

## **3.1 Install Postfix and Dovecot**

On the **local Fedora server**:
```bash
sudo dnf install postfix dovecot -y
```

---

## **3.2 Configure Postfix**

Edit `/etc/postfix/main.cf`:
```ini
inet_interfaces = 10.0.0.2
myhostname = mail.<your-domain.com>
mydomain = <your-domain.com>
myorigin = $mydomain
mydestination = $myhostname, localhost.$mydomain, localhost, $mydomain
relay_domains = $mydestination
mynetworks = 127.0.0.0/8, 10.0.0.1/32
smtp_use_tls = yes
smtpd_use_tls = yes
smtpd_tls_cert_file = /etc/ssl/certs/ssl-cert-snakeoil.pem
smtpd_tls_key_file = /etc/ssl/private/ssl-cert-snakeoil.key
```

Restart Postfix:
```bash
sudo systemctl restart postfix
```

---

## **3.3 Configure Dovecot**

Edit `/etc/dovecot/conf.d/10-mail.conf`:
```ini
mail_location = mbox:~/mail:INBOX=/var/mail/%u
```

Edit `/etc/dovecot/conf.d/10-ssl.conf`:
```ini
ssl = yes
ssl_cert = </etc/ssl/certs/dovecot-selfsigned.pem
ssl_key = </etc/ssl/private/dovecot-selfsigned.key
```

Restart Dovecot:
```bash
sudo systemctl restart dovecot
```

---

# **4. Set Up RainLoop Webmail in Docker**

## **4.1 Create Docker Compose File**

Create the following structure:
```plaintext
~/docker/rainloop/
└── docker-compose.yml
```

**`docker-compose.yml`**:
```yaml
version: '3.8'

services:
  rainloop:
    container_name: rainloop
    image: hardware/rainloop
    restart: always
    volumes:
      - ./data:/rainloop/data:z
    ports:
      - "8888:8888"
```

---

## **4.2 Start RainLoop**

From the `~/docker/rainloop/` directory, run:
```bash
sudo docker-compose up -d
```

---

## **4.3 Access RainLoop Admin Panel**

1. Open a browser and visit:
   ```
   https://mail.<your-domain.com>:8888/?admin
   ```

2. Log in with:
   - **Username**: `admin`
   - **Password**: `12345` (default).

3. Add your domain configuration:
   - **IMAP**: `mail.<your-domain.com>` (Port 993, SSL)
   - **SMTP**: `mail.<your-domain.com>` (Port 587, STARTTLS)

Test the configuration and save.

---

# **5. Update DNS Records**

Set the following DNS records in your provider (e.g., Cloudflare):

- **MX Record**:
   - Name: `@`
   - Content: `mail.<your-domain.com>`
   - Priority: `10`

- **A Record**:
   - Name: `mail`
   - Content: `<LINODE_PUBLIC_IP>`

---

# **6. Test the Mail Server**

1. **Send a test email** to `user@<your-domain.com>` from an external account (e.g., Gmail).

2. Log in to RainLoop:
   - Visit: `https://mail.<your-domain.com>:8888`
   - Log in with your email account credentials.

3. Check for incoming emails.

---

# **7. Errors and Troubleshooting**

_Sidenote: Here are the commands to view the logs from the above programs_
- **Postfix Logs**:  
   ```bash
   sudo tail -f /var/log/maillog
   ```
- **Dovecot Logs**:
   ```bash
   sudo tail -f /var/log/dovecot.log
   ```
- **RainLoop Errors**:
   Check `~/docker/rainloop/data/_data_/logs/`.

---

## **1. WireGuard: "Required key not available"**

### **Cause**:
- Missing or mismatched WireGuard keys.
- Configuration errors in the `AllowedIPs` or `Endpoint`.

### **Solution**:
- Regenerate and verify keys on both servers:
   ```bash
   wg genkey | tee private.key | wg pubkey > public.key
   ```
- Replace keys in `/etc/wireguard/wg0.conf` and restart WireGuard:
   ```bash
   sudo systemctl restart wg-quick@wg0
   ```
- Verify the tunnel with `wg show` and ping test (`ping 10.0.0.1` and `ping 10.0.0.2`).

---

## **2. Postfix: "inet_interfaces: no local interface found"**

### **Cause**:
- Postfix is configured to bind to `10.0.0.2` before WireGuard is active.

### **Solution**:
- Temporarily set Postfix to listen on all interfaces:
   ```ini
   inet_interfaces = all
   ```
- Use systemd overrides to start Postfix after WireGuard:
   ```bash
   sudo systemctl edit postfix
   ```
   Add:
   ```ini
   [Unit]
   After=network.target wg-quick@wg0.service
   Wants=wg-quick@wg0.service
   ```

Restart Postfix:
```bash
sudo systemctl restart postfix
```

---

## **3. RainLoop: "Data folder permissions error [is_readable]"**

### **Cause**:
- RainLoop container cannot access the host `data` directory due to file ownership or SELinux restrictions.

### **Solution**:
1. Fix directory ownership for RainLoop's user (`UID 33`):
   ```bash
   sudo chown -R 33:33 ~/docker/rainloop/data
   sudo chmod -R 755 ~/docker/rainloop/data
   ```

2. Adjust SELinux labels (Fedora specific):
   ```bash
   sudo chcon -R -t container_file_t ~/docker/rainloop/data
   ```

3. Update `docker-compose.yml` to add `:z` for SELinux compatibility:
   ```yaml
   volumes:
     - ./data:/rainloop/data:z
   ```

Restart RainLoop:
```bash
sudo docker-compose down
sudo docker-compose up -d
```

---

## **4. Dovecot: "ssl_cert: Can't open file"**

### **Cause**:
- The SSL certificate file is missing or incorrectly referenced.

### **Solution**:
1. Generate a self-signed SSL certificate:
   ```bash
   sudo mkdir -p /etc/ssl/certs /etc/ssl/private
   sudo openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
     -keyout /etc/ssl/private/dovecot-selfsigned.key \
     -out /etc/ssl/certs/dovecot-selfsigned.pem \
     -subj "/C=US/ST=State/L=City/O=Organization/OU=IT/CN=mail.<your-domain.com>"
   ```

2. Update Dovecot's configuration in `/etc/dovecot/conf.d/10-ssl.conf`:
   ```ini
   ssl = yes
   ssl_cert = </etc/ssl/certs/dovecot-selfsigned.pem
   ssl_key = </etc/ssl/private/dovecot-selfsigned.key
   ```

3. Restart Dovecot:
   ```bash
   sudo systemctl restart dovecot
   ```

---

## **5. rinetd Errors: Permission Denied**

### **Cause**:
- `rinetd` may not have permissions to forward traffic.

### **Solution**:
1. Ensure `rinetd.conf` is properly configured:
   ```plaintext
   0.0.0.0 587 10.0.0.2 587
   0.0.0.0 993 10.0.0.2 993
   ```

2. Restart `rinetd`:
   ```bash
   sudo systemctl restart rinetd
   ```

3. Check for SELinux interference:
   ```bash
   sudo setenforce 0  # Temporarily disable SELinux for testing
   ```

   If this resolves the issue, fix SELinux permanently:
   ```bash
   sudo chcon -R -t container_file_t /etc/rinetd.conf
   ```

---

## **Summary of Error Handling**

| **Error**                               | **Cause**                       | **Solution**                                   |
|-----------------------------------------|---------------------------------|-----------------------------------------------|
| Required key not available (WireGuard)  | Missing/mismatched keys         | Regenerate keys and verify configuration.     |
| inet_interfaces error (Postfix)         | WireGuard interface not active  | Delay Postfix startup using systemd overrides.|
| Data folder permissions error (RainLoop)| Ownership or SELinux restriction| Fix ownership (`chown`) and SELinux labels.   |
| ssl_cert error (Dovecot)                | Missing SSL certificate         | Generate a self-signed SSL certificate.       |
| rinetd permission denied                | SELinux or misconfigurations    | Fix permissions and test SELinux compatibility.|

