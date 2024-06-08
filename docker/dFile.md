# Keywords

## FROM (module)
* gives instructions about the base platform to use (node, fedora, etc)
- `FROM node:20`


## WORKDIR (path)
* like when you `cd` into a directory
* makes sure any commands executed will be in this directory
- `WORKDIR /app`


## COPY (src) (dest)
* copies files from `src` to `dest`
* I THINK it's like a symbolic link? Maybe?
- `COPY package*.json ./`

*Note: you can get docker to ignore files by creating a `.dockerignore` file*


## RUN (commands)
* like running a command in the terminal!
* `RUN npm install`


## ENV ((varName=varVal) (varName2=varVal2) ...)
* sets env vars (like doing it from the command line)
- `ENV PORT=3000`


## EXPOSE (PORT)
* this will expose a port to the network
- `EXPOSE 3000`


## CMD (args[])
* only ONE per dockerfile
* will tell the container how to run the application
* same as nodejs `spawn` args
- `CMD ["npm", "start"]`


# Notes
every step/instruction in docker is it's own layer
- docker attempts to cache layers if nothing is changes
- this means we want to install dependancies first so they aren't re-installed every time (i.e. are cached)