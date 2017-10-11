#include <AFMotor.h>
AF_DCMotor motor1(2);

void setup() {
  // put your setup code here, to run once:
motor1.setSpeed(255);
}

void loop() {
  // put your main code here, to run repeatedly:

//motor1.setSpeed(255);

motor1.run(FORWARD);

delay(5000);      

motor1.setSpeed(255);


delay(5000);      


motor1.setSpeed(0);


delay(5000);      



}
