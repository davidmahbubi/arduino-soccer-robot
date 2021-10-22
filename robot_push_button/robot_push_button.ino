#include <SoftwareSerial.h>

SoftwareSerial bluetooth(2, 3); // RX, TX 

// Menampung nilai dari bluetooth
int bluetoothInput = 0;

// Koneksi Motor Listrik A
int enA = 9;
int in1 = 8;
int in2 = 7;

// Koneksi Motor Listrik B
int enB = 3;
int in3 = 5;
int in4 = 4;

void setup() {

  // Set mode PIN
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  // Matikan semua motor listrik saat robot baru dinyalakan
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

void loop() {

  if (bluetooth.available()) {
    
    bluetoothInput = bluetooth.read();

    switch (bluetoothInput) {
      case 1:
        maju(); break;
      case 2:
        mundur(); break;
      case 3:
        belokKanan(); break;
      case 4:
        belokKiri(); break;
      default:
        berhenti();
    }
  }
}

void maju() {
  analogWrite(enA, 255);
  analogWrite(enB, 255);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void mundur() {
  analogWrite(enA, 255);
  analogWrite(enB, 255);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void belokKanan() {
  analogWrite(enA, 255);
  analogWrite(enB, 0);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

void belokKiri() {
  analogWrite(enA, 0);
  analogWrite(enB, 255);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void berhenti() {
  analogWrite(enA, 0);
  analogWrite(enB, 0);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}
