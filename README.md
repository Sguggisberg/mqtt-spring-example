﻿# mqtt-spring-example

## run docker-compose

docker-compose -p mqtt-broker up -d

source: <https://github.com/sukesh-ak/setup-mosquitto-with-docker>

## Send message via Spring Restservice

Start Arduino (as Subscriber)
Start Docker compose "docker-compose -p mqtt-broker up -d" (as Broker)
Start Sprong (as Publisher)

Call http://localhost:8080/ (Get)
