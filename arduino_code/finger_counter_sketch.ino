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



part 3










// YOUR CODE, UPDATED WITH A NON-BLOCKING SERVO FOR 4 SECONDS

#include <Servo.h>  // <-- NEW: Include the library for the servo motor

char input;
Servo myServo;      // <-- NEW: Create a servo object

// --- NEW VARIABLES FOR NON-BLOCKING SERVO TIMING ---
int servoState = 0;             // 0=idle, 1=moving to 90, 2=waiting
unsigned long servoTimer = 0;   // Will store the time when the servo starts waiting
const long ROTATION_TIME = 4000; // <-- NEW: 4 seconds (4000 milliseconds)

void setup() {
  Serial.begin(9600);

  // Your exact pin setup - UNCHANGED
  pinMode(4, OUTPUT);   // g
  pinMode(6, OUTPUT);   // f
  pinMode(9, OUTPUT);   // a
  pinMode(10, OUTPUT);  // b
  pinMode(5, OUTPUT);   // e
  pinMode(3, OUTPUT);   // d
  pinMode(12, OUTPUT);  // c

  // --- NEW SERVO SETUP ---
  myServo.attach(7);    // <-- NEW: Attach the servo to pin 7
  myServo.write(0);     // <-- NEW: Start the servo at 0 degrees
}

void loop() {
  // --- PART 1: Check for new commands from Python (Your code, unchanged) ---
  if (Serial.available() > 0) {
    input = Serial.read();
    if (input >= '0' && input <= '9') {
      clearDisplay();
      displayDigit(input);
    }
  }

  // --- PART 2: Always check the servo state (This runs continuously) ---
  handleServo(); // <-- NEW
}

// Your displayDigit function, with one small change for case '5'
void displayDigit(char digit) {
  switch (digit) {
    case '1': show1(); break;
    case '2': show2(); break;
    case '3': show3(); break;
    case '4': show4(); break;
    
    // --- UPDATED CASE FOR '5' ---
    case '5':
      show5(); // First, show the number 5 on the display
      if (servoState == 0) { // Only start the rotation if the servo is idle
        servoState = 1;      // <-- NEW: Trigger the start of the servo sequence
      }
      break;
      
    case '6': show6(); break;
    case '7': show7(); break;
    case '8': show8(); break;
    case '9': show9(); break;
    default: clearDisplay(); break;
  }
}

// --- NEW NON-BLOCKING FUNCTION TO MANAGE THE SERVO ---
void handleServo() {
  // This function runs thousands of times a second, never blocking the code.
  
  if (servoState == 1) { // State 1: Move to 90 degrees
    myServo.write(360);
    servoTimer = millis(); // Record the current time (start the 4-second timer)
    servoState = 2;      // Move to the next state: "waiting"
  }

  if (servoState == 2 && millis() - servoTimer >= ROTATION_TIME) {
    // State 2: Check if 4 seconds have passed since we started waiting
    myServo.write(0);  // If yes, move the servo back to 0
    servoState = 0;    // Reset to the idle state, ready for the next "5"
  }
}


// ------ YOUR FUNCTIONS BELOW ARE 100% UNCHANGED ------

void clearDisplay() {
  digitalWrite(4, LOW); digitalWrite(6, LOW); digitalWrite(9, LOW);
  digitalWrite(10, LOW); digitalWrite(5, LOW); digitalWrite(3, LOW);
  digitalWrite(12, LOW);
}
void show1() { digitalWrite(10, HIGH); digitalWrite(12, HIGH); }
void show2() { digitalWrite(9, HIGH); digitalWrite(10, HIGH); digitalWrite(4, HIGH); digitalWrite(5, HIGH); digitalWrite(3, HIGH); }
void show3() { digitalWrite(9, HIGH); digitalWrite(10, HIGH); digitalWrite(4, HIGH); digitalWrite(12, HIGH); digitalWrite(3, HIGH); }
void show4() { digitalWrite(6, HIGH); digitalWrite(4, HIGH); digitalWrite(10, HIGH); digitalWrite(12, HIGH); }
void show5() { digitalWrite(9, HIGH); digitalWrite(6, HIGH); digitalWrite(4, HIGH); digitalWrite(12, HIGH); digitalWrite(3, HIGH); }
void show6() { digitalWrite(9, HIGH); digitalWrite(6, HIGH); digitalWrite(4, HIGH); digitalWrite(5, HIGH); digitalWrite(12, HIGH); digitalWrite(3, HIGH); }
void show7() { digitalWrite(9, HIGH); digitalWrite(10, HIGH); digitalWrite(12, HIGH); }
void show8() { digitalWrite(9, HIGH); digitalWrite(10, HIGH); digitalWrite(12, HIGH); digitalWrite(3, HIGH); digitalWrite(5, HIGH); digitalWrite(6, HIGH); digitalWrite(4, HIGH); }
void show9() { digitalWrite(9, HIGH); digitalWrite(10, HIGH); digitalWrite(4, HIGH); digitalWrite(6, HIGH); digitalWrite(12, HIGH); digitalWrite(3, HIGH); }
