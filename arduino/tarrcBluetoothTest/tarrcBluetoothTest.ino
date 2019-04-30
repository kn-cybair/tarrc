/*
  MIT License 2019
  ---
  TARRC Robot
  Program purpose: Bluetooth test
  ---
  @author: Krzysztof Stezala
  ---
  Provided by CybAiR Science Club at 
  Institute of Control, Robotics and Information Engineering of
  Poznan University of Technology  
*/

#define TX_PIN 10
#define RX_PIN 11
#define LED_RED 13
#define BAUDRATE 9600

#include <SoftwareSerial.h>

SoftwareSerial bluetooth(TX_PIN,RX_PIN);
char state;

void setup(){
    pinMode(LED_RED,OUTPUT);
    bluetooth.begin(BAUDRATE);
}

void loop(){
    while(bluetooth.available()){
        delay(10);
        state = bluetooth.read();
        if(state=='1'){
            digitalWrite(LED_RED, HIGH);
        }
        else if(state == '0'){
            digitalWrite(LED_RED, LOW);
        }
    }
}



