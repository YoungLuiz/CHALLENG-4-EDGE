#include <ArduinoJson.h>

int trigPin = 10;
int echoPin = 9;

int buzzer = 8;
int ledVermelho = 7;
int ledVerde = 6;

int duration;
int Distancia;

bool menuAtivo = false;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(buzzer, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledVerde, OUTPUT);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  Distancia = (duration * 0.0343) / 2;

  Serial.print("Distancia: ");
  Serial.print(Distancia);
  Serial.println(" cm");

  StaticJsonDocument<100> json;
  json["distancia"] = Distancia;
  json["menu"] = (Distancia > 15) ? "desbloqueado" : "bloqueado";
  serializeJson(json, Serial);
  Serial.println();

  if (Distancia < 15) {
    if (!menuAtivo) {
      Serial.println("ABRIR_MENU");

      digitalWrite(ledVerde, HIGH);
      digitalWrite(ledVermelho, LOW);

    
      tone(buzzer, 261);
      delay(200);
      noTone(buzzer);

      tone(buzzer, 293);
      delay(200);
      noTone(buzzer);

      tone(buzzer, 329);
      delay(200);
      noTone(buzzer);

      tone(buzzer, 349);
      delay(200);
      noTone(buzzer);

      tone(buzzer, 392);
      delay(200);
      noTone(buzzer);

      delay(2000);
      menuAtivo = true;
    }
  } else {
    if (menuAtivo) {
      Serial.println("MENU_BLOQUEADO");

      digitalWrite(ledVerde, LOW);
      digitalWrite(ledVermelho, HIGH);

      menuAtivo = false;
    }
  }

  delay(100);
}
