/*
  Made by: Teddy.M
  Since: 5/5/2024
  Discription: Used to check pin letters on common cathode display
*/


byte cathode1 = 2;  // set to LOW for diget 1
byte cathode2 = 3;  // set to LOW for diget 2

byte cathodePins[] = {
  cathode1, cathode2
};

byte pinA = 0;
byte pinB = 1;
byte pinC = 5;
byte pinD = 8;
byte pinE = 7;
byte pinF = 4;
byte pinG = 9;
byte pinDP = 6;

byte pins[] = { pinA, pinB, pinC, pinD, pinE, pinF, pinG };
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
  digitalWrite(cathodePins[0], HIGH;
  digitalWrite(cathodePins[1], HIGH;
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
  digitalWrite(cathodePins[0], LOW);
  digitalWrite(cathodePins[1], LOW);
  for (int i = 0; i < sizeof(pins); i++) {
      digitalWrite(pins[i], HIGH;
  }
}
















