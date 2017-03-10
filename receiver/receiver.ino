#include <nRF24L01.h>
#include <RF24.h>
#include <RF24_config.h>

#include <SPI.h>
int msg[2];
RF24 radio(9,10);
const uint64_t pipe = 0xE8E8F0F0E1LL;
int LED1 = 2;

void setup(void){
 Serial.begin(9600);
 radio.begin();
 radio.openReadingPipe(1,pipe);
 radio.startListening();
 pinMode(LED1, OUTPUT);
}
void loop(void){
 if (radio.available()){
   bool done = false;    
   while (!done){
     done = radio.read(msg, 10);      
     Serial.println(msg[0]);
     if (msg[0] == 2){
       delay(1000);
       //Serial.println(msg[1]);
       Serial.println(msg[2]);
       digitalWrite(LED1, HIGH);
     }
     else {
       digitalWrite(LED1, LOW);
     }
     delay(1);
   }
 }
 else{Serial.println("No radio available");}
}
