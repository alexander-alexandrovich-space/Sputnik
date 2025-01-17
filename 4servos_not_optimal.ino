/*
The normal write example passed the test in SCS15, 
and if testing other models of SCS series servos
please change the appropriate position, speed and delay parameters.
*/

// the UART used to control servos.
// GPIO 18 - S_RXD, GPIO 19 - S_TXD, as default.
#define S_RXD 18
#define S_TXD 19

#include <SCServo.h>



SCSCL servo;
int servo_pos1=-1;
int servo_pos2=-2;
int servo_pos3 =-3;
int accuracy_gor=5;
int accuracy_vert=5;
void setup()
{
  Serial.begin(115200);
  Serial1.begin(1000000, SERIAL_8N1, S_RXD, S_TXD);
  servo.pSerial = &Serial1;
  servo.WritePos(1,200,0,2000);
  servo.WritePos(2,340,0,2000);
  servo.WritePos(3, 0, 0, 1000);
  servo.WritePos(4, 0, 0, 1000);  
  delay(1000);
 
}

void loop()
{
  int read_pos1=-1, read_pos2=-1;
  int servo_speed1=75;

  for(servo_pos2=347 ; servo_pos2<=633; servo_pos2+=accuracy_vert){
      servo.WritePos(2,servo_pos2,0,2000);
      read_pos2=servo.ReadPos(2);
      
      

      while(servo_pos1<769){
        servo.WritePos(1, 777, 0, servo_speed1);
        while(servo_pos3<=985){
          servo.WritePos(3, 1000, 0, 1000);
          servo.WritePos(4, 1000, 0, 1000);
          servo_pos3=servo.ReadPos(3);
          Serial.println(servo_pos3);
        }
        while(servo_pos3>36){
          servo.WritePos(3, 27, 0, 1000);
          servo.WritePos(4, 27, 0, 1000);
          servo_pos3=servo.ReadPos(3);
          Serial.println(servo_pos3);
        }
        servo_pos1=servo.ReadPos(1);
        
        Serial.print(servo_pos1);
        Serial.print(",");
        Serial.print(read_pos2);
        Serial.println(",");
      
        if(servo_pos3==-1){
        servo_pos1=203;
        servo_pos2=347;
        servo_pos3=27;
        servo.WritePos(1,200,0,2000);
        servo.WritePos(2,340,0,2000);
        delay(1000);
        read_pos1=servo.ReadPos(1);
        read_pos2=servo.ReadPos(2);
        }
      }
      servo_pos2+=accuracy_vert;
      servo.WritePos(2,servo_pos2,0,2000);
      servo.WritePos(3, 0, 0, 1000);
      servo.WritePos(4, 0, 0, 1000);
      read_pos2=servo.ReadPos(2);
      while(servo_pos1>215){
        servo.WritePos(1, 203, 0, servo_speed1);
         while(servo_pos3<=985){
          servo.WritePos(3, 1000, 0, 1000);
          servo.WritePos(4, 1000, 0, 1000);
          servo_pos3=servo.ReadPos(3);
          Serial.println(servo_pos3);
        }
        while(servo_pos3>36){
          servo.WritePos(3, 27, 0, 1000);
          servo.WritePos(4, 27, 0, 1000);
          servo_pos3=servo.ReadPos(3);
          Serial.println(servo_pos3);
        }
        servo_pos1=servo.ReadPos(1);
        servo_pos3=servo.ReadPos(3);
        Serial.print(servo_pos1);
        Serial.print(",");
        Serial.print(read_pos2);
        Serial.print(",");
        Serial.println(servo_pos3);
        if(servo_pos3==-1){
        servo_pos1=203;
        servo_pos2=347;
        servo_pos3=27;
        servo.WritePos(1,200,0,2000);
        servo.WritePos(2,340,0,2000);
        delay(1000);
        read_pos1=servo.ReadPos(1);
        read_pos2=servo.ReadPos(2);


        
        }
      }
      
    }
}
 