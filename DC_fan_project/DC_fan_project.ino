//Controlling the speed of a DC fan using a transistor and pushbutton, using an LED as a visual indicator of the fan speed.
int button1 = 6;
int button1Val;
int button2Val;
float LEDbrightness = 0;
float fanspeed = 0;
int button2 = 5;
int LEDpin = 9;
int fan = 3;
// int initial1Val=1;
// int initial2Val=1;
int add=10;
int dt = 250;

void setup() {
  // put your setup code here, to run once:
pinMode(button1, INPUT);
pinMode(button2, INPUT);
pinMode(LEDpin, OUTPUT);
Serial.begin(9600);
pinMode(fan, OUTPUT);
digitalWrite(fan, LOW);
digitalWrite(LEDpin, LOW);
}

void loop() {
 button1Val = digitalRead(button1);
 button2Val = digitalRead(button2);
 Serial.print("button1Val is ");
 Serial.print(button1Val);
 Serial.print(", button2Val is ");
 Serial.println(button2Val);

 if(button1Val==0){
  LEDbrightness = LEDbrightness+add;
  if(LEDbrightness>255){LEDbrightness=255;}
  fanspeed = fanspeed+add;
  if(fanspeed>250){fanspeed=255;}
 } 
//  initial1Val=button1Val;

 if(button2Val==0){
  LEDbrightness = LEDbrightness-add;
  if(LEDbrightness<0){LEDbrightness=0;}
  fanspeed = fanspeed-add;
  if(fanspeed<0){fanspeed=0;}
 } 
//  initial2Val=button2Val;
  analogWrite(fan, fanspeed);
  analogWrite(LEDpin, LEDbrightness);
  delay (dt);
}
