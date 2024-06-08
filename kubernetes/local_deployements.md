you can run using [minicube](https://minikube.sigs.k8s.io/docs/start/?)!
small open-source program where both the master and node both run on one machine

you can interact with the cluster using [cubectl](https://kubernetes.io/docs/tasks/tools/)!


minikube can either start as a container or a virtual machine (make sure you have docker installed)

## Setting it up
you can start minikube by running `minikube start --driver=docker`

## Checking
just use `minikube status`

## Interacting with Minikube
1. get the node using `kubectl get node`

*Note: when creating secrets, you can just use `echo -n datahere | base64` to encode it*