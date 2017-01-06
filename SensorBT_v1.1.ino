#include <SoftwareSerial.h>
SoftwareSerial mySerial(3, 2); // RX, TX

char command;
String string;
boolean ledon = false;
#define led 4
#define SW1 5

  void setup()
  {
    //Setup usb serial connection to computer
    Serial.begin(38400);
  
    mySerial.begin(9600);
    delay(100);
    pinMode(led, OUTPUT);
    Serial.print("Probando Dispositivo: ");

    pinMode(SW1, INPUT);
    digitalWrite(SW1, HIGH);
  }

  void loop()
  {
    if(mySerial.available()>0)
    {
      char toSend = (char)mySerial.read();
      Serial.print("Tengo Dato: ");
      Serial.print(toSend);
      Serial.print("\n");
      LeoInstruccion(toSend);    
    }


   if(digitalRead(SW1)){ //abierto
      if(ledon == false){
        //ledOn();
        ledon = true;
        mySerial.print("_SW1-A#");
        mySerial.print("\n\r");
        Serial.print("_SW1-A#");
        Serial.print("\n\r");
      }
   }else{
    if(ledon == true){
      //ledOff();
      ledon = false;
      mySerial.print("_SW1-C#");
      mySerial.print("\n\r");
      Serial.print("_SW1-C#");
      Serial.print("\n\r");
    }
   }

    
   delay(500); 
    
 }

void LeoInstruccion(char string)
{
  
switch(string){
  case '1':  

    {
        ledOn();
        //ledon = true;
        //mySerial.println(string);
    }
    break;
   case '0': 
    {
        ledOff();
        //ledon = false;
        //mySerial.println(string);
    }
   break;
}
}


void ledOn()
   {
      digitalWrite(led, HIGH);
      delay(10);
    }
 
 void ledOff()
 {
      digitalWrite(led, LOW);
      delay(10);
 }
 

    
