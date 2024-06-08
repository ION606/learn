## Initial Steps (readying your app)
*Note: I assume you already have a minikube running*
1. check if you have any pods running with `kubectl get pod` and stop them if so

2. create external configurations
    - kubectl apply -f mongo-config.yaml
    - kubectl apply -f mongo-secret.yaml
    ★ the -f is for file

3. create connection for the database
    - kubectl apply -f mongo.yaml

4. deploy the web app
    - kubectl apply -f webapp.yaml


## Kubectl
1. check your pods using `kubectl get all`
2. check your configmap using `kubectl get configmap`
3. check your secrets using `kubectl get secret`

 - you can use `kubectl get [component_name]` to get some data for any component or run `kubectl get --help` for help with the `get` subcommand

 - you can use `kubectl describe service [service_name]` to get a description of the service

 - you can use `kubectl logs [pod_name]` to get the logs for that pod

## Accessing the Application Externally
In our case from the browser
1. use `kubectl get svc` to get the service
2. get the `nodPort`'s ip using `minikube ip`
★ you can access more data using `kubectl get node -o wide`
3. access the ip using the corresponding IP address : port