#include "NDelayFunc.h"
#include <Servo.h>

// ★★★ Variables ★★★

// LED Blink
const int blink_LED = 10;
unsigned int on_off = 0;

// LED Fade In & Fade OUT
const int fading_LED = 11;
unsigned int t_high = 0;
unsigned int t_high2 = 255;

int trigger = 0;

// Servo Function Change & push button by millis()

bool funcState = false;

const int buttonPin = 7;
int buttonState;
int lastButtonState = LOW;

unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 1000;

// Servo Sweep
Servo myservo;

int pos = 0;
int servo_direction = 1;

// Knob
int potpin = A0;
int val;

// ★★★ Functions ★★★

// LED Blink
void blink() {
  on_off++;
  if (on_off > 1) on_off = 0;
  digitalWrite(blink_LED, on_off);
}

// LED Fade In & Fade OUT
void fading() {
  t_high++;
  if (t_high > 255) {
    t_high = 0;
    trigger = 1;
  }
  analogWrite(fading_LED, t_high);
}

void fadeout() {
  t_high2--;
  if (t_high2 == 0) {
    t_high2 = 255;
    trigger = 0;
  }
  analogWrite(fading_LED, t_high2);
}

// Sweep
void sweep() {
  if (servo_direction == 1) {
    pos++;
    myservo.write(pos);
    if (pos == 180) {
      servo_direction = -1;
    }
  }
  if (servo_direction == -1) {
    pos--;
    myservo.write(pos);
    if (pos == 0) {
      servo_direction = 1;
    }
  }
}

// Knob

void knob() {
  val = analogRead(potpin);
  val = map(val, 0, 1023, 0, 180);
  myservo.write(val);
  pos = val;
}

// ★★★ Functions Arrangement ★★★

NDelayFunc nDelayBlink(500, blink);  // LED Blink
NDelayFunc nDelayFading(4, fading);  // LED Fade In & Fade OUT
NDelayFunc nDelayFadeout(4, fadeout);
NDelayFunc nDelaySweep(10, sweep);  // Servo
NDelayFunc nDelayKnob(4, knob);

void setup() {
  pinMode(blink_LED, OUTPUT);
  myservo.attach(6);  // Servo pin 세팅
  pinMode(buttonPin, INPUT);
}

void loop() {
  nDelayBlink.run();
  
  if (trigger == 0) {
    nDelayFading.run();
  }
  if (trigger == 1) {
    nDelayFadeout.run();
  }

  // push button by millis()
  int reading = digitalRead(buttonPin);

  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != buttonState) {
      buttonState = reading;

      if (buttonState == HIGH) {
        funcState = !funcState;
      }
    }
  }

  if (funcState == false) {
    nDelaySweep.run();
  }
  if (funcState == true) {
    nDelayKnob.run();
  }

  lastButtonState = reading;
}