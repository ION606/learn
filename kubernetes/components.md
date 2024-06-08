## Worker Node
can be a physical server, virtual machine, etc

made up of........
## pods
- a wrapper over a container so that Kubernetes can replace them if necessary
- there is usually 1 application per pod (or 1 application with a helper)


**pods are EPHEMERAL** (they can die very easily)
★ for example, if the app contained in the pod's wrapped container crashes, runs out of resources, etc

when this happens, a new pod is created in it's place, with a new address.
To work with this, we attach a.....

## Service
- a static IP address that is attatched to each pod/app
- an app (stored in a node) will have it's own service/database, and every pod will have it's own service
- the service lifetime is not connected to the pod's, so when the pod is replaced, the same internal IP can be used
- also works as a load balancer when allocating requests to pods


There are **two types of services**
1. internal
    - this is the default type
    - can not be accessed externally
2. external
    - you must specify this when creating a service
    - can communicate externally (i.e. via browser for a web app's endpoint)
    - can be accessed via http://[node_ip_addr][service_port_number]

what if you want to access something, but it needs to be via some sort of domain?
use.....

## Ingress
- exposes HTTP and HTTPS routes from outside the cluster to services within the cluster
- you set **rules**, which will then decide how requests are routed (forewarded to services or otherwise)

<hr>

## ConfigMap
- external configurations for your application (i.e. database urls)
- connected to pods so that they have access to this data
- this allows you to just change the value in the configMap without re-building the pods
- stored in plaintext

**HOWEVER**
This type of storage is ***NOT*** secure, so kubernetes offers.....

## Secret
- just like configMap, but for secrets (i.e. usernames, passowrd, etc)
- stored in base64-encoded format
- is meant to be encrypted using third-party tools (perhaps given by the cloud provider)


**BOTH** ConfigMap and Secret can be used inside of pods like env vars or as a properties file

<hr>

## Volume
- used for data storage
★ imagine there is a "database" pod. If that pod restarts, your data is gone
- attaches physical storage to a pod
- can be on the same machine the pod is running on or a remote source outside of the cluster
- **kubernetes does not manage data persistance**