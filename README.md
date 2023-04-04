# 04_04

## 1. DevBoard

![Image1](/YoneheeDev.png)

|Pin number|Name|Function|
|---|:---:|---|
|A0|가변저항|아날로그 입력|
|6|Servo|서보 모터|
|7|Button1|버튼 기능|
|8|Button2|버튼 기능|
|9|Piezo|소리|
|10|LED1|발광|
|11|LED2|발광|
|12|LED3|발광|

### LED 검증
* Basics -> Blink 예제

### Button 검증
* Digital -> Button 예제

### Piezo 검증
* Digital -> toneMelody 예제

### 가변저항 검증
* Analog -> AnalogInput 예제

<hr/>

## 2. Serial.read()

시리얼과 통신하는 함수.

```
int incomingByte = 0; // for incoming serial data

void setup() {
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
}

void loop() {
  // send data only when you receive data:
  if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.read();

    // say what you got:
    Serial.print("I received: ");
    Serial.println(incomingByte, DEC);
  }
}
```

이런 식으로 작동한다. (책의 142p LED 켜고 끄기도 참조할 것)

이 때, 내가 만약 숫자1을 입력한다면 1을 바로 받는 것이 아니라 1에 대응하는 아스키 코드 값인 49를 받음.

1에 대응하도록 작동하는 함수를 구현하고 싶다면

1) '1'을 사용하기
```
if(incomingByte == '1'){
      digitalWrite(led, HIGH);
      delay(500);
      digitalWrite(led, LOW);
      delay(500);
}
```
2) Serial.read()-'0' 을 사용해서 아스키 코드로 계산하기
3) Serial.parseInt() 함수 사용하기

총 3가지 방법이 있다.
