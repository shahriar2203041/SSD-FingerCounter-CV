// Final Arduino Code - Matches the wiring map:
// g=4, f=6, a=9, b=10, e=5, d=3, c=12

char input;

void setup() {
  Serial.begin(9600);

  // Setting up your pins exactly as you specified
  pinMode(4, OUTPUT);   // g
  pinMode(6, OUTPUT);   // f
  pinMode(9, OUTPUT);   // a
  pinMode(10, OUTPUT);  // b
  pinMode(5, OUTPUT);   // e
  pinMode(3, OUTPUT);   // d
  pinMode(12, OUTPUT);  // c
}

void loop() {
  if (Serial.available() > 0) {
    input = Serial.read();

    if (input >= '0' && input <= '9') {
      clearDisplay();
      displayDigit(input);
    }
  }
}

void displayDigit(char digit) {
  switch (digit) {
    case '1': show1(); break;
    case '2': show2(); break;
    case '3': show3(); break;
    case '4': show4(); break;
    case '5': show5(); break;
    case '6': show6(); break;
    case '7': show7(); break;
    case '8': show8(); break;
    case '9': show9(); break;
    default: clearDisplay(); break;
  }
}

void clearDisplay() {
  digitalWrite(4, LOW); digitalWrite(6, LOW); digitalWrite(9, LOW);
  digitalWrite(10, LOW); digitalWrite(5, LOW); digitalWrite(3, LOW);
  digitalWrite(12, LOW);
}

// --- Functions to Show Each Number (Corrected for Your Wiring) ---
void show1() { digitalWrite(10, HIGH); digitalWrite(12, HIGH); }
void show2() { digitalWrite(9, HIGH); digitalWrite(10, HIGH); digitalWrite(4, HIGH); digitalWrite(5, HIGH); digitalWrite(3, HIGH); }
void show3() { digitalWrite(9, HIGH); digitalWrite(10, HIGH); digitalWrite(4, HIGH); digitalWrite(12, HIGH); digitalWrite(3, HIGH); }
void show4() { digitalWrite(6, HIGH); digitalWrite(4, HIGH); digitalWrite(10, HIGH); digitalWrite(12, HIGH); }
void show5() { digitalWrite(9, HIGH); digitalWrite(6, HIGH); digitalWrite(4, HIGH); digitalWrite(12, HIGH); digitalWrite(3, HIGH); }
void show6() { digitalWrite(9, HIGH); digitalWrite(6, HIGH); digitalWrite(4, HIGH); digitalWrite(5, HIGH); digitalWrite(12, HIGH); digitalWrite(3, HIGH); }
void show7() { digitalWrite(9, HIGH); digitalWrite(10, HIGH); digitalWrite(12, HIGH); }
void show8() { digitalWrite(9, HIGH); digitalWrite(10, HIGH); digitalWrite(12, HIGH); digitalWrite(3, HIGH); digitalWrite(5, HIGH); digitalWrite(6, HIGH); digitalWrite(4, HIGH); }
void show9() { digitalWrite(9, HIGH); digitalWrite(10, HIGH); digitalWrite(4, HIGH); digitalWrite(6, HIGH); digitalWrite(12, HIGH); digitalWrite(3, HIGH); }










part 2

// FINAL ARDUINO CODE - YOUR FORMAT, YOUR WIRING
// This code is based on your map: g=4, f=6, a=9, b=10, e=5, d=3, c=12

char input;

void setup() {
  Serial.begin(9600);

  // Setting up your pins exactly as you specified
  pinMode(4, OUTPUT);   // g
  pinMode(6, OUTPUT);   // f
  pinMode(9, OUTPUT);   // a
  pinMode(10, OUTPUT);  // b
  pinMode(5, OUTPUT);   // e
  pinMode(3, OUTPUT);   // d
  pinMode(12, OUTPUT);  // c
}

void loop() {
  if (Serial.available() > 0) {
    input = Serial.read();

    // Clear and display if it's a number from 0-9
    if (input >= '0' && input <= '9') {
      clearDisplay();
      displayDigit(input);
    }
  }
}

// Calls the correct function for each number
void displayDigit(char digit) {
  switch (digit) {
    case '1': show1(); break;
    case '2': show2(); break;
    case '3': show3(); break;
    case '4': show4(); break;
    case '5': show5(); break;
    case '6': show6(); break;
    case '7': show7(); break;
    case '8': show8(); break;
    case '9': show9(); break;
    default: clearDisplay(); break; // If '0' or anything else, display is blank
  }
}

// Turns all segments off
void clearDisplay() {
  digitalWrite(4, LOW);  // g
  digitalWrite(6, LOW);  // f
  digitalWrite(9, LOW);  // a
  digitalWrite(10, LOW); // b
  digitalWrite(5, LOW);  // e
  digitalWrite(3, LOW);  // d
  digitalWrite(12, LOW); // c
}


// ------ FUNCTIONS TO SHOW EACH NUMBER (100% Correct for Your Wiring) ------

void show1() { // Segments: b, c
  digitalWrite(10, HIGH); // b
  digitalWrite(12, HIGH); // c
}

void show2() { // Segments: a, b, g, e, d
  digitalWrite(9, HIGH);  // a
  digitalWrite(10, HIGH); // b
  digitalWrite(4, HIGH);  // g
  digitalWrite(5, HIGH);  // e
  digitalWrite(3, HIGH);  // d
}

void show3() { // Segments: a, b, g, c, d
  digitalWrite(9, HIGH);  // a
  digitalWrite(10, HIGH); // b
  digitalWrite(4, HIGH);  // g
  digitalWrite(12, HIGH); // c
  digitalWrite(3, HIGH);  // d
}

void show4() { // Segments: f, g, b, c
  digitalWrite(6, HIGH);  // f
  digitalWrite(4, HIGH);  // g
  digitalWrite(10, HIGH); // b
  digitalWrite(12, HIGH); // c
}

void show5() { // Segments: a, f, g, c, d
  digitalWrite(9, HIGH);  // a
  digitalWrite(6, HIGH);  // f
  digitalWrite(4, HIGH);  // g
  digitalWrite(12, HIGH); // c
  digitalWrite(3, HIGH);  // d
}

void show6() { // Segments: a, f, g, e, c, d
  digitalWrite(9, HIGH);  // a
  digitalWrite(6, HIGH);  // f
  digitalWrite(4, HIGH);  // g
  digitalWrite(5, HIGH);  // e
  digitalWrite(12, HIGH); // c
  digitalWrite(3, HIGH);  // d
}

void show7() { // Segments: a, b, c
  digitalWrite(9, HIGH);  // a
  digitalWrite(10, HIGH); // b
  digitalWrite(12, HIGH); // c
}

void show8() { // Segments: a, b, c, d, e, f, g (All pins HIGH)
  digitalWrite(9, HIGH);  // a
  digitalWrite(10, HIGH); // b
  digitalWrite(12, HIGH); // c
  digitalWrite(3, HIGH);  // d
  digitalWrite(5, HIGH);  // e
  digitalWrite(6, HIGH);  // f
  digitalWrite(4, HIGH);  // g
}

void show9() { // Segments: a, b, g, f, c, d
  digitalWrite(9, HIGH);  // a
  digitalWrite(10, HIGH); // b
  digitalWrite(4, HIGH);  // g
  digitalWrite(6, HIGH);  // f
  digitalWrite(12, HIGH); // c
  digitalWrite(3, HIGH);  // d
}


