/*

 
 Code to do an organ with four hc-sr04 sensors
 each sensor can trigger two notes, depending on the height of the hand in front of it (see MEDIUM and HIGHEST constants).
 
 Based on an example found on the internet, and fading memories of the laser harp/organ of Jean-Michel Jarre 
 
 May 2015,  @wadael
 */


#define trigPin1 8
#define trigPin2 9
#define trigPin3 10
#define trigPin4 11

#define echoPin1 4
#define echoPin2 5
#define echoPin3 6
#define echoPin4 7

/* this is values expressed in centimeters (cm) because I love the metric system */
#define MEDIUM 30
#define HIGHEST 60

#define DELAY_TIME 250  // Milliseconds


void setup() {

  Serial.begin (9600); // speed of the communication ; value used in the example

  /* Setting the arduino pins for outpout or input */
  pinMode(trigPin1, OUTPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(trigPin3, OUTPUT);
  pinMode(trigPin4, OUTPUT);

  pinMode(echoPin1, INPUT);
  pinMode(echoPin2, INPUT);
  pinMode(echoPin3, INPUT);
  pinMode(echoPin4, INPUT);
}



void loop() {
  checkSensor(trigPin1, echoPin1,"do","sol");
  checkSensor(trigPin2, echoPin2,"re","la");
  checkSensor(trigPin3, echoPin3,"mi","si");
  checkSensor(trigPin4, echoPin4,"fa","do");
}


int checkSensor(int trigPin, int echoPin, char* lowKey, char* highKey){
  long duration, distance;
  digitalWrite(trigPin, LOW);  // Added this line
  delayMicroseconds(2); // Added this line

  digitalWrite(trigPin, HIGH);
  //  delayMicroseconds(1000); - Removed this line
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;

  if (distance > HIGHEST || distance <= 0){
    /* Serial.print( trigPin );
     Serial.print(":");
     Serial.print("Out of range :");
     */
  }
  else {
    /* Serial.print( trigPin );
     Serial.print( ";");
     Serial.print(distance);
     Serial.print(" cm " );
     */
    if(distance >0 && distance <= MEDIUM){
      Serial.println(  lowKey );
    }
    else{
      if(distance >MEDIUM && distance <= HIGHEST){
        Serial.println(  highKey );
      }
    }
    delay(DELAY_TIME);  
  }

}



