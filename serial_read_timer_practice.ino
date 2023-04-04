int led = 10;

unsigned long inputTime = 0;
unsigned long inputDelay = 0;
unsigned long inputDelay2 = 0;
int trigger = 0;

int timeout = 500;

void setup() {
  pinMode(led, OUTPUT);
  Serial.begin(9600);
  Serial.setTimeout(timeout);     // Serial의 기본 통신 타임아웃 변경. default는 1000
}

void loop() {
  if (Serial.available() > 0) {
    inputDelay = Serial.parseInt();   // Serial로부터 Integer 입력 받음.
    // inputTime = millis();
    trigger = 1;
  }                                   // Serial 입력 완료. timeout만큼 작동 됨.

  if (trigger == 1) {                 // trigger가 없으면 inputTime이 계속 올라감. 멈추게 해준다.
    if (inputDelay != 0) {            // inputDelay가 2번 들어오므로(1개는 내가 입력한 숫자 & 1개는 엔터)
      inputDelay2 = inputDelay;       // inputDelay를 저장해주자.
    }
    inputTime = millis();
    trigger = 0;
    Serial.println((String) "Start Time : " + millis());
  }
  if (millis() - inputTime + timeout < inputDelay2) {         // Serial은 timeout이 끝나야 동작하므로 조건문에 timeout 시간도 넣어주자.
    if(millis()%50==0){
      Serial.println((String) "Now : " + millis());
    }
    digitalWrite(led, HIGH);
  } else if (millis() - inputTime + timeout == inputDelay2) {
    Serial.println((String) "Stop Time : " + millis());
  } else if (millis() - inputTime + timeout > inputDelay2) {
    digitalWrite(led, LOW);
  }
  // if((millis()%1000) == 0){
  //   Serial.println((String)"millis()   : "+millis());
  //   Serial.println((String)"inputTime  : "+inputTime);
  //   Serial.println((String)"inputDelay : "+inputDelay);
  // }
}
