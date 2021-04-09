//Adding REMOTE CONTROLLER LIBRARY

#include <boarddefs.h>
#include <IRremote.h>
#include <IRremoteInt.h>
#include <ir_Lego_PF_BitStreamEncoder.h>

int alici = 2;

IRrecv irrecv(alici); //we told pin number 2 to get information to the library

decode_results sonuc; //We defined a variable (in command language) to understand our results, that is, whether the key is pressed

//Definition of KEYS ON THE CONTROL

#define BUTON1 0xFFA25D
#define BUTON2 0xFF629D
#define BUTON3 0xFFE21D
#define BUTON_sifir 0xFF9867

void setup() 
{
  // Led identification operations
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);

  
  irrecv.enableIRIn(); // The process of activating the control receiver
}

void loop() 
{


  if (irrecv.decode(&sonuc)) // if a key was pressed
  {

    if(sonuc.value == BUTON1) // If the value in the pressed key is equal to the value named button1
    {
      digitalWrite(8,HIGH); // Turn on the led number 8
    }

    if(sonuc.value == BUTON2) // If the value in the pressed key is equal to the value named button2
    {
      digitalWrite(9,HIGH);  // Turn on the led number 9
    }

    if(sonuc.value == BUTON3) // If the other button on the pressed key is equal to the value named 3
    {
      digitalWrite(10,HIGH);  // Turn on the LED 10
    }

    if(sonuc.value == BUTON_sifir) // If the other button on the pressed key is equal to the value named zero
    {
      digitalWrite(8,LOW); // Turn off the 8 numbered led
      digitalWrite(9,LOW); // Turn off the 9 numbered led
      digitalWrite(10,LOW); // Turn off the led 10
    }

    irrecv.resume(); //Let the control work continue
    
  }
}
