#include <Wire.h>
#include <Adafruit_MotorShield.h>
//#include "utility/Adafruit_PWMServoDriver.h"

// Create the motor shield object with the default I2C address
Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
// Or, create it with a different I2C address (say for stacking)
// Adafruit_MotorShield AFMS = Adafruit_MotorShield(0x61); 

// Select which 'port' M1, M2, M3 or M4. In this case, M1
Adafruit_DCMotor *myMotor = AFMS.getMotor(1);
// You can also make another motor on port M2
Adafruit_DCMotor *myOtherMotor = AFMS.getMotor(2);

void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Adafruit Motorshield v2 - DC Motor test!");

  AFMS.begin();  // create with the default frequency 1.6KHz
  //AFMS.begin(1000);  // OR with a different frequency, say 1KHz
  
  // Set the speed to start, from 0 (off) to 255 (max speed)
  myMotor->setSpeed(25);
  myOtherMotor->setSpeed(180);
  myMotor->run(FORWARD);
  myOtherMotor->run(FORWARD);
  // turn on motor
  myMotor->run(RELEASE);
  myOtherMotor->run(RELEASE);
}

void loop() {
  uint8_t j;
  //unit8_t j;
  
  Serial.print("tick");

  myMotor->run(FORWARD);
  myOtherMotor->run(FORWARD);
  for (j=0; j<190; j++) {
    myMotor->setSpeed(j);
    //myOtherMotor->setSpeed(i);
    delay(100);
  }
  /*for (j=255; j!=0; j--) {
    myMotor->setSpeed(j);
    myOtherMotor->setSpeed(j);
    delay(100);
  }
  */
  myOtherMotor->run(FORWARD);
  for (j=0; j<105; j++) {
    myOtherMotor->setSpeed(j);
    //myOtherMotor->setSpeed(j);
    delay(10);
  }
  for (j=105; j!=0; j--) {
    myOtherMotor->setSpeed(j);
    //myOtherMotor->setSpeed(i);
    delay(10);
    
  }
  
  Serial.println("tock");

  myMotor->run(BACKWARD);
  myOtherMotor->run(BACKWARD);
  for (j=0; j<255; j++) {
    myMotor->setSpeed(j);
    myOtherMotor->setSpeed(j);
    delay(10);
  }
  for (j=255; j!=0; j--) {
    myMotor->setSpeed(j);
    myOtherMotor->setSpeed(j);
    delay(10);
  }
  
  Serial.println("tech");
  myMotor->run(RELEASE);
  myOtherMotor->run(RELEASE);
  delay(1000);
  
  while(0);
}
