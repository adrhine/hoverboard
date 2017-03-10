#include <nRF24L01.h>
#include <RF24.h>
#include <RF24_config.h>

#include <SPI.h>
#include "controller.cpp"

RF24 radio(9,10);
const uint64_t pipe = 0xE8E8F0F0E1LL;
//int LED1 = 2;
controller cntrl = {0,0};

void setup(void){
 Serial.begin(9600);
 radio.begin();
 radio.openReadingPipe(1,pipe);
 radio.startListening();
 //pinMode(LED1, OUTPUT);
}
void loop(void){
 if (radio.available()){
     radio.read(&cntrl, sizeof(cntrl));
     Serial.println(cntrl.potMtr);
     Serial.println(cntrl.thmbStick);
     delay(100);
   }
 else{
  Serial.println("No radio available");
 }
}
