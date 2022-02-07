
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);



Servo pressureSwitch;
int pumpPin = 8;
const int trigPin = 13;
const int echoPin = 12;
const int optionButton1 = 2;
const int optionButton2 = 3;
const int optionButton3 = 4;
int distance,duration;
bool isSelected = false;
bool istrue = true;
int debitSenzor = A15;
int selectedModeIndex;
int X;
int Y;
float TIME = 0;
float FREQUENCY = 0;
float WATER = 0;
float TOTAL = 0;
float LS = 0;
void setup() {
  pressureSwitch.attach(9);
  pressureSwitch.write(0);
  pinMode(pumpPin,OUTPUT); 
  pinMode(optionButton1,INPUT);
  pinMode(optionButton2,INPUT);
  pinMode(optionButton3,INPUT);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  digitalWrite(pumpPin,HIGH);
  pinMode(debitSenzor,INPUT);
  lcd.init();
  lcd.setBacklight(100);
  initialize();
 
  
  
}


bool selected = false;


void loop() {
  
if(getDistance()<=5){
 while(selected == false){
 relaxModeInfo();
 if(selected == true){
  break;
 }
 ecoModeInfo();
 if(selected == true){
  break;
 }
 superEcoModeInfo();
 
 }
 getSelectedMode(istrue);
 istrue = false;
 startShower();
}
selected = false;
istrue = true;
lcd.clear();
Serial.println(getDistance());
}




void startShower(){
  X = pulseIn(debitSenzor, HIGH);
  switch(selectedModeIndex){
    case 1:digitalWrite(pumpPin,LOW);
    delay(11000);
    digitalWrite(pumpPin,HIGH);break;

    case 2:digitalWrite(pumpPin,LOW);
    delay(8000);
    digitalWrite(pumpPin,HIGH);break;

    case 3:digitalWrite(pumpPin,LOW);
    delay(5000);
    digitalWrite(pumpPin,HIGH);break;
  }
  Y = pulseIn(debitSenzor, LOW);
TIME = X + Y;
FREQUENCY = 1000000/TIME;
WATER = FREQUENCY/7.5;
LS = WATER/60;
if(FREQUENCY >= 0)
{
if(isinf(FREQUENCY))
{
lcd.clear();
lcd.setCursor(0,0);
lcd.print("VOL. :0.00");
lcd.setCursor(0,1);
lcd.print("TOTAL:");
lcd.print( TOTAL);
lcd.print(" L");
}
else
{
TOTAL = TOTAL + LS;
Serial.println(FREQUENCY);
lcd.clear();
lcd.setCursor(0,0);
lcd.print("VOL.: ");
lcd.print(WATER);
lcd.print(" L/M");
lcd.setCursor(0,1);
lcd.print("TOTAL:");
lcd.print( TOTAL);
lcd.print(" L");
}
}
delay(2000);
}


int getDistance(){
 
 
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  
  distance = duration * 0.034 / 2; 
  return distance;

}

void initialize(){
  lcd.setCursor(5,0);
  lcd.print("Sheco");
  lcd.setCursor(4,1);
  lcd.print("Loading...");
  
  delay(3000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Choose the Mode:");
  delay(2000);
  lcd.clear();  
}
String selectedMode;
void relaxModeInfo(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("1.Relax Mode-15m");
  lcd.setCursor(0,1);
  lcd.print("121.8L|4.12KWh");
  delay(5000);
  selected = checkIfButtonWasPressed();
  lcd.clear();
 
}

void ecoModeInfo(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("2.Eco Mode-10m");
  lcd.setCursor(0,1);
  lcd.print("81.25L|2.75KWh");
  delay(5000);
  selected = checkIfButtonWasPressed();
  lcd.clear();
  
}

void superEcoModeInfo(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("3.Eco+ Mode-5m");
  lcd.setCursor(0,1);
  lcd.print("40.6L|1.37KWh");
  delay(5000);
  selected = checkIfButtonWasPressed();
  lcd.clear();
}

bool checkIfButtonWasPressed(){

  if(digitalRead(optionButton1) ==HIGH){
    selectedMode = "Relax Mode";
    selectedModeIndex = 1;
    pressureSwitch.write(0);
    return true;
  }else
  if(digitalRead(optionButton2) ==HIGH){
    selectedMode = "Eco Mode";
    selectedModeIndex = 2;
    pressureSwitch.write(70);
    return true;
  }else
  if(digitalRead(optionButton3) ==HIGH){
    selectedMode = "Super-Eco Mode";
    selectedModeIndex = 3;
    pressureSwitch.write(120);
    return true;
  }
  return false;
  }
int getSelectedMode(bool showIt){
  if(showIt==true){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("You selected:");
  lcd.setCursor(0,1);
  lcd.print(selectedMode);
  delay(3000);
  lcd.clear();}
  return selectedModeIndex;
}
  




 
