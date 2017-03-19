#include  <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"
#include "controller.cpp"

int value = 0;
int msg[3];
RF24 radio(9,10);
const uint64_t pipe = 0xE8E8F0F0E1LL;
controller cntlr = {0, 0};

void setup(void){
 Serial.begin(9600);
 radio.begin();
 radio.openWritingPipe(pipe);
 radio.setRetries(15,15);
 radio.stopListening();
 pinMode(0, INPUT);
}
void loop(void){
  cntlr.thmbStick = analogRead(0);
  cntlr.potMtr = analogRead(1);
  Serial.println(cntlr.thmbStick);
  Serial.println(cntlr.potMtr);
  radio.write(&cntlr, sizeof(cntlr));
}
