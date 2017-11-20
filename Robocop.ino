//Sensor Magnetic
const int magneticPin = 13;




//Relays PIN



//ASUS PREMIUM
const int relayAsusPremium = 8;

//ASUS ROG Crossair Formula
const int relayAsusFormula = 12;


//No usado por los momentos
const int relayPowerPinThree = 13;
const int relayPowerPinFour = 15;





int PowerForceMotherBoard(int pin)
{

   pinMode(pin, OUTPUT);
   delay(9000);
   pinMode(pin, INPUT);
   
  return 0;
}




int PowerMotherBoard(int pin)
{


   pinMode(pin, OUTPUT);
   delay(1000);
   pinMode(pin, INPUT);
   return 0;

}





/*
  Door flags
  
  1:1 = OPEN
  1:2 = CLOSED

*/


int CheckDoorSensor()
{

   
    if(digitalRead(magneticPin) == LOW)
    {
        //Puerta cerrada
        return 0;
    }
    
       else
       {
          //Puerta abierta
          return 1;
       }   
}



void setup()
{

    //Init WiFi params
    //const char ssid[]     = "yfa83vwhTddJjk3V";
    //const char pass[] = "HZxJ6Q9K2iwrKmKKX";    


  

     //Init Serial
     Serial.begin(9600);

  
    //Init magnetic sensor
    //pinMode(magneticPin, INPUT);
    //digitalWrite(magneticPin, HIGH);
     

    //Init power PC
    //pinMode(relayPowerPinThree, OUTPUT);
    
}

void loop()
{

   //Serial.println("Check sensor door");
   CheckDoorSensor();


   if (Serial.available() > 0)
   {

    
      int num = Serial.read();

      //Serial.print("Escribiste ... ");
      //Serial.println(num);




      //  48 == 0
      //  PowerForce ASUS ROG Formula
      
      if(num == 48)
      {        
        Serial.println("PowerForce ASUS ROG Formula");
        PowerForceMotherBoard(relayAsusFormula);
      }





      //  49 == 1
      //  PowerForce ASUS ROG Premium
      
      if(num == 49)
      {        
        Serial.println("PowerForce ASUS Premium");
        PowerForceMotherBoard(relayAsusPremium);
      }





      //  50 == 2
      //  Power ASUS ROG Formula
      
      if(num == 50)
      {        
        Serial.println("Power ASUS ROG Formula");
        PowerMotherBoard(relayAsusFormula);
      }




      //  51 == 3
      //  Power ASUS Premium
      
      if(num == 51)
      {        
        Serial.println("Power ASUS Premium");
        PowerMotherBoard(relayAsusPremium);
      }










      //  53 == 5
      //  Test para saber si todo esta OK
      
      if(num == 53)
      {        
        Serial.println("OK");
      }



      
   }

   delay(5000);
  
} 
