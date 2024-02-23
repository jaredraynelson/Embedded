#include <Servo.h>

#define xPin A0
#define yPin A1
#define potPin A2

#define jStick 2
#define clampServoPin 9
#define xServoPin 3
#define yServoPin 10
#define zServoPin 6

int xPos = 90;
int yPos = 90;
int zPos = 90;
int handPos = 0;

Servo xServo;
Servo yServo;
Servo zServo;
Servo clampServo;

void setup() {
  pinMode(jStick, INPUT_PULLUP);
  pinMode(xServoPin, OUTPUT);
  pinMode(yServoPin, OUTPUT);
  pinMode(zServoPin, OUTPUT);
  pinMode(clampServoPin, OUTPUT);
  xServo.attach(xServoPin);
  yServo.attach(yServoPin);
  zServo.attach(zServoPin);
  clampServo.attach(clampServoPin);
  Serial.begin(9600);
}

void loop() {
    int xValue = analogRead(xPin);
    int yValue = analogRead(yPin);
    int zValue = analogRead(potPin);
    int pushVal = digitalRead(jStick);

    // Map joystick values to servo angle (adjust the ranges as needed)
    int xMove = getMove(xValue, 'x');
    int yMove = getMove(yValue, 'y');
    int zMove = getMove(zValue, 'z');

    moveServo(xPos, xMove, 'x', 100, 40);
    moveServo(yPos, yMove, 'y', 100, 40);
    moveServo(zPos, zMove, 'z', 180, 0);
    clamp(pushVal);

}

void clamp (int pushVal) {
    if (pushVal == 0) {
    while (handPos < 180) {
      handPos+=2;
      clampServo.write(handPos);
      delay(10);
      Serial.println(handPos);
    }
    handPos = 180;
  }
  else {
    while (handPos > 0) {
      handPos -= 2;
      clampServo.write(handPos);
      delay(10);
      Serial.println(handPos);
    }
    handPos = 0;
  }
}

int getMove(int val, char dir) {
  int mappedMax = 3;
  int mappedMin = -3;
  int servoMin = 0;
  int servoMax = 1023;
  if (dir == 'y') {
    mappedMin *=- 1;
    mappedMax *=- 1;
  }
    int sA2 = map(val, servoMin, servoMax, mappedMin, mappedMax);
    int sA3 = map(val, servoMin, servoMax, mappedMin, mappedMax);
    int sA1 = map(val, servoMin, servoMax, mappedMin, mappedMax);
    int servoMove = (sA1 + sA2 + sA3)/3;
    return servoMove;
}

void moveServo(int pos, int move, char dir, int max, int min) {
      if (move > 1 || move < -1) {
      pos += move-1;
      Serial.print(dir);
      Serial.print(" :");
        if (pos > max) {
        pos = max;
      }
      else if (pos < min) {
        pos = min;
      }
      Serial.println(pos);
      if (dir == 'x') { 
        xPos = pos;
        xServo.write(pos); 
        }
      else if (dir == 'z') {
        zPos = pos;
        zServo.write(pos);
      }
      else { 
        yPos = pos;
        yServo.write(pos);
       }
      delay(40);
    }
}
