#include <WiFi.h>
#include <PubSubClient.h>

// Wifi
const char* ssid = "setName";
const char* password = "setPassword";

// MQTT Broker
const char* mqtt_broker = "192.168.254.101";
const char* topic = "example-topic";
const int mqtt_port = 1883;

WiFiClient espClient;
PubSubClient client(espClient);

void initWiFi() {
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi ..");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print('.');
    delay(1000);
  }
  Serial.println(WiFi.localIP());
}

void initMqtt() {
  client.setServer(mqtt_broker, mqtt_port);
  client.setCallback(callback);
}

//Verbindung mit dem Broker herstellen
void mqttConnect() {
  Serial.print("Verbindung zum MQTT_Server");
  client.setServer(mqtt_broker, mqtt_port);
  while (!client.connected()) {
    String client_id = "esp32-client-";
    client_id += String(WiFi.macAddress());
    Serial.printf("The client %s connects to the public MQTT broker\n", client_id.c_str());
    if (client.connect(client_id.c_str())) {
      Serial.println("Public EMQX MQTT broker connected");
    } else {
      Serial.print("failed with state ");
      Serial.print(client.state());
      delay(2000);
    }
  }
}

void subscribe() {
  Serial.print("Subscrib to topic: ");
  client.subscribe(topic);
  delay(1000);
}

void send() {
  Serial.print("Send message!");
  client.publish(topic, "Hi, I'm ESP32");
  delay(5000);
}

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived in topic: ");
  Serial.println(topic);
  Serial.print("Message:");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();
  Serial.println("-----------------------");
}

void setup() {
  Serial.begin(115200);
  initWiFi();
  initMqtt();
  Serial.print("RRSI: ");
  Serial.println(WiFi.RSSI());
  if (!client.connected()) {
    mqttConnect();
  }
  subscribe();
}


void loop() {
 // send();
  client.loop();
}
