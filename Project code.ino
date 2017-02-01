int trigPin1 = 2;
int echoPin1 = 4;

int trigPin2 =7;
int echoPin2 = 8;


int ledPin1 = 9;
int ledPin2 = 10;
int duration2, distance2;
int red,green;
int duration1, distance1;
int c;

void setup() {
  Serial.begin (9600);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
 
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);

  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
}

void firstsensor();
void secondsensor();
void setColor(int red,int green)
  {
    #ifdef COMMON_CATHODE
    red = 255 - red;
    green = 255 - green;
    #endif
    analogWrite(ledPin1, red);
    analogWrite(ledPin2, green);
    
  }
  
void firstsensor(){ // This function is for first sensor.
  
  digitalWrite (trigPin1, HIGH);
  delayMicroseconds (10);
  digitalWrite (trigPin1, LOW);
  duration1 = pulseIn (echoPin1, HIGH);
  distance1 = (duration1/2) / 29.1;

      Serial.print("1st Sensor: ");
      Serial.print(distance1); 
      Serial.print("cm    ");

 
   if (distance1 < 15  ) {  // Change the number for long or short distances.
    setColor(255, 0);
        delay(5000);
        setColor(0,0);
        c=1;
        secondsensor();9
  } 
    else if (!(distance1 < 15 ) && c !=1){
    setColor(0, 255);
        delay(5000);
        setColor(0,0);
        c=1;
        firstsensor();     
  } 
   else if(c==1)
   {
     c=0;
     secondsensor();
   }
   
}
void secondsensor(){ // This function is for second sensor.
    
    digitalWrite (trigPin2, HIGH);
    delayMicroseconds (10);
    digitalWrite (trigPin2, LOW);
    duration2 = pulseIn (echoPin2, HIGH);
    distance2 = (duration2/2) / 29.1;
 
      Serial.print("2nd Sensor: ");
      Serial.print(distance2); 
      Serial.print("cm    ");
  
    if (distance2 < 15 && distance2>5) {  // Change the number for long or short distances.
        firstsensor();
}
else{
    setColor(0, 0);
        
}
}

void loop() {
Serial.println("\n");

secondsensor();

delay(100);
} 
