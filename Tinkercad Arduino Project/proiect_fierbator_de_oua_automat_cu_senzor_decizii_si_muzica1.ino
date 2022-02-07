#include <LiquidCrystal.h>
  LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
  
  int sensor_Input;
  float temp;
  int tareState = 0;
  int moaleState = 0;
  int modState = 0;
  int i,sec;
//////////////////////////////////////////////////////////      
  void setup() {
  
    Serial.begin(9600);
    lcd.begin(16, 2);
    pinMode(2, INPUT);
    pinMode(3, INPUT);
    pinMode(4, OUTPUT);
  }
//////////////////////////////////////////////////////////
  void loop() {
    measure_Temp();
    display_Temp();
    
    tareState = digitalRead(3);
    moaleState = digitalRead(2);
    
      
    if(moaleState == HIGH){
      modState = 2;  
      Serial.print(modState);
     
    }
    
    if(tareState == HIGH){
      modState = 1; 
        Serial.print(modState);
      
    }
    delay(10);
    Serial.print(modState);
  }
//////////////////////////////////////////////////////////
void display_Temp(){
if(temp<100){
    lcd.setCursor(0, 0);
    Serial.print("Temp. Apa in C: ");
    Serial.print(temp);
    Serial.println();
    lcd.print("Temp. Apa in C: ");
    lcd.setCursor(5, 1);
    lcd.print(temp);
    delay(500);
    
}
    else if(temp>100){
     if(modState == 0){//Selectarea modului
    lcd.setCursor(0, 0);
    Serial.print("Oul se fierbe!  ");
    Serial.print(temp);
    Serial.println();
    lcd.print("Oul se fierbe!  ");
    lcd.setCursor(5, 1);
    lcd.print(temp);
    delay(1000);
      
    lcd.setCursor(0, 0);
    Serial.print("Fiert Tare/Mole?");
    Serial.println();
    lcd.print("Fiert Tare/Mole?");
    lcd.setCursor(5, 1);
      delay(1000); 
     
    }
//////////////////////////////////////////////////////////
      if(modState == 1){//Fiert Tare
      lcd.setCursor(0, 0);
    Serial.print("Fierb Tare!       ");
    lcd.print("Fierb Tare!          ");
    for(i=7;i>=0;i--){
         delay(1000);
         lcd.setCursor(0, 0);
    Serial.print("Minute ramase:");
    Serial.print(i);
    Serial.println();
    lcd.print("Minute ramase:");
    lcd.setCursor(5, 1);
    lcd.print("      ");
    lcd.setCursor(8, 1);
    lcd.print(i);
        }
         modState=4;
      
       
      }
//////////////////////////////////////////////////////////
    if(modState == 2)
    { //Fiert Moale
      lcd.setCursor(0, 0);
    Serial.print("Fierb Moale!       ");
    lcd.print("Fierb Moale!          ");
    for(i=3;i>=0;i--){
         delay(1000);
         lcd.setCursor(0, 0);
    Serial.print("Minute ramase:");
    Serial.print(i);
    Serial.println();
    lcd.print("Minute ramase:");
    lcd.setCursor(5, 1);
    lcd.print("      ");
    lcd.setCursor(8, 1);
    lcd.print(i);
        }
         modState=5;    
    }
//////////////////////////////////////////////////////////
      if(modState==4){
        lcd.setCursor(0, 0);
    Serial.print("OUL ESTE FIERT!!      ");
    lcd.print("OUL ESTE FIERT!!!          ");
        lcd.setCursor(8, 1);
    lcd.print("      ");
        tone(4,523,400); //C
        delay(400);
        tone(4,622,400); //Eb
        delay(400);
        tone(4,698,400);  //F
        delay(400);
        tone(4,739,400);  //F#
        delay(400);
        tone(4,698,400);  //F
        delay(400);
        tone(4,622,400); //Eb
        delay(400);
        tone(4,523,2000); //C
        delay(1000);
        tone(4,466,200); //Bb
        delay(200);
        tone(4,587,200); //Eb
        delay(200);
        tone(4,523,1000); //C
        delay(1000);
        
        tone(4,261,200); //C4
        delay(400);
        tone(4,392,200); //G4
        delay(1000);
        
        tone(4,523,400); //C
        delay(400);
        tone(4,622,400); //Eb
        delay(400);
        tone(4,698,400);  //F
        delay(400);
        tone(4,739,400);  //F#
        delay(400);
        tone(4,698,400);  //F
        delay(400);
        tone(4,622,400); //Eb
        delay(400);
        tone(4,739,1500);  //F#
        delay(1650);
        tone(4,739,300);  //F#
        delay(300);
        tone(4,698,300);  //F
        delay(300);
        tone(4,622,300); //Eb
        delay(300);
        tone(4,739,300);  //F#
        delay(300);
        tone(4,698,300);  //F
        delay(300);
        tone(4,622,300); //Eb
        delay(300);
        tone(4,523,400); //C
        delay(400);
        
        
        modState=0;
      }
    }  
//////////////////////////////////////////////////////////
  if(modState==5){
        lcd.setCursor(0, 0);
    Serial.print("OUL ESTE FIERT!!      ");
    lcd.print("OUL ESTE FIERT!!!          ");
        lcd.setCursor(8, 1);
    lcd.print("      ");
        tone(4,73.42,200); //D2
        delay(500);
    	tone(4,116.54,100); //Bb2
        delay(400);
    	tone(4,110,200); //A2
        delay(500);
        tone(4,116.54,200); //Bb2
        delay(500);
    	tone(4,65.4,200); //C2
        delay(500);
    	tone(4,110,200); //A2
        delay(500);
    	tone(4,116.54,100); //Bb2
        delay(300);
  		tone(4,73.42,200); //D2
        delay(500);
    	tone(4,116.54,100); //Bb2
        delay(400);
    	tone(4,110,200); //A2
        delay(500);
        tone(4,116.54,200); //Bb2
        delay(500);
    	tone(4,65.4,200); //C2
        delay(500);
    	tone(4,110,200); //A2
        delay(500);
    	tone(4,116.54,100); //Bb2
        delay(300);
    
    modState = 0;
  }
    
 
  } 
//////////////////////////////////////////////////////////
  void measure_Temp()
  {
    sensor_Input = analogRead(A0);
    temp = (float)sensor_Input / 1024;
    temp = temp * 5;
    temp = temp - 0.5;
    temp = temp * 100;
  }
  
  
    