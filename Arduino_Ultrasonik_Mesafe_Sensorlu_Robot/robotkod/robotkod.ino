#define echoPin 6
#define trigPin 7
#define buzzerPin 8

const int solMotor = 11;
const int sagMotor = 12;

int maximumRange = 50;
int minimumRange = 0;

void setup()
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(solMotor,OUTPUT);
  pinMode(sagMotor,OUTPUT);

}

void loop()
{
  int olcum = mesafe(maximumRange, minimumRange);
  digitalWrite(solMotor, HIGH); digitalWrite(sagMotor, HIGH);
  melodi(olcum *10);
  delay(olcum *10);
  
  digitalWrite(solMotor, LOW ); digitalWrite(sagMotor, LOW);
}

int mesafe(int maxrange, int minrange)
{
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration / 58.2;
  delay(50);
  if (distance >= maxrange || distance <= minrange)
    return 0;
  return distance;
}

int melodi(int dly)
{
  tone(buzzerPin, 440);
  delay(dly);
  noTone(buzzerPin);
  delay(dly);
}
