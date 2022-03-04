#include "dht.h"
#define dht_apin A2 // Analog Pin sensor is connected to
//#define SensorPin A1
#define SensorPin A1         // the pH meter Analog output is connected with the Arduino’s Analog
#define echoPin 12 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 11 //attach pin D3 Arduino to pin Trig of HC-SR04
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement
unsigned long int avgValue;  //Store the average value of the sensor feedback
float b;
int buf[10],temp;
int sensorValue;
dht DHT;
String crop;
String msg="Enter your choice:";
String op;
void setup() 
{
  // put your setup code here, to run once:
  pinMode(3,OUTPUT);
   Serial.begin(9600);
  delay(2000);//Delay to let system boot
   pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
  Serial.println("Ultrasonic Sensor HC-SR04 Test"); // print some text in Serial Monitor
  Serial.println("with Arduino UNO R3");
 
}

void loop() 
{
  DHT.read11(dht_apin);
  sensorValue= analogRead (A0);
  sensorValue= map (sensorValue,550,10,0,100);
  Serial.println(DHT.humidity);
  Serial.println(msg);
  while(Serial.available()==0)
  {
  
  }
  int inByte = Serial.read();
  switch (inByte)
  {
    case '1':
    {
      DHT.read11(dht_apin);
  sensorValue= analogRead (A0);
  sensorValue= map (sensorValue,550,10,0,100);
      delay(1000);
  
      Serial.println("let us search for suitable crop");
      Serial.println("please wait until we generate our results...!!");
      delay(2000);
      if(DHT.temperature>=22 && DHT.temperature<=37 && DHT.humidity>=60 && DHT.humidity<=80 && sensorValue>=35 && sensorValue<=55)
      {
        String op="HURRAY!suitable crop is  RICE";
        //Serial.println("HURRAY!suitable crop is  RICE");
        Serial.println(op);
      }
      else if(DHT.temperature>=10 && DHT.humidity<=30 && DHT.humidity<=70 && sensorValue>=35 && sensorValue<=45 )
      {
        String op="HURRAY!suitable crop is  TULASI";
        Serial.println(op);
      }
      else if(DHT.temperature>=10 && DHT.temperature<=15 and DHT.humidity>=50 && DHT.humidity<=60 && sensorValue>=45 && sensorValue<=55 )
      {
        String op="HURRAY!suitable crop is  WHEAT";
        Serial.println(op); 
        
      }
      else if(DHT.temperature>=27 && DHT.temperature<=32 && DHT.humidity>=35 && DHT.humidity<=45 )
      {
        if((sensorValue>=35 && sensorValue<=45)||(sensorValue>=10.5 && sensorValue<=22))
        {
          String op="HURRAY!suitable crop is  MILLETS";
          Serial.println(op); 
        
        }
      }
      else if(DHT.temperature>=20 && DHT.temperature<=25 && DHT.humidity>=0)
      {
        if(sensorValue>=15 && sensorValue<=25)
        {
          Serial.println("it is sandy soil");
          String op="HURRAY!suitable crop is  GRAMS";
          Serial.println(op); 
        
        }
         if(sensorValue>=15 && sensorValue<=25)
        {
         Serial.println("it is loamy soil");
          String op="HURRAY!suitable crop is  GRAMS";
          Serial.println(op); 
        
        }
         if(sensorValue>=15 && sensorValue<=25)
        {
          Serial.println("it is clay soil");
          String op="HURRAY!suitable crop is  GRAMS";
          Serial.println(op); 
        
        }
     }
     else if(DHT.temperature>=21 && DHT.temperature<=27 && DHT.humidity>=80 && DHT.humidity<=85 && sensorValue>=35 && sensorValue<=45)
     {
      String op="HURRAY!suitable crop is  sugarcane";
      Serial.println(op);
     }
     else if(DHT.temperature>=21 && DHT.temperature<=30 && DHT.humidity>=11.1 && DHT.humidity<=25 && sensorValue>=10.5 && sensorValue<=22.0 )
     {
      String op="HURRAY!suitable crop is  COTTON";
      Serial.println(op);
     }
     
     else if(DHT.temperature>=20 and DHT.temperature<=30 and DHT.humidity>=9.0 and sensorValue>=35 and sensorValue<=45 )
     {
       String op="HURRAY!suitable crop is  oil seed";
       Serial.println(op);
     }
     
     else if(DHT.temperature>=20 && DHT.temperature<=30 && DHT.humidity>=45 && sensorValue>=35 && sensorValue<=45 )
     {
      String op="HURRAY!suitable crop is TEA";
      Serial.println(op);
     }
     else if(DHT.temperature>=15 && DHT.temperature<=28 && DHT.humidity>=45 && sensorValue>=35 && sensorValue<=45 )
     {
       String op="HURRAY!suitable crop is coffee";
       Serial.println(op);
     
     }
     else
     {
      String op="Oops..! Thins land is not suitable for farming.. :(";
      Serial.println(op);
     // Serial.println("Oops..! This land is not suitable for farming.. :(");
     }
     delay(2000);
      
     break;
    }
    
  case '2':
  {
    if(sensorValue<0)
      {
         Serial.println("Moisture level is low..! Don't worry...! Watering plants");

        delay(1000);
        digitalWrite(3, HIGH);  
      }
      else{
        delay(1000);
        digitalWrite(3, LOW); 
      }
    /*DHT.read11(dht_apin);
    Serial.print("Current humidity = ");
    Serial.print(DHT.humidity);
    Serial.print("%  ");
    Serial.print("temperature = ");
    Serial.print(DHT.temperature); 
    Serial.print("C  ");
    Serial.println("Soil Moisture value= ");
    Serial.print(sensorValue); 
    if(sensorValue<0)
     {
      digitalWrite(3,HIGH);
     }
     else
     {
      digitalWrite(3,LOW);
     } 
    break;*/
    delay(2000);
    Serial.println("Pest detection mode:");
    delay(2000);
    digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  Serial.print("OMG..!Pests identified!! Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  delay(2000);
  Serial.println("Finding ph value ");
  for(int i=0;i<10;i++)       //Get 10 sample value from the sensor for smooth the value
  { 
    buf[i]=analogRead(SensorPin);
    delay(10);
  }
  for(int i=0;i<9;i++)        //sort the analog from small to large
  {
    for(int j=i+1;j<10;j++)
    {
      if(buf[i]>buf[j])
      {
        temp=buf[i];
        buf[i]=buf[j];
        buf[j]=temp;
      }
    }
  }
  avgValue=0;
  for(int i=2;i<8;i++)                      //take the average value of 6 center sample
    avgValue+=buf[i];
  float phValue=(float)avgValue*5.0/1024/6; //convert the analog into millivolt
  phValue=3.5*phValue;                      //convert the millivolt into pH value
  Serial.print("    pH:");  
  Serial.print(phValue,2);
  Serial.println(" ");
  //digitalWrite(13, HIGH);       
  delay(800);
    break;
  }
  }
  delay(20000);
}
