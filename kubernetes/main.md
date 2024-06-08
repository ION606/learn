My notes from https://www.youtube.com/watch?v=s_o8dwzRlu4 and other videos

# What is kubernetes
* an open source container orchestration tool
* helps you manage apps that are made of 100s or 1000s of containers in different dev environments (cloud, local, etc)


## Container Orchestration Tool
* manages many containers
* offers high availability (little to no downtime)
* offers scalability
* offers disaster recovery (backup and restore)


## Kubernetes Cluster Structure
### at least 1 Master Node
has:
* API Server (the entrypoint for the kubernetes cluster), this is what the kubernetes clients (UI, API, CLI, etc) will talk to
* Controller Manager
	- keeps track of the cluster (i.e. a container has died, restart it)
* Scheduler
	- decides on which node any new container should be scheduled
	- it does this based on workload, server resources on each node, etc
* etcd
	- key/value storage for the current state of the cluster
	- holds the current config data, status data of each node/the node's container, etc
	- snapshots of this etcd are used for RECOVERY

**connected to it, there are many smaller**

### Worker Nodes
all of which have:
* a kublet (kubernetes process that talks to other kublets and master node) running on it
* docker containers (which do the work)


### Virtual Network
* spans all the nodes in the cluster
* enables the nodes to talk to each other

*Note: in most prod environments, it's recommended to have more than one master node so that if one of them fails, the process can continue running*
