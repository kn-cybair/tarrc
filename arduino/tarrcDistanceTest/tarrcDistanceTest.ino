/*
  MIT License 2019
  ---
  TARRC Robot
  Program purpose: Distance sensor test
  ---
  @author: Krzysztof Stezala
  ---
  Provided by CybAiR Science Club at 
  Institute of Control, Robotics and Information Engineering of
  Poznan University of Technology  
*/

#define BAUDRATE 9600
#define TRIG_PIN 8
#define ECHO_PIN 9
#define LED_RED 13

long signalDuration = 0;
int objectDistance = 0;

void setup(){
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
    pinMode(LED_RED,OUTPUT);
    Serial.begin(BAUDRATE);
}

void loop(){
    objectDistance = calculate_distance();
    if(objectDistance<2000){
        Serial.println(objectDistance);
        digitalWrite(LED_RED,LOW);
    }else{
        digitalWrite(LED_RED,HIGH);
    }
    delay(50);
}

int calculate_distance(){
    digitalWrite(TRIG_PIN,LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN,HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN,LOW);
    signalDuration = pulseIn(ECHO_PIN,HIGH);
    int distance = signalDuration/58;
    return distance;
}
