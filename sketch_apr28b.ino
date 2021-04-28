#include <SoftwareSerial.h>
SoftwareSerial BTSerial(2, 3);

int Apin=A0;
int value_pre, value_cur; //이전 값과 현재 값을 저장하는 변수

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  BTSerial.begin(9600);
  value_pre=analogRead(Apin); //가변저항의 초기값을 저장
  sendData(value_pre);
}

void loop() {
  // put your main code here, to run repeatedly:
  value_cur=analogRead(Apin); //가변저항 값 저장
  if(value_cur!=value_pre){ //가변저항 값이 변화될 경우에만 전송
    value_pre=value_cur;
    sendData(value_cur);
    Serial.println(String("가변저항 값=")+value_cur);
    
  }
}

void sendData(int value){
  //안드로이드로 데이터 전달
  String message=String(value)+'\n';
  BTSerial.print(message);
}
