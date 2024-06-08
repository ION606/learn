to avoid downtime, create a......

## Deployement
- a blueprint for for a process-specific pod
- you specify how many replicas of the pod to make
- this is an *abstraction* on top of pods
- can scale up or down
★ if one of the replicated pods dies, the service will simply foreward the request to whatever pod has the lightest load

what if multiple pods want to write to a storage medium? Then we have to use a......

## StatefulSet
- replaces deployements for *stateful* apps (apps that need static information)  
★ examples of stateful apps include databases, email, etc
- ensures database reads/writes are synchronized
- very complicated, consider hosting outside of the kubernetes cluster