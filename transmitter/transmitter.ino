#include  <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"
int msg[2];
RF24 radio(9,10);
const uint64_t pipe = 0xE8E8F0F0E1LL;
void setup(void){
 Serial.begin(9600);
 radio.begin();
 radio.openWritingPipe(pipe);
 pinMode(0, INPUT);
}
void loop(void){
  int numOfInputs = 2;
  int thmbStick = analogRead(0);
  int potMtr = analogRead(1);
  //Serial.println(val);
  msg[0] = numOfInputs;
  //msg[1] = thmbStick;
  msg[1] = potMtr;
  Serial.println(thmbStick);
    Serial.println(potMtr);
  radio.write(msg, 10); // 2 = #/bytes
}
