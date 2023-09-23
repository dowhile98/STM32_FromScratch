#include <Arduino.h>
#include <WiFi.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>

char ssid[] = "RQUINOB";
char pass[] = "R#29qbCivil";


EventGroupHandle_t networkFlag;

WiFiClient client;
PubSubClient mqtt(client);

typedef enum{
  NETWORK_DISCONNED = 1,
  NETWORK_DATA       = 1<<1,
  NETWORK_CONNECTED = 1<<2
}NetworkFlag_t;


void NetworkTask(void *params){

  Serial.printf("ESP32 CONNECTANDO A:%s\r\n", ssid);
  WiFi.mode(WIFI_MODE_STA);
  WiFi.begin(ssid, pass);
  while(WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    vTaskDelay(pdMS_TO_TICKS(300));
  }
  Serial.print("conexion exitosa\r\n");
  Serial.println(WiFi.localIP());

  for(;;){
    if(WiFi.isConnected() != true){
      //reconnect
      WiFi.reconnect();
      xEventGroupSetBits(networkFlag, NETWORK_DISCONNED);
    }else{
      xEventGroupSetBits(networkFlag, NETWORK_CONNECTED);
    }
    ///mqtt.loop();
    delay(40);
  }
}

void setup() {
  Serial.begin(115200);
  portBASE_TYPE STATUS;
  STATUS =  xTaskCreatePinnedToCore(NetworkTask, "WiFi", 4000, NULL, 5, NULL, ARDUINO_RUNNING_CORE);
  configASSERT(STATUS == pdPASS);

  networkFlag = xEventGroupCreate();
}

void loop() {
  EventBits_t flag  = xEventGroupGetBits(networkFlag);
  // put your main code here, to run repeatedly:
  if(flag & NETWORK_CONNECTED){

  }else if(flag & NETWORK_DISCONNED){
    xEventGroupWaitBits(networkFlag, NETWORK_CONNECTED, pdFALSE, pdTRUE, portMAX_DELAY);



  }
  else if(flag & NETWORK_DATA){

  }
}

