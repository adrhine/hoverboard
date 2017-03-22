//#include <nRF24L01.h>
//#include <RF24_config.h>
#include <RF24.h>
#include <Servo.h>
#include "controller.cpp"

RF24 radio(9,10);
const uint64_t pipe = 0xE8E8F0F0E1LL;
//int LED1 = 2;
controller cntrl = {0,0};
Servo thrustESC;
Servo fuelESC;
Servo directionalServo;

void setup(void){
 Serial.begin(9600);
 radio.begin();
 radio.openReadingPipe(1,pipe);
 radio.startListening();
 thrustESC.attach(4);
 fuelESC.attach(3);
 directionalServo.attach(2);
 //pinMode(LED1, OUTPUT);
}
void loop(void){
 if (radio.available()){
     radio.read(&cntrl, sizeof(cntrl));
     int fuelingSpeed = cntrl.potMtr/4;
     fuelESC.write(fuelingSpeed);
     int rudderPos = ((cntrl.thmbStick*.059) + 50);
     directionalServo.write(rudderPos);
     delay(100);
   }
 else{
  Serial.println("No radio available");
 }
}
