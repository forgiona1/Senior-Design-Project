// This is the INHERITED motor control code. Not currently being used; for reference only

#include <SharpIR.h> // Library for the proximitydistance sensors 
#define IR1 A0 // First proximity distance sensor 
#define model1 1080 


SharpIR mySensor =  SharpIR(IR1, model1); // Initializingfor the first proximity distance sensor 
int distance_cm = 0; //Center proximity distance sensor 


const int potPin=A3; // Analog pin for the potentiometer 



int power=255;
void turnRight(); // Turn right function 
void turnLeft(); // Turn left function 
void forward(); // Move forward function 
void reverse(); // Backup function 
void breaking(); // Breaking function
void stopping(); // Emergency stopping function

// Front right motor controller initialization 
int RIS = 50; 
int REN = 51; 
int RPWM = 5;
int LIS = 40; 
int LEN = 41; 
int LPWM = 6; 

 // Back Right motor controller initialization 
int RIS2 = 30;
int REN2 = 31; 
int RPWM2 = 7;
int LIS2 = 25; 
int LEN2 = 26; 
int LPWM2 = 8; 

// Back Left motor controller initialization
int RIS3 = 52;

int REN3 = 53; 
int RPWM3 = 9;
int LIS3 = 44; 
int LEN3 = 45; 
int LPWM3 = 10; 

// Frobnt Left motor controller initialization 
int RIS4 = 34;
int REN4 = 35; 
int RPWM4 = 11;
int LIS4 = 22; 
int LEN4 = 23; 
int LPWM4 = 12; 

void setup() {
 
  Serial.begin(9600);
// First motor controller 
  pinMode(RIS, OUTPUT); 
  pinMode(REN, OUTPUT); 
  pinMode(RPWM, OUTPUT); 
  pinMode(LIS, OUTPUT);
  pinMode(LEN, OUTPUT); 
  pinMode(LPWM, OUTPUT); 

  // Second motor controller
  pinMode(RIS2, OUTPUT);  
  pinMode(REN2, OUTPUT);
  pinMode(RPWM2, OUTPUT); 
  pinMode(LIS2, OUTPUT);
  pinMode(LEN2, OUTPUT); 
  pinMode(LPWM2, OUTPUT);

  // Third motor controller 
  pinMode(RIS3, OUTPUT);  
  pinMode(REN3, OUTPUT); 
  pinMode(RPWM3, OUTPUT); 
  pinMode(LIS3, OUTPUT); 
  pinMode(LEN3, OUTPUT); 
  pinMode(LPWM3, OUTPUT);

  // Fourth motor controller 
  pinMode(RIS4, OUTPUT); 
  pinMode(REN4, OUTPUT); 
  pinMode(RPWM4, OUTPUT); 
  pinMode(LIS4, OUTPUT); 
  pinMode(LEN4, OUTPUT); 
  pinMode(LPWM4, OUTPUT);

  // Defining the enable and IS pins of each motor controller 
  // First motor controller 
  digitalWrite(RIS, LOW); digitalWrite(LIS, LOW); digitalWrite(REN, HIGH); digitalWrite(LEN, HIGH);

  // Second motor controller
  digitalWrite(RIS2, LOW); digitalWrite(LIS2, LOW); digitalWrite(REN2, HIGH); digitalWrite(LEN2, HIGH);

  // Third motor controller 
  digitalWrite(RIS3, LOW); digitalWrite(LIS3, LOW); digitalWrite(REN3, HIGH); digitalWrite(LEN3, HIGH);

  // Fourth motor controller 
  digitalWrite(RIS4, LOW); digitalWrite(LIS4, LOW); digitalWrite(REN4, HIGH); digitalWrite(LEN4, HIGH);
  delay(1000); 

}

void loop() {
  //power=analogRead(potPin)/4; // Power output basedon the potentiometer. 
  
  distance_cm = mySensor.getDistance();
  Serial.println(distance_cm);
  if(distance_cm <= 45){
   
    reverse();
    breaking(); 
  }
  else{
    forward();
    Serial.println("Forward");
  }
  
  
  
  
  
  
    Serial.println(power);
    forward();
    Serial.println("Forward");
    delay(1000); 
/*
    turnRight();
    Serial.println("Turn Right");
    delay(1000);
/*
    turnLeft();
    Serial.println("Turn Left");
    delay(1000);

    reverse();
    Serial.println("Reverse");
    delay(1000);

    breaking();
    delay(1000); 
 */ 
}

void reverse() { 


// All four wheels will spin the reverse direction. 
analogWrite(RPWM, 0); 
analogWrite(LPWM, 80); 
analogWrite(RPWM2, 0); 
analogWrite(LPWM2, 80); 
analogWrite(RPWM3, 0); 
analogWrite(LPWM3, 80);
analogWrite(RPWM4, 0); 
analogWrite(LPWM4, 80); 
delay(1000); // The robot will back up for 1 second 

}

void turnRight() { 
 // reverse(); // The robot will stop moving forward and will back up for 1 second 
  
  // The robot will turn off two of the motors and keep two motors operating
   
  analogWrite(RPWM, 30);
  analogWrite(LPWM, 0 );
  analogWrite(RPWM2, 40);
  analogWrite(LPWM2, 0);
  analogWrite(RPWM3, 0);
  analogWrite(LPWM3, 30);
  analogWrite(RPWM4, 0);
  analogWrite(LPWM4, 40);
  delay(500); 
  
}

void turnLeft() { 
  reverse(); // The robot will stop moving forward and will back up for 1 second 
 
  // Front and back left motors will spin forward while the right motors will both spin backwards
  // causes robot to spin in place
  
  analogWrite(RPWM, 80);
  analogWrite(LPWM, 0);
  analogWrite(RPWM2, 80);
  analogWrite(LPWM2, 0); 
  analogWrite(RPWM3, 0);
  analogWrite(LPWM3, 80);
  analogWrite(RPWM4, 0);
  analogWrite(LPWM4, 80); 
  delay(1000); 
  
}

void breaking() { 
  
  // All motion will come to a temporary halt. 
  analogWrite(RPWM, 0); 
  analogWrite(LPWM, 0); 
  analogWrite(RPWM2, 0); 
  analogWrite(LPWM2, 0); 
  analogWrite(RPWM3, 0); 
  analogWrite(LPWM3, 0); 
  analogWrite(RPWM4, 0); 
  analogWrite(LPWM4, 0); 
  
  delay(2000); // This temporary halt in motion will last 3 seconds
 
  
} 
void forward() {
    // The robot will always travel forward with all four motors operating at once 
    // The power output for the motors is dependent on a manually adjusted potentiometer. 
    analogWrite(RPWM, 40); 
    analogWrite(LPWM, 0); 
    analogWrite(RPWM2, 30); 
    analogWrite(LPWM2, 0); 
    analogWrite(RPWM3, 30); 
    analogWrite(LPWM3, 0); 
    analogWrite(RPWM4, 40); 
    analogWrite(LPWM4, 0);
}
