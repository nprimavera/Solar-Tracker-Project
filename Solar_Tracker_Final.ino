 
#include <Servo.h>                                            // Include the Servo library  
#include <Math.h>                                             // Include the math library (fractions ect.) -- dont need 

Servo Servo1;                                                 // Create a servo object for servo1 & servo2
Servo Servo2;
                                              
int servoPin = 3;                                             // Declare the servo pins 
int servoPin2 = 2; 
int index;                                                    // Angle associated with max value -- servo 1
int index2;                                                   // Angle associated with max value -- servo 2

double sig;                                                   // sig = read from solar panel (volts) -- servo1  
double sigh = 0.0;                                            // Previous max values -- servo1                
double sig2;                                                  // sig2 = read from solar panel (volts) -- servo2
double sigh2 = 0.0;                                           // Previous max values -- servo2


void setup() { 
                                              
    Servo1.attach(servoPin);                                  // We need to attach the servo to the used pin number
    Servo2.attach(servoPin2);
    
    Serial.begin(9600);                                       // Initialize serial communication at 9600 bits per second

  }

void loop(){ 

for (int i = 0; i <= 90; i = i + 10){                         // Initialization; condition; increment
    
  Servo1.write(i);                                            // Telling servo1 to move in increments of i 
  sig = analogRead(A0);                                       // Read the value from the solar panel 
  Serial.println(sig);                                        // Prints the values of sig   
  Serial.println(i);                                          // Prints the values at each increment of i (angle) 
  Serial.println(sigh);                                       // Prints the value of sigh --> max value  
  Serial.println();                                           // space 
  delay(2000);                                                // Stop the program for 2000 milliseconds ~ 2 seconds  
 
  if (sig > sigh) {                                           // updating maximum angle based on voltage received from solar panel  
    
    sigh = sig;
    index = i; 
    
    }

  Serial.println(index);                                      // Prints the values of index --> angle associated with max value
  Serial.println();                                           // space  
  
}
                                         
for (int j = 0; j <= 90; j = j + 10){
    
    Servo2.write(j);                                          // Telling servo2 to move in increments of j 
    sig2 = analogRead(A0);                                    // Read the value from 
    Serial.println(sig2);                                     // Prints the values of sig   
    Serial.println(j);                                        // Prints the values at each increment of i (angle) 
    Serial.println(sigh2);                                    // Prints the value of sigh --> max value  
    Serial.println();                                         // space 
    delay(2000);                                              // Stop the program for 2000 milliseconds ~ 2 seconds  
    
    if(sig2 > sigh2) {                                        // updating maximum angle based on voltage received from solar panel 
      
      sigh2 = sig2;
      index2 = j;
     
      }

    Serial.println(index2);                                   // Prints the values of index --> angle associated with max value
    Serial.println();                                         // space 
    
  }

    Serial.println("The max angle on the x-axis is");         // Explaining what the next line is   
    Serial.println(index);                                    // Print max value from servo1
    Serial.println();                                         // space 
    Serial.println("The max angle on the y-axis is");         // Explaining the next line  
    Serial.print(index2);                                     // Print max value from servo2 
    Serial.println();                                         // space 
    Serial.println();                                         // space 
    
    Servo1.write(index);                                      // Telling servo1 to move to index(max) angle
    Servo2.write(index2);                                     // Telling servo2 to move to index2(max) angle  
    
    delay(30000);                                             // Delay for 30 seconds before the loop runs again 
    
}                                                             // End of void loop 
