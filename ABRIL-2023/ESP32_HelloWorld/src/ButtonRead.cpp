#include <Arduino.h>

#define BUTTON 0


void ButtonReadTask(void *params){

    for(;;){
        if(digitalRead(BUTTON) == 0){
            while(digitalRead(BUTTON) == 0);
            Serial.println("button clicked\r\n");
        }
        delay(10);
    }

    vTaskDelete(NULL);
}