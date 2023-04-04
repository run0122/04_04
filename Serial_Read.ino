// 1. 기본 Serial.Read()  -> Serial.Monitor에서 전송하면 적용됨.

// int incomingByte = 0; // for incoming serial data

// void setup() {
//   Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
// }

// void loop() {
//   // send data only when you receive data:
//   if (Serial.available() > 0) {
//     // read the incoming byte:
//     incomingByte = Serial.read();

//     // say what you got:
//     Serial.print("I received: ");
//     Serial.println(incomingByte, DEC);
//   }
// }

// 2. 문자 1을 보내면 LED 1번, 문자2를 보내면 LED 2번 Blink (int incomingByte)

// int incomingByte = 0;  // for incoming serial data

// int led = 10;

// void setup() {
//   Serial.begin(9600);  // opens serial port, sets data rate to 9600 bps
//   pinMode(led, OUTPUT);
// }

// void loop() {
//   // send data only when you receive data:
//   if (Serial.available() > 0) {
//     // read the incoming byte:
//     incomingByte = Serial.read() - '0';

//     for (int i = 0; i < incomingByte; i++) {
//       digitalWrite(led, HIGH);
//       delay(500);
//       digitalWrite(led, LOW);
//       delay(500);
//     }
//     // say what you got:
//     Serial.print("I received: ");
//     Serial.println(incomingByte, DEC);
//   }
// }

// 3. 문자 1을 보내면 LED 1번, 문자2를 보내면 LED 2번 Blink (다른 방법들)

int led = 10;

void setup() {
  Serial.begin(9600);  // opens serial port, sets data rate to 9600 bps
  pinMode(led, OUTPUT);
}

void loop() {
  // send data only when you receive data:
  if (Serial.available() > 0) {
    // read the incoming byte:
    int incomingByte = Serial.parseInt();

    // if(incomingByte == '1'){
    //   digitalWrite(led, HIGH);
    //   delay(500);
    //   digitalWrite(led, LOW);
    //   delay(500);
    // }

    for (int i = 0; i < incomingByte; i++) {
      digitalWrite(led, HIGH);
      delay(500);
      digitalWrite(led, LOW);
      delay(500);
    }
    // say what you got:
    Serial.print("I received: ");
    Serial.println(incomingByte);
  }
}