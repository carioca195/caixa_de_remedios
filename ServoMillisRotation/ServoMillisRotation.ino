#include <Servo.h>

#define LED 12
#define SERVO 7
#define PIEZO 10

unsigned long currentTime;
unsigned long previousTime = 0;
Servo servo;



void setup() {
  Serial.begin(9600);
  
  pinMode(LED, OUTPUT);
  servo.attach(SERVO);
  pinMode(10,OUTPUT);

  servo.write(0); //Calibrando o Servo na posição 0 graus
}


void loop() {
  currentTime = millis();
  if(currentTime - previousTime > 10000){  // para 4 horas: 14,400,000
    previousTime = currentTime;
    Serial.print("Dispensando...   ");
    dispenser();
    som();
    Serial.println("Feito!");
  }
}


// ========= Dispenser =========

void dispenser() {
  servo.write(180);
  digitalWrite(LED, HIGH);
  delay(2000);
  servo.write(0);
  digitalWrite(LED, LOW);
}

// ========= Som ===============
void som() {
  tone(10,262,150); //DO
  delay(200);
  tone(10,330,200); //MI
  delay(150);
  tone(10,349,200); //FA
}
