// 1. LED를 배열을 활용해서 깜빡이기

// int LED[] = { 10, 11, 12 };

// void setup() {
//   for (int i = 0; i <= 2; i++) {
//     pinMode(LED[i], OUTPUT);
//   }
// }

// void loop() {
//   for (int i = 0; i <= 2; i++) {
//     digitalWrite(LED[i], HIGH);
//   }
//   delay(1000);
//   for (int i = 0; i <= 2; i++) {
//     digitalWrite(LED[i], LOW);
//   }
//   delay(1000);
// }

// 2. 버튼을 누르면 작동하게 하기

int LED[] = { 10, 11, 12 };
int buttonPin = 7;

void setup() {
  for (int i = 0; i <= 2; i++) {
    pinMode(LED[i], OUTPUT);
  }
  pinMode(buttonPin, INPUT);
}

void loop() {
  int reading = digitalRead(buttonPin);

  if (reading == HIGH) {
    for (int i = 0; i <= 2; i++) {
      digitalWrite(LED[i], HIGH);
      delay(500);
    }
    delay(500);
    for (int i = 2; i >= 0; i--) {
      digitalWrite(LED[i], LOW);
      delay(500);
    }
    delay(500);
  }
}