#include <LiquidCrystal.h> //LCD SCREEN LIBRARY identification process

LiquidCrystal lcd(12,11,5,4,3,2); //LCD display pins connected on your board

int trig = 9;
int echo = 10;
int buzzer = 13;

long sure; //sure Since the named variable cannot be an integer, we defined it as long.

int distance;

void setup() 
{
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(buzzer, OUTPUT);

  lcd.begin(16,2);
  lcd.clear();
}

void loop() 
{

  digitalWrite(trig,LOW); //Capture the first head voice send
  delayMicroseconds(2); //Wait for 2 milliseconds

  digitalWrite(trig, HIGH); //send sound wave
  delayMicroseconds(10); //Wait 10 milliseconds
  digitalWrite(trig, LOW); //Turn off sending sound waves

  sure = pulseIn(echo, HIGH); //hold the incoming sound wave, transfer it to Sura

  distance = sure*0.034/2; //The formula we need to apply with sound waves to find the distance

  if (distance <=5) //if the distance is 5 or less
  {
    tone(buzzer,HIGH); //let the buzzer work
  }

  else //if not

  {    
    noTone(buzzer); //shut the buzzer
  }

  lcd.print("distance : "); //constant writing on the lcd screen
  lcd.print(distance);
  delay(3000); //3 wait a second

  lcd.clear();

}
