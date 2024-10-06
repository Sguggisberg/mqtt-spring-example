package ch.guggisberg.stefan.microservice.mqttexample;

import lombok.AllArgsConstructor;
import org.eclipse.paho.client.mqttv3.MqttClient;
import org.eclipse.paho.client.mqttv3.MqttException;
import org.eclipse.paho.client.mqttv3.persist.MemoryPersistence;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RestController;

import java.nio.charset.StandardCharsets;

@RestController
@AllArgsConstructor
public class MqttTestController {

    @GetMapping
    public String test() throws MqttException {
        MqttClient mqttClient = new MqttClient(
                "tcp://localhost:1883",
                MqttClient.generateClientId(),
                new MemoryPersistence());
        mqttClient.connect();
        mqttClient.publish(
                "example-topic", "Java Publisher say hello to Arduino".getBytes(StandardCharsets.UTF_8),
                0, false
        );
        return "ok";
    }
}
