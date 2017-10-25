#include <StepperAK.h>
#include <AFMotor.h>
#include <Wire.h> //I2C Arduino Library

#define address 0x1E //0011110b, I2C 7bit address of HMC5883

AF_DCMotor motor1(2);//forward/backward
AF_DCMotor motor2(1);//sideways
AF_DCMotor motor3(4);//forward/backward
AF_DCMotor motor4(3);//sideways

//stepper pins
#define pin1  9  //blue     these are the Arduino pins that we use to activate coils 1-4 of the stepper motor
#define pin2  10 //green
#define pin3  13 //yellow
#define pin4  2  //brown

#define delaytime 20   //delay time in ms to control the stepper motor delaytime.
//Our (StepperAK's) tests showed that 8 is about the fastest that can yield reliable operation w/o missing steps
//should I use #define instead of declaring integers here?
int sidewaystime = 2000; //how long does it take to reach the other side? (test this)
int howfarwevecome = 0;
int pausetime = 100; //this is how long we wait in between ultrasonic measurements
int linewidth = 10; //in cm, this is how far we advance per line
int linesdone = 0;
int numberofstepstoopendoor = 100; //need to test this experimentally
int collect_time = 2000; //the time it takes to move forward enough to collect a magnet
int spin_90_time = 920; // time it takes to do a 180 --> again, measure experimentally
int motor_speed = 100; //between 0 and 255
int wheel_speed = 50; //in cm/s, to be experimentally measured if possible?? This will change when we change motor_speed
int linetime = 2000;  // linewidth / wheel_speed;
bool has_mag = false;


const int trigPin = A2; //Is trigpin what sends out the signal?
const int echoPin = A1;//and echopin what receives it?
void setup() {
  //ultrasonic setup
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // initialize the stepper pins as an output:
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(pin4, OUTPUT);

  //SDA: A4, SCL:A5

  //Initialize Serial and I2C communications for magno
  Wire.begin();

  //Put the HMC5883 IC into the correct operating mode
  Wire.beginTransmission(address); //open communication with HMC5883
  Wire.write(0x02); //select mode register
  Wire.write(0x00); //continuous measurement mode
  Wire.endTransmission();
  //delay before starting;
  delay(900);

  //Pre-test --- hold up a piece of paper to block the ultrasonic sensor, then press reset button


  delay(500);
  if (get_distance() < 5) {
    pretest();

  }

}

void loop() {


  linesdone += 1;
  strip(FORWARD);//left first, then right
  strip(BACKWARD); //make sure that we end up on the right hand edge, so that we don't get stuck around the corner.
  if (has_mag = true) {
    backtobase(linesdone);
    dump(); //dump should include spinning, opening door, reversing, closing door, then spinning again
    /*GENIUS: we can make the reverse part of dump exactly linewidth, which will mean that when we go back to the frontlines
      we'll be one line further forward */
    dc_move(motor1, motor3, FORWARD, linesdone * linetime);
  }
  else if (get_distance() > linewidth) {
    dc_move(motor1, motor3, FORWARD, linetime);
  }
  else {
    dc_move(motor1, motor3, BACKWARD, linetime * 2);
  }
}

