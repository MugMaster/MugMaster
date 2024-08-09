/*
  Made by: Teddy.M
  Since: 5/5/2024
  Discription: Same code as CC but adaped for CA
*/


byte anode1 = 3;  // set to high for diget 1
byte anode2 = 2;  // set to high for diget 2

byte anodePins[] = {
  anode1, anode2
};

byte pinA = 0;
byte pinB = 1;
byte pinC = 5;
byte pinD = 8;
byte pinE = 7;
byte pinF = 4;
byte pinG = 9;
byte pinDP = 6;

byte zero[] = { pinA, pinB, pinC, pinD, pinE, pinF };
byte one[] = { pinB, pinC };
byte two[] = { pinD, pinE, pinG, pinB, pinA };
byte three[] = { pinA, pinB, pinG, pinC, pinD };
byte four[] = { pinF, pinG, pinB, pinC };
byte five[] = { pinA, pinF, pinG, pinC, pinD };
byte six[] = { pinA, pinF, pinG, pinE, pinD, pinC };
byte seven[] = { pinB, pinC, pinA };
byte eight[] = { pinA, pinB, pinC, pinD, pinE, pinF, pinG };
byte nine[] = { pinA, pinB, pinC, pinD, pinF, pinG };

byte number = 2;

bool updateNeeded = false;

/*
    __A__
   |     |
   F     B
   |__G__|
   |     |
   E     C
   |__D__|
*/

void setup() {
  Serial.begin(9600);
  setPinModes();
  digitalWrite(anodePins[0], LOW);
  digitalWrite(anodePins[1], LOW);
}

void setPinModes() {
  pinMode(pinA, OUTPUT);
  pinMode(pinB, OUTPUT);
  pinMode(pinC, OUTPUT);
  pinMode(pinD, OUTPUT);
  pinMode(pinE, OUTPUT);
  pinMode(pinF, OUTPUT);
  pinMode(pinG, OUTPUT);
  pinMode(pinDP, OUTPUT);
  pinMode(anode1, OUTPUT);
  pinMode(anode2, OUTPUT);

  Serial.println("Set pin modes");
}

void loop() {
  diplayDigetOne();
  diplayDigetTwo();
}

void diplayDigetOne() {
  digitalWrite(anode1, HIGH);
  digitalWrite(anode2, LOW);
  byte numberToShow = (number / 10) % 10;
  clear();
  showNumber(numberToShow);
  delay(2);
}

void diplayDigetTwo() {
  digitalWrite(anode2, HIGH);
  digitalWrite(anode1, LOW);
  byte numberToShow = (number / 1) % 10;
  clear();
  showNumber(numberToShow);
  delay(2);
}

void clear() {
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, HIGH);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, HIGH);
  digitalWrite(pinDP, HIGH);
}

void showNumber(byte numberToShow) {
  if (numberToShow == 0) {
    for (int i = 0; i < sizeof(zero); i++) {
      digitalWrite(zero[i], LOW);
    }
  } else if (numberToShow == 1) {
    for (int i = 0; i < sizeof(one); i++) {
      digitalWrite(one[i], LOW);
    }
  } else if (numberToShow == 2) {
    for (int i = 0; i < sizeof(two); i++) {
      digitalWrite(two[i], LOW);
    }
  } else if (numberToShow == 3) {
    for (int i = 0; i < sizeof(three); i++) {
      digitalWrite(three[i], LOW);
    }
  } else if (numberToShow == 4) {
    for (int i = 0; i < sizeof(four); i++) {
      digitalWrite(four[i], LOW);
    }
  } else if (numberToShow == 5) {
    for (int i = 0; i < sizeof(five); i++) {
      digitalWrite(five[i], LOW);
    }
  } else if (numberToShow == 6) {
    for (int i = 0; i < sizeof(six); i++) {
      digitalWrite(six[i], LOW);
    }
  } else if (numberToShow == 7) {
    for (int i = 0; i < sizeof(seven); i++) {
      digitalWrite(seven[i], LOW);
    }
  } else if (numberToShow == 8) {
    for (int i = 0; i < sizeof(eight); i++) {
      digitalWrite(eight[i], LOW);
    }
  } else if (numberToShow == 9) {
    for (int i = 0; i < sizeof(nine); i++) {
      digitalWrite(nine[i], LOW);
    }
  }
}
