# mqtt-spring-example



### docker commands

## run docker-compose

docker-compose -p mqtt5 up -d

source: <https://github.com/sukesh-ak/setup-mosquitto-with-docker>

## Others

## Passwort setzen

1. docker exec -it 38b76f7e073e sh
2. mosquitto_passwd -c /mosquitto/config/pwfile user1
 delete user command format:
mosquitto_passwd -D /mosquitto/config/pwfile <user-name-to-delete>
3. docker restart <container-id>
4. 




