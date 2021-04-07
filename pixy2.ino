#include <Pixy2.h>

const int LeftPin1 = 2;
const int LeftPin2 = 3;
const int RightPin1 = 4;
const int RightPin2 = 5;
const int LeftSpeed = 6;
const int RightSpeed = 9;

boolean flag;
byte data;
Pixy2 pixy;

void setup() {
  pinMode(LeftPin1, OUTPUT);
  pinMode(LeftPin2, OUTPUT);
  pinMode(RightPin1, OUTPUT);
  pinMode(RightPin2, OUTPUT);
  pinMode(LeftSpeed, OUTPUT);
  pinMode(RightSpeed, OUTPUT);
  analogWrite(LeftSpeed, 255);
  analogWrite(RightSpeed, 255);
  Serial.begin(9600);
  pixy.init();
}

void loop() {
  if (Serial.available() > 0) {
    data = Serial.read();
    if (data == 5) {
      flag = !flag;
    }
  }
  if (!flag)mobileControl();
  else objectFollowing();
}

void mobileControl() {
  switch (data) {
    case 0: Stop(); break;
    case 1: Right(); break;
    case 2: Backword(); break;
    case 3: Left(); break;
    case 4: Forword(); break;
  }
}

void objectFollowing() {
  pixy.ccc.getBlocks();
  int x = 150, width = 80;
  if (pixy.ccc.numBlocks) {
    x = pixy.ccc.blocks[0].m_x;
    width = pixy.ccc.blocks[0].m_width;
  }
  if (x < 110)Left();
  else if (x > 230)Right();
  else if (width < 60)Forword();
  else if (width > 100)Backword();
  else Stop();
}

void Forword() {
  digitalWrite(LeftPin1, HIGH);
  digitalWrite(LeftPin2, LOW);
  digitalWrite(RightPin1, LOW);
  digitalWrite(RightPin2, HIGH);
}

void Backword() {
  digitalWrite(LeftPin1, LOW);
  digitalWrite(LeftPin2, HIGH);
  digitalWrite(RightPin1, HIGH);
  digitalWrite(RightPin2, LOW);
}

void Left() {
  digitalWrite(LeftPin1, LOW);
  digitalWrite(LeftPin2, HIGH);
  digitalWrite(RightPin1, LOW);
  digitalWrite(RightPin2, HIGH);
}

void Right() {
  digitalWrite(LeftPin1, HIGH);
  digitalWrite(LeftPin2, LOW);
  digitalWrite(RightPin1, HIGH);
  digitalWrite(RightPin2, LOW);
}

void Stop() {
  digitalWrite(LeftPin1, LOW);
  digitalWrite(LeftPin2, LOW);
  digitalWrite(RightPin1, LOW);
  digitalWrite(RightPin2, LOW);
}
