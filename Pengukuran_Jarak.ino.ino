const int trigPin = 10;
const int echoPin = 9;
int lampu = 13 ;
 
void setup() {
  Serial.begin(9600);
  pinMode(lampu, OUTPUT);
}
 
long duration, inches, cm;
  
void loop()
{
  pinMode(trigPin, OUTPUT);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
 
  inches = microsecondsKeInchi(duration);
  cm = microsecondsKeCenti(duration);
   
  Serial.print(inches);
  Serial.print(" in, ");
  Serial.print(cm);
  Serial.print(" cm");
  Serial.println();
 
  lampuNyala() ;
  
   
  delay(10);
}
 
long microsecondsKeInchi(long microseconds)
{
  return microseconds / 74 / 2;
}
 
long microsecondsKeCenti(long microseconds)
{
  return microseconds / 29 / 2;
}
 
void lampuNyala(){
   if(cm > 0 && cm <=30){
      digitalWrite(lampu,HIGH) ;
    }
    else{
      digitalWrite(lampu,LOW) ;
      }
  }
