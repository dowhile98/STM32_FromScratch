#include <Arduino.h>
#include <PubSubClient.h>
#include <WiFi.h>
/*Global variables ----------------------------------------*/
TaskHandle_t ButtonHandle;
extern PubSubClient client;
EventGroupHandle_t systemEventHandle;
/*Function prototype --------------------------------------*/
extern void ButtonReadTask(void *params);

extern void MQTT_Task(void *params);

void setup() {
  char txt[] = "Tarea de lectura de botones creado\r\n";
  BaseType_t status;

  Serial.begin(115200);
  Serial.println("configuraccion correcta\r\n");
  systemEventHandle = xEventGroupCreate();
  //task create
  status = xTaskCreatePinnedToCore(ButtonReadTask,
                                    "BUTTON",
                                    2048,
                                    NULL,
                                    8,
                                    &ButtonHandle,
                                    ARDUINO_RUNNING_CORE);
  configASSERT(status == pdPASS);

  status = xTaskCreatePinnedToCore(MQTT_Task,
                                    "MQTT",
                                    3000,
                                    NULL,
                                    10,
                                    NULL,
                                    ARDUINO_RUNNING_CORE);
  /**
   * dpPASS
   * pdFAIL
   * pdTRUE
   * pdFALSE
   * 
   */
  configASSERT(status == pdPASS);
  
}

void loop() {
  //Serial.println("loop principal...\r\n");
  xEventGroupWaitBits(systemEventHandle, 1, pdFALSE, pdTRUE, portMAX_DELAY);
  client.publish("outTopic", "holaaaaaa!\r\n");
  vTaskDelay(pdMS_TO_TICKS(2000));
}

