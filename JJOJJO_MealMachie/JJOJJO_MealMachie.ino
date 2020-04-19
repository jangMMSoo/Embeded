#include <TimeLib.h>
#include <TimeAlarms.h>
#include <Servo.h>    // 서보모터 라이브러리

Servo servo;    // 서보모터 사용을 위한 객체 생성

int motor = 2;  // 서보모터의 핀 
int angle = 90; // 서보모터 초기 각도 값
void setup() {
  servo.attach(motor);  // 서보모터 연결
  Serial.begin(9600);  // 시리얼 모니터 시작
  
  setTime(9,0,0,18,4,20); // set time to Saturday 8:29:00am Jan 1 2011

  // create the alarms, to trigger at specific times
  Alarm.alarmRepeat(8,10,0, goMeal);  // 8:30am every day
  Alarm.alarmRepeat(19,30,0,goMeal);  // 5:45pm every day  setTime(8,29,0,1,1,11); // set time to Saturday 8:29:00am Jan 1 2011

 
}

void loop() {
  Alarm.delay(1000); // wait one second between clock displayAlarm.delay(1000); // wait one second between clock display
}

void goMeal(){
  Serial.println("go meal");
      servo.write(angle);
      for(int i = 0; i < 70; i++){
          servo.write(--angle);   
          delay(10);
      }
      delay(600);
      for(int i = 0; i < 70; i++){
          servo.write(++angle);   
          delay(10);
      }
      angle = 90;
}
