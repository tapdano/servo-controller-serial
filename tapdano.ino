#include <Servo.h>

Servo servo;

void setup() {
  Serial.begin(9600);
  servo.attach(9);
  servo.write(45);
  Serial.println("STARTED");
}

void loop() {
  if (Serial.available() > 0) {
    String command = Serial.readStringUntil('\n');
    command.trim();
    if (command == "MOVE") {
      moveServo(45);
      delay(3000);
      moveServo(-45);
      Serial.println("OK");
    }
    if (command == "MOVE1") {
      moveServo(45);
      Serial.println("OK");
    }
    if (command == "MOVE2") {
      moveServo(-45);
      Serial.println("OK");
    }
  }
}

void moveServo(int speed) {
  int pos = servo.read();
  if (speed < 0) {
    for (int i = pos; i >= pos + speed; i--) {
      servo.write(i);
      delay(20);
    }
  } else {
    for (int i = pos; i <= pos + speed; i++) {
      servo.write(i);
      delay(20);
    }
  }
}
