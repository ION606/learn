build_and_run:
	sudo docker build -t ion606/img .
	sudo docker run ion606/img -p 5000:3000

build_and_run_with_mem:
	sudo docker build -t ion606/img .
	sudo docker volume create shared_mem
	sudo docker run -p 5000:3000 --mount source=shared_mem,target=/shredmem ion606/img

compose:
	docker compose up

stopall:
	docker stop $(docker ps -a -q)