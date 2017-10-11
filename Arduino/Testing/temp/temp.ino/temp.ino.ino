//starting Rolls value
int rolls = 0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  while (rolls < 7){
  Serial.print("    How many members of the Rolls family are there?     ");
  Serial.println(rolls);
  rolls += 1;
  }

}
