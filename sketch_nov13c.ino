#define S_RXD 18
#define S_TXD 19

#include <SCServo.h>

int servo_pos1, servo_pos2;

SCSCL servo;
void setup()
{
  Serial.begin(115200);
  Serial1.begin(1000000, SERIAL_8N1, S_RXD, S_TXD);
  servo.pSerial = &Serial1;

 servo.WritePosEx(2, 353, 2000, 60);
 delay(1000);//Servo(ID1) moves at max speed=1500, moves to position=20.
}

void loop()
{

   servo_pos1=servo.ReadPos(1);
    servo_pos2=servo.ReadPos(2);
    while(1){
      //servo.WritePosEx(1, 783, 2000, 60);//Servo(ID1) moves at max speed=1500, moves to position=20.
      servo.WritePos(2, 638, 0, 300);
      servo_pos2=servo.ReadPos(2);
      Serial.println(servo_pos2);
      if(servo_pos2==633){break;}
      
    }
   // delay(1000);
    while(1){
      //servo.WritePosEx(1, 197, 2000, 60);//Servo(ID1) moves at max speed=1500, moves to position=1000.
      servo.WritePos(2, 341, 0, 300);
      servo_pos2=servo.ReadPos(2);
      Serial.println(servo_pos2);
    if(servo_pos2==347){break;}

    }
  
}
      