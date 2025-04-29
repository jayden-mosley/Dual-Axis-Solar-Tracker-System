#include <Servo.h>

Servo servoX;  // horizontal axis
Servo servoY;  // vertical axis

int LDR_TL = A0; // Top Left
int LDR_TR = A1; // Top Right
int LDR_BL = A2; // Bottom Left
int LDR_BR = A3; // Bottom Right

int posX = 90;
int posY = 90;

void setup() {
  servoX.attach(9);
  servoY.attach(10);

  servoX.write(posX);
  servoY.write(posY);

  Serial.begin(9600);
}

void loop() {
  int val_TL = analogRead(LDR_TL);
  int val_TR = analogRead(LDR_TR);
  int val_BL = analogRead(LDR_BL);
  int val_BR = analogRead(LDR_BR);

  int avgTop = (val_TL + val_TR) / 2;
  int avgBottom = (val_BL + val_BR) / 2;
  int avgLeft = (val_TL + val_BL) / 2;
  int avgRight = (val_TR + val_BR) / 2;

  int threshold = 50;

  if (abs(avgLeft - avgRight) > threshold) {
    if (avgLeft > avgRight) {
      posX += 1;
    } else {
      posX -= 1;
    }
  }

  if (abs(avgTop - avgBottom) > threshold) {
    if (avgTop > avgBottom) {
      posY += 1;
    } else {
      posY -= 1;
    }
  }

  posX = constrain(posX, 0, 180);
  posY = constrain(posY, 0, 180);

  servoX.write(posX);
  servoY.write(posY);

  delay(100);
