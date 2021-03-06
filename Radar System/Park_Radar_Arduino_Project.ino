/* 
Author: Kamran Rashidov
Project: Park Radar System 
YouTube Channel: Electrologia
*/

const int trigPin = 5;
const int echoPin = 3;
const int bluePin = 9;
const int redPin = 8;
const int whitePin = 10;
const int buzzer = 2;

long duration;
long interval;

void setup()
{
  pinMode(buzzer, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(whitePin, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop()
{ 
  digitalWrite(trigPin, LOW);
  delayMicroseconds(10000);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10000);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  interval = duration * 0.034/2;

  Serial.print("Distance: ");
  Serial.println(interval);


  if ((interval >= 20)&&(interval <= 30))
  {
    digitalWrite(whitePin, HIGH);
    tone(buzzer, 250);
    delay(250);
    noTone(buzzer);
    digitalWrite(whitePin, LOW);
    delay(250);
    digitalWrite(bluePin, LOW);
    digitalWrite(redPin, LOW);
    
  }
  else if ((interval >= 10)&&(interval < 20))
  {
    digitalWrite(bluePin, HIGH);
    tone(buzzer, 350);
    delay(150);
    noTone(buzzer);
    digitalWrite(bluePin, LOW);
    delay(150);
    digitalWrite(redPin, LOW);
    digitalWrite(whitePin, LOW);
  }
  else if (interval < 10)
  {
    digitalWrite(redPin, HIGH);
    tone(buzzer, 450);
    delay(50);
    noTone(buzzer);
    digitalWrite(redPin, LOW);
    delay(50);
    digitalWrite(bluePin, LOW);
    digitalWrite(whitePin, LOW);
  }
  else
  {
    digitalWrite(redPin, LOW);
    digitalWrite(bluePin, LOW);
    digitalWrite(whitePin, LOW);
  }
}
