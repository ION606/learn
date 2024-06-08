# Docker Compose
allows running of multiple containers/volumes


## Creating
create a `docker-compose.yaml` file in the root dir of the project


## Running
use `docker-compose up`


## Sections

### Version
a version number (i.e. `version: '3'`)

### services
this is the section containing the different things you want to run
for example, if you want to runa web app, and then sql db you would use:
```dockerfile
services:
    web:
        build: .
        ports:
            - "3000:3000"
    db:
        image: "mysql"
        environment:
            # env vars here
            ROOT_PASS: password
        volumes:
            -db-data:/foo

volumes:
    -db-data:/foo
```

