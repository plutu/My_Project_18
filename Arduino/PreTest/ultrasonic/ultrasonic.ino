const int trigPin = A2; //Is trigpin what sends out the signal?
const int echoPin = A1;//and echopin what receives it?
/*const int in1 = 9;
const int in2 = 8;
const int in3 = 4;
const int in4 = 3;*/


void setup() 
{
  Serial.begin(9600);
  Serial.println("Begin");
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  /*pinMode (in1, OUTPUT);
  pinMode (in2, OUTPUT);
  pinMode (in3, OUTPUT);
  pinMode (in4, OUTPUT);*/
}
long duration, distance;

void loop()
{     
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);  
  duration = pulseIn(echoPin, HIGH);
  distance = duration/58.2;
  Serial.println(distance);

 /* if(distance<15)
    {
      Serial.println(distance);
      digitalWrite(in1, LOW); //so we're turning on the motors if it's on?
      digitalWrite(in2, HIGH); 
      digitalWrite(in3, HIGH); 
      digitalWrite(in4, LOW);
    }
  else
    {
      digitalWrite(in1, HIGH); 
      digitalWrite(in2, LOW); 
      digitalWrite(in3, HIGH); 
      digitalWrite(in4, LOW);

      Serial.println(distance);

      
    }  */
  delay(50);
}
