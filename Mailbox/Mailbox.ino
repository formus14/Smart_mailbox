#include <SimpleTimer.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define trigPin D5
#define echoPin D4

SimpleTimer timer;
WidgetLCD lcd(V1);

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "72967a142b504f7e9b3aa83ecad33bd7";

void Read_Values(){
  digitalWrite(trigPin, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(1000); 
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin, LOW);
  
  long duration, distance;
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  //Serial.println(distance);
  if (distance < 4) {  // This is where the LED On/Off happens
  Serial.println("You have one Mail");
  lcd.clear(); //Use it to clear the LCD Widget
  lcd.print(0, 0, "New post in"); // use: (position X: 0-15, position Y: 0-1, "Message you want to print")
  lcd.print(3, 1, " your Mailbox");
  // Please use timed events when LCD printintg in void loop to avoid sending too many commands
  // It will cause a FLOOD Error, and connection will be dropped
}
  else {
  lcd.clear(); //Use it to clear the LCD Widget
  lcd.print(0, 0, "Nothing in"); // use: (position X: 0-15, position Y: 0-1, "Message you want to print")
  lcd.print(3, 1, " your Mailbox");
  // Please use timed events when LCD printintg in void loop to avoid sending too many commands
  // It will cause a FLOOD Error, and connection will be dropped
  }
}

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Blynk.begin(auth, "Romanista", "12341234");
  while (Blynk.connect() == false) {
    // Wait until its connected
  }
  lcd.clear(); //Use it to clear the LCD Widget
  timer.setInterval(1000L, Read_Values);
}
void loop() {
  Blynk.run();    
  timer.run(); // Initiates SimpleTimer
}
