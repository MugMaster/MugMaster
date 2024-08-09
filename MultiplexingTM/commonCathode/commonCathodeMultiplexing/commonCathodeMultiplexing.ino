/*
  Made by: Teddy.M
  Since: 5/5/2024
  Discription: For use with multiplexed common cathode seven
  segment displays, to add more digets copy existing common 
  cathode code with as many times as nessisary.
  
  Beginer tip: Every 7 segment display has pins labled
  on their diagrams from A-G and most have DP (decimal point),
  to hook up your ardino to the dislay look up your display model
  and connect output pins accordingly, feel free to change which pin
  controls which segment where it says "byte pin[pinLetterHere] = [outputPinNumber];"
*/


byte cathode1 = 9;  // set to low for diget 1
byte cathode2 = 8;  // set to low for diget 2

byte cathodePins[] = {
  cathode1, cathode2
};

byte pinA = 3;
byte pinB = 2;
byte pinC = 1;
byte pinD = 0;
byte pinE = 5;
byte pinF = 6;
byte pinG = 7;
byte pinDP = 4;

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

byte number = 15;

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
  digitalWrite(cathodePins[0], HIGH);
  digitalWrite(cathodePins[1], HIGH);
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
  pinMode(cathode1, OUTPUT);
  pinMode(cathode2, OUTPUT);

  Serial.println("Set pin modes");
}

void loop() {
  diplayDigetOne();
  diplayDigetTwo();
}

void diplayDigetOne() {
  digitalWrite(cathode1, LOW);
  digitalWrite(cathode2, HIGH);
  byte numberToShow = (number / 10) % 10;
  clear();
  showNumber(numberToShow);
  delay(2);
}

void diplayDigetTwo() {
  digitalWrite(cathode2, LOW);
  digitalWrite(cathode1, HIGH);
  byte numberToShow = (number / 1) % 10;
  clear();
  showNumber(numberToShow);
  delay(2);
}

void clear() {
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, LOW);
  digitalWrite(pinD, LOW);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, LOW);
  digitalWrite(pinG, LOW);
  digitalWrite(pinDP, LOW);
}

void showNumber(byte numberToShow) {
  if (numberToShow == 0) {
    for (int i = 0; i < sizeof(zero); i++) {
      digitalWrite(zero[i], HIGH);
    }
  } else if (numberToShow == 1) {
    for (int i = 0; i < sizeof(one); i++) {
      digitalWrite(one[i], HIGH);
    }
  } else if (numberToShow == 2) {
    for (int i = 0; i < sizeof(two); i++) {
      digitalWrite(two[i], HIGH);
    }
  } else if (numberToShow == 3) {
    for (int i = 0; i < sizeof(three); i++) {
      digitalWrite(three[i], HIGH);
    }
  } else if (numberToShow == 4) {
    for (int i = 0; i < sizeof(four); i++) {
      digitalWrite(four[i], HIGH);
    }
  } else if (numberToShow == 5) {
    for (int i = 0; i < sizeof(five); i++) {
      digitalWrite(five[i], HIGH);
    }
  } else if (numberToShow == 6) {
    for (int i = 0; i < sizeof(six); i++) {
      digitalWrite(six[i], HIGH);
    }
  } else if (numberToShow == 7) {
    for (int i = 0; i < sizeof(seven); i++) {
      digitalWrite(seven[i], HIGH);
    }
  } else if (numberToShow == 8) {
    for (int i = 0; i < sizeof(eight); i++) {
      digitalWrite(eight[i], HIGH);
    }
  } else if (numberToShow == 9) {
    for (int i = 0; i < sizeof(nine); i++) {
      digitalWrite(nine[i], HIGH);
    }
  }
}
