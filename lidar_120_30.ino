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
int accuracy_gor=5;
int accuracy_vert=5;
void setup()
{
  Serial.begin(115200);
  Serial1.begin(1000000, SERIAL_8N1, S_RXD, S_TXD);
  servo.pSerial = &Serial1;
  servo.WritePos(1,200,0,2000);
  servo.WritePos(2,340,0,2000);
  delay(1000);
 
}

void loop()
{
  int read_pos1=-1, read_pos2=-1;
  int servo_speed1=100;



for(servo_pos2=347 ; servo_pos2<=633; servo_pos2+=accuracy_vert){
      servo.WritePos(2,servo_pos2,0,2000);
      read_pos2=servo.ReadPos(2);
      
      for(servo_pos1=203; servo_pos1<=777; servo_pos1+=accuracy_gor){
        servo.WritePos(1, servo_pos1, 0, servo_speed1);
        delay(65);
        read_pos1=servo.ReadPos(1);
        Serial.print(read_pos1);
        Serial.print(",");
        Serial.println(read_pos2);
      }
      servo_pos2+=accuracy_vert;
      servo.WritePos(2,servo_pos2,0,2000);
      read_pos2=servo.ReadPos(2);
      for(servo_pos1=777; servo_pos1>=203; servo_pos1-=accuracy_gor){
        servo.WritePos(1, servo_pos1, 0, servo_speed1);
        delay(65);
        read_pos1=servo.ReadPos(1);
        Serial.print(read_pos1);
        Serial.print(",");
        Serial.println(read_pos2);
      }
    }
    //delay(1000);
    /*
    servo.WritePos(1,20,0,2000);
    servo.WritePos(2,20,0,2000);
  
    for(servo_pos1=servo.ReadPos(1) ; servo_pos1<=885; servo_pos1+=accuracy){
      servo.WritePos(1,servo_pos1,0,300);
      servo_pos1=servo.ReadPos(1);
      
      while(servo_pos2<=870){
        servo.WritePos(2, 880, 0, 300);
        servo_pos2=servo.ReadPos(2);
        Serial.print(servo_pos1);
        Serial.print(",");
        Serial.println(servo_pos2);
      }
      while(servo_pos2>=15){
        servo.WritePos(2,20,0,300);
        servo_pos2=servo.ReadPos(2);
        Serial.print(servo_pos1);
        Serial.print(",");
        Serial.println(servo_pos2);
      }
    servo.WritePos(1,20,0,2000);
    servo.WritePos(2,20,0,2000);
    */
    }
    /*
// программная позиция
int read_pos1=-1, read_pos2=-1;

for(servo_pos1=20 ; servo_pos1<=880; servo_pos1+=accuracy){
      servo.WritePos(1,servo_pos1,0,300);
      read_pos1=servo.ReadPos(1);
      
      while(servo_pos2<=885){
        servo.WritePos(2, 880, 0, 300);
        read_pos2=servo.ReadPos(2);
        Serial.print(read_pos1);
        Serial.print(",");
        Serial.println(read_pos2);
      }
      servo_pos1+=accuracy;
      servo.WritePos(1,servo_pos1,0,300);
      read_pos1=servo.ReadPos(1);
      while(servo_pos2>=15){
        servo.WritePos(2,20,0,300);
        servo_pos2=servo.ReadPos(2);
        Serial.print(servo_pos1);
        Serial.print(",");
        Serial.println(servo_pos2);
      }
    }
// два фора
*/
/*
int read_pos1=-1, read_pos2=-1;

for(servo_pos1=20 ; servo_pos1<=880; servo_pos1+=accuracy){
      servo.WritePos(1,servo_pos1,0,300);
      read_pos1=servo.ReadPos(1);
      
      for(servo_pos2=20; servo_pos2<=880; servo_pos2+=accuracy){
        servo.WritePos(2, servo_pos2, 0, 300);
        read_pos2=servo.ReadPos(2);
        Serial.print(read_pos1);
        Serial.print(",");
        Serial.println(read_pos2);
      }
      servo_pos1+=accuracy;
      servo.WritePos(1,servo_pos1,0,300);
      read_pos1=servo.ReadPos(1);
      for(servo_pos2=880; servo_pos2>=20; servo_pos2-=accuracy){
        servo.WritePos(2, servo_pos2, 0, 300);
        read_pos2=servo.ReadPos(2);
        Serial.print(read_pos1);
        Serial.print(",");
        Serial.println(read_pos2);
      }
    }

*/

    /*
    while(servo_pos1<=700){
      servo.WritePosEx(1,20+5*i, 300, 5);
      servo_pos1=servo.ReadPos(1);
      Serial.println(servo_pos1);
      while(servo_pos2<=700){
        //Servo(ID1) moves at max speed=1500, moves to position=20.
        servo.WritePosEx(2, 880, 300, 5);
        servo_pos2=servo.ReadPos(2);
        Serial.println(servo_pos2);
        servo.WritePosEx(2, 20, 2000, 5);
        delay(10000);

      }
      i++;
     
    }
   // delay(1000);
  
    while(servo_pos1>=2){
      servo.WritePosEx(1, 880-5*j, 300, 5);
      servo_pos1=servo.ReadPos(1);
      Serial.println(servo_pos1);
      while(servo_pos2>=2){
        //Servo(ID1) moves at max speed=1500, moves to position=1000.
        servo.WritePosEx(2, 20, 300, 5);
        servo_pos2=servo.ReadPos(2);
        Serial.println(servo_pos2);
        servo.WritePosEx(2, 880, 2000, 5);
        delay(10000);
      }
      j++;

    }
    */
  