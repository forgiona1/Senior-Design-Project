


// Front-Right Wheel (1)

#define RPWM1 9 // define pin 9 for RPWM pin (output)
#define R_EN1 53 // define pin 53for R_EN pin (input)
#define R_IS1 52 // define pin 52for R_IS pin (output)
#define LPWM1 10 // define pin 10for LPWM pin (output)
#define L_EN1 45 // define pin 7 for L_EN pin (input)
#define L_IS1 44 // define pin 8 for L_IS pin (output)
 
// Back-Right Wheel (2)

#define RPWM2 11// define pin 3 for RPWM pin (output)
#define R_EN2 35 // define pin 2 for R_EN pin (input)
#define R_IS2 34 // define pin 5 for R_IS pin (output)
#define LPWM2 12// define pin 6 for LPWM pin (output)
#define L_EN2 23 // define pin 7 for L_EN pin (input)
#define L_IS2 22 // define pin 8 for L_IS pin (output)

// Back-Left Wheel (3)

#define RPWM3 5 // define pin 3 for RPWM pin (output)
#define R_EN3 51 // define pin 2 for R_EN pin (input)
#define R_IS3 50 // define pin 5 for R_IS pin (output)
#define LPWM3 6 // define pin 6 for LPWM pin (output)
#define L_EN3 41 // define pin 7 for L_EN pin (input)
#define L_IS3 40 // define pin 8 for L_IS pin (output)



// Front-Left Wheel (4)

#define RPWM4 7  // define pin 7 for RPWM pin (output)
#define R_EN4 31 // define pin 31for R_EN pin (input)
#define R_IS4 30 // define pin 30for R_IS pin (output)
#define LPWM4 8 // define pin 8 for LPWM pin (output)
#define L_EN4 26 // define pin 26for L_EN pin (input)
#define L_IS4 25 // define pin 25for L_IS pin (output)




#define CW 1 //do not change
#define CCW 0 //do not change
#define debug 1 //change to 0 to hide serial monitor debugging information or set to 1 to view

#include <RobojaxBTS7960.h>

RobojaxBTS7960 motor1(R_EN1,RPWM1,R_IS1, L_EN1,LPWM1,L_IS1,debug);
RobojaxBTS7960 motor2(R_EN2,RPWM2,R_IS2, L_EN2,LPWM2,L_IS2,debug);
RobojaxBTS7960 motor3(R_EN3,RPWM3,R_IS3, L_EN3,LPWM3,L_IS3,debug);
RobojaxBTS7960 motor4(R_EN4,RPWM4,R_IS4, L_EN4,LPWM4,L_IS4,debug);

void setup() {
  // BTS7960 Motor Control Code by Robojax.com 20190622
  Serial.begin(9600);// setup Serial Monitor to display information

   motor1.begin();
   motor2.begin();
   motor3.begin();
   motor4.begin();

   
    // BTS7960 Motor Control Code by Robojax.com 20190622 
}

void loop() {
   // BTS7960 Motor Control Code by Robojax.com 20190622 
      //watch video for details: https://youtu.be/PUL5DZ9TA2o
     
    motor1.rotate(100,CW);// run motor with 100% speed in CW direction
    Serial.print("RPWM1: ");
    Serial.println(RPWM1);
    
    motor2.rotate(100,CW);// run motor with 100% speed in CW direction
    motor3.rotate(100,CW);// run motor with 100% speed in CW direction
    motor4.rotate(100,CW);// run motor with 100% speed in CW direction
  
    delay(5000);//run for 5 seconds
    
    motor1.stop();// stop the motor
    motor2.stop();// stop the motor
    motor3.stop();// stop the motor
    motor4.stop();// stop the motor
    
    delay(3000);// stop for 3 seconds
    
    motor1.rotate(25,CCW);// run motor at 100% speed in CCW direction
    motor2.rotate(25,CCW);// run motor at 100% speed in CCW direction
    motor3.rotate(25,CCW);// run motor at 100% speed in CCW direction
    motor4.rotate(25,CCW);// run motor at 100% speed in CCW direction

    /*
    
    delay(5000);// run for 5 seconds
    motor.stop();// stop the motor
    delay(3000);  // stop for 3 seconds
  // slowly speed up the motor from 0 to 100% speed
    for(int i=0; i<=100; i++){ 
        motor.rotate(i,CCW);
        delay(50);
    } 
  
   // slow down the motor from 100% to 0 with 
    for(int i=100; i>0; i--){ 
        motor.rotate(i,CCW);
        delay(50);
    } 
  
   //watch video for details: https://youtu.be/PUL5DZ9TA2o  
    motor.stop();// stop motor
    delay(3000); // stop for 3 seconds        
 // BTS7960 Motor Control Code by Robojax.com 20190622 */ 
}// loop ends
