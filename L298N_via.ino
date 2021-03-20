#define LeftPin1 2
#define LeftPin2 3
#define RightPin1 4
#define RightPin2 5
#define LeftSpeed 6
#define RightSpeed 9

boolean flag;
byte data;

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
}

void loop() {
  if (Serial.available() > 0) {
    data = Serial.read();
  }
  switch (data) {
    case 0: Stop(); break;
    case 1: Right(); break;
    case 2: Backword(); break;
    case 3: Left(); break;
    case 4: Forword(); break;
  }
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
