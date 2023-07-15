#include <SoftwareSerial.h>

const int rxPin = 2;
const int txPin = 3;               
SoftwareSerial mySerial(rxPin, txPin);

int led = 4;
int bulb = 5;
int fan = 6;
int button = 7;
String data;

void setup() 
{
   Serial.begin(9600);
   mySerial.begin(9600);
   
   pinMode(led, OUTPUT);
   pinMode(bulb, OUTPUT);
   pinMode(fan, OUTPUT);
   pinMode(button, OUTPUT);
 
   digitalWrite(led, LOW);
   digitalWrite(bulbt, LOW);
   digitalWrite(fan, LOW);
   digitalWrite(button, LOW);
}

void loop() 
{
    int i = 0;
    char ch = 0;
    data="";
    while(1)
    { 
      while(mySerial.available()<=0);
      ch = mySerial.read();
      if(ch=='#')
      break;
      data+=ch;
    }
   Serial.println(data);
    
    if(data=="turn on led")
    { 
      digitalWrite(led,HIGH);
      Serial.println("led on");
    }
    else if(data=="*turn off led")
    {
      digitalWrite(led,LOW);
      Serial.println("led off");
    }
    else if(data=="turn on bulb")
    {
      digitalWrite(bulb,HIGH);
      Serial.println("bulb on");
    }
    else if(data=="turn off bulb")
    {
      digitalWrite(bulb,LOW);
      Serial.println("bulb off");
    }
    else if(data=="turn on fan")
    {
      digitalWrite(fan,HIGH);
      Serial.println("fan on");
    }
    else if(data=="turn off fan")
    {
      digitalWrite(fan,LOW);
      Serial.println("fan off");
    }
    else if(data=="turn on button")
    {
      digitalWrite(button,HIGH);
      Serial.println("button on");
    }
    else if(data=="turn on button")
    {
      digitalWrite(button,LOW);
      Serial.println("button off");
    }
    else if(data=="turn on all")
    {
      digitalWrite(led,HIGH);
      digitalWrite(bulb,HIGH);
      digitalWrite(fan,HIGH);
      digitalWrite(button,HIGH);
      Serial.println("all on");
    }
    else if(data=="turn off all")
    {
      digitalWrite(led,LOW);
      digitalWrite(bulb,LOW);
      digitalWrite(fan,LOW);
      digitalWrite(button,LOW);
      Serial.println("all off");
    
    }
    
}