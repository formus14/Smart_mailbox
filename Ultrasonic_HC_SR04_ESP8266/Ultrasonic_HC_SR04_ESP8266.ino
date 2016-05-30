#define trigPin D2
#define echoPin D1

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}
void Read_Values(){
  digitalWrite(trigPin, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(1000); 
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin, LOW);
}
void loop() {
  long duration, distance;
  Read_Values();
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  Serial.println(distance);
  if (distance < 4) {  // This is where the LED On/Off happens
  Serial.println("You have one Mail");
}
  else if (distance >= 200 || distance <= 0){
    Serial.println("Out of range");
  }
  else {
    Serial.print(distance);
    Serial.println(" cm");
  }
  delay(1000);
}
