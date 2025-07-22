#include <Arduino.h>
#include <Servo.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

// WiFi Access Point
ESP8266WebServer server(80);
const char *ssid = "Labiryntator 3000";
const char *password = "czterdziescidwa";


#define LED_L D1
#define LED_R D8
#define BUZZER D5
#define STEP_1 D2
#define STEP_2 D3

Servo myservo1;
Servo myservo2;

void buzzer(int toneValue = 500, int repeat = 1)
{
  for(int i = 0; i < repeat; i++)  
  {
    tone(BUZZER, toneValue);
    delay(100);
    noTone(BUZZER);
    delay(500);
  }
}

void moveForward() {
  // Przykład: oba serwa do przodu
  myservo1.write(180);
  myservo2.write(0);
}

void moveBack() {
  myservo1.write(0);
  myservo2.write(180);
}

void turnLeft() {
  myservo1.write(0);
  myservo2.write(0);
}

void turnRight() {
  myservo1.write(180);
  myservo2.write(180);
}

void stopMotors() {
  myservo1.write(90);
  myservo2.write(90);
}

void setup()
{
  Serial.begin(115200);
  delay(2000);
  Serial.println("Start ESP");

  pinMode(LED_L, OUTPUT);
  pinMode(LED_R, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  myservo1.attach(STEP_1);
  myservo2.attach(STEP_2);

  stopMotors();


  WiFi.softAP(ssid, password);
  Serial.println("Access Point uruchomiony!");
  Serial.print("IP AP: ");
  Serial.println(WiFi.softAPIP());

  
  server.on("/forward", HTTP_GET, [](){
    moveForward();
    server.send(200, "text/plain", "Moving forward");
  });

  server.on("/back", HTTP_GET, [](){
    moveBack();
    server.send(200, "text/plain", "Moving back");
  });

  server.on("/left", HTTP_GET, [](){
    turnLeft();
    server.send(200, "text/plain", "Turning left");
  });

  server.on("/right", HTTP_GET, [](){
    turnRight();
    server.send(200, "text/plain", "Turning right");
  });

  server.on("/buzzer", HTTP_GET, [](){
    buzzer(500, 2);
    server.send(200, "text/plain", "Buzzing");
  });

  server.on("/led_l", HTTP_GET, [](){
    digitalWrite(LED_L, !digitalRead(LED_L)); // Przełącz LED_L
    server.send(200, "text/plain", "LED_L toggled");
  });

  server.on("/led_r", HTTP_GET, [](){
    digitalWrite(LED_R, !digitalRead(LED_R)); // Przełącz LED_R
    server.send(200, "text/plain", "LED_R toggled");
  });

  server.onNotFound([](){
    stopMotors();
    server.send(404, "text/plain", "Not Found");
  });

  server.begin();
  Serial.println("Serwer HTTP działa");
}

void loop()
{
  server.handleClient();
}