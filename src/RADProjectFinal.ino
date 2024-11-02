#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

//Left
int en1 = 6 ;
int in1 = 8;
int in2 = 7;
//Right
int en2=11;
int in3=12;
int in4=13;

//ir inputs
int irLeft = 4;
int irRight = 5 ;

// ultrasonic sensor pins
int trigPin = 2;
int echoPin = 3;

int distance = 9 ; 
bool pickingInProgress = false ;

//servo driver 

#define SERVOMIN 125
#define SERVOMAX 575

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x40);

uint8_t servonum = 0 ;

void setup() {
  Serial.begin(9600);
  pwm.begin();
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(en1,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
  pinMode(en2,OUTPUT);
  analogWrite(en1,125);
  analogWrite(en2,110);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  pinMode(irLeft,INPUT);
  pinMode(irRight,INPUT);
  pwm.setPWMFreq(60);  
  pwm.setPWM(0,0,575);
  pwm.setPWM(1,0,250);
  pwm.setPWM(2,0,125);
  delay(1500);
}

void loop() {
    int irLeftValue = digitalRead(irLeft);
    int irRightValue = digitalRead(irRight);

    distance = getDistance();
    if(distance <=8 && !pickingInProgress){
        stop();
        pickAndPlace();
        pickingInProgress = true ;
    }
    else{
        if( irLeftValue==0  && irRightValue == 0 ){
         forward();
        }
        else if(irLeftValue==0  && irRightValue == 1 ){
          turnRight();
        }
        else if(irLeftValue==1  && irRightValue == 0 ){
          turnLeft();
        }
        else{
          stop();
        }
        pickingInProgress = false ;
    }

    // Serial.print("Left sensor :");
    // Serial.println(irLeftValue);
    // Serial.print("Right Sensor :");
    // Serial.println(irRightValue);
    // Serial.println(getDistance());
  
    
}
void setSpeed(int speed){
  analogWrite(en1,speed);
  analogWrite(en2,speed);
}
void forward(){
    digitalWrite(in2,HIGH);
    digitalWrite(in4,HIGH);    
    digitalWrite(in3,LOW);    
    digitalWrite(in1,LOW);    
}
void stop(){
    digitalWrite(in3,LOW);
    digitalWrite(in1,LOW);
    digitalWrite(in4,LOW);    
    digitalWrite(in2,LOW);
}

void turnLeft(){
    digitalWrite(in2,HIGH);
    digitalWrite(in4,LOW);
    digitalWrite(in3,HIGH);    
    digitalWrite(in1,LOW);
}
void turnRight(){
    digitalWrite(in2,LOW);
    digitalWrite(in4,HIGH);
    digitalWrite(in3,LOW);    
    digitalWrite(in1,HIGH);
}


long getDistance(){
  long duration;
  int distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  return distance;
}


void pickAndPlace(){
  
  for(int i=125;i<=250;i+=5)
  {
    pwm.setPWM(1,0,i);
    delay(35);
  }
  //servo hand
  for(int i=125;i<=300;i+=5)
  {
    pwm.setPWM(2,0,i);
    delay(55);
  }
  //servo right shoulder 
  for(int i = 250; i>=125 ; i-=5)
  {
    pwm.setPWM(1,0,i);
    delay(35);
  }
  //servo bottom
  for(int i = 575; i>=300 ; i-=5)
  {
    pwm.setPWM(0,0,i);
    delay(35);
  }
  //sevo right
  for(int i=125;i<=250;i+=5)
  {
    pwm.setPWM(1,0,i);
    delay(35);
  }
  //servo hand
  for(int i=300;i>=125;i-=5)
  {
    pwm.setPWM(2,0,i);
    delay(55);
  }
  //servo right shoulder
  for(int i = 250; i>=125 ; i-=5)
  {
    pwm.setPWM(1,0,i);
    delay(35);
  }
  //servo bottom
  for(int i=300;i<=575;i+=5)
  {
    pwm.setPWM(0,0,i);
    delay(35);
  }  
}