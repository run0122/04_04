int led[] = { 10, 11, 12 };
int buttonPin = 7;

void setup() {
  for (int i = 0; i <= 2; i++) {
    pinMode(led[i], OUTPUT);
  }
  pinMode(buttonPin, INPUT);
}

void loop() {
  int buttonInput = digitalRead(buttonPin);
  if (buttonInput == HIGH) {
    for (int x = 0; x <= 2; x++) {
      for (int x = 0; x <= 2; x++) {
        digitalWrite(led[x], LOW);
      }
      digitalWrite(led[x], HIGH);
      buttonInput = digitalRead(buttonPin);
      if (buttonInput == LOW) break;

      delay(50);
    }
  }
}
