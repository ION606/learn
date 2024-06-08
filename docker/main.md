# Parts of Docker
## Docker File
a blueprint for building a docker image

## Docker Image
a template for running docker containers. These are IMMUTABLE!!!

## Docker Container
a running process (like a node app)

## Docker Volume
a "folder" on the host machine that can have data which multiple containers can access


## Docker Compose
runs multiple docker containers

*Note: docker can basically "freeze" the dev env so that any other devs will be able to exactly reproduce it*


# Commands
## docker ps
gives you a list of all images on your system


## docker volume create (name)


## docker build \[flags] (directory)
builds the docker image

### Options
* -t [NAMETAG] - gives the docker conainer a name (i.e. ION606/myimage:1.0)


## docker run (imageId || tagName)

### Options
* -p (LOCALPORT:CONTAINERPORT) - enables port forewarding between the docker container and the system

* --mount (source=volumeName) (target=mountingName)


## docker stop \[imageId]
*Note: to stop all just use `docker stop $(docker ps -a -q)`*