/**
 * @file MQTT_Task.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-06-01
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <Arduino.h>
#include <WiFi.h>
#include <PubSubClient.h>

const char* ssid = "RQUINOB"; // Aquí debes poner el nombre de tu red wifi
const char* password = "R#29qbCivil"; // Aquí debes poner la contraseña de tu red wifi
//const char* mqtt_server = "broker.hivemq.com"; // Aquí debes poner la dirección de tu servidor MQTT
IPAddress mqtt_server(192,168,1,38);
extern EventGroupHandle_t systemEventHandle;
WiFiClient espClient;
PubSubClient client(espClient);

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    xEventGroupClearBits(systemEventHandle, 1);
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    if (client.connect("arduinoClient")) {
      Serial.println("connected");
      // Once connected, publish an announcement...
      //client.publish("outTopic","hello world");
      // ... and resubscribe
      client.subscribe("ESP32Topic");

      xEventGroupSetBits(systemEventHandle, 1);
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}


void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i=0;i<length;i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();
}


void MQTT_Task(void *params){
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.println("Conectando a wifi...");
    }
    Serial.println("Conexión wifi establecida");
    Serial.print("Dirección IP: ");
    Serial.println(WiFi.localIP());

    client.setCallback(callback);
    client.setServer(mqtt_server, 1883); // El número 1883 es el puerto por defecto para MQTT

    for(;;){
        if (!client.connected()) {
            reconnect();
        }
        client.loop();
        //publicar
        delay(3);
    }
}