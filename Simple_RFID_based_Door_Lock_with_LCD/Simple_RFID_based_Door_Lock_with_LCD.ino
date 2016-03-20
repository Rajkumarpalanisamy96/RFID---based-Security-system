#include<SoftwareSerial.h>
#include<LiquidCrystal.h>
#define RELAYPIN 13
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
SoftwareSerial mySerial(9,10);
int read_count=0;
int j=0,k=0; 
char data_temp, RFID_data[12];
char Saved_Tags[1][12]={
                       {'5','1','0','0','9','4','C','E','0','F','0','4'},
                      };
boolean tag_check,tag_status,entry_control;

void setup()
{
mySerial.begin(9600);
Serial.begin(9600);
pinMode(RELAYPIN,OUTPUT);
lcd.begin(16, 2); 
}

void loop()
{
RecieveData();
CheckData();
AccessCheck();
}

void RecieveData()
{
lcd.setCursor(0,0);
lcd.print("Show Your Card");
if(mySerial.available()>0)
{
data_temp=mySerial.read();
RFID_data[read_count]=data_temp;
read_count++;
}}

void CheckData()
{
if(read_count==12)
{
entry_control=true;  
for(k=0;k<3;k++)
{
for(j=0;j<12;j++)
{
  if(Saved_Tags[k][j]==RFID_data[j])
 {
  tag_check=true;
  
  }
  else
  {
  tag_check=false;
  break;
  }
}
if(tag_check==true)
{
tag_status=true;
}}
read_count=0;
}}

void AccessCheck()
{
if(entry_control==true)
{
if(tag_status==true)
{
  lcd.clear();
  delay(100);
lcd.setCursor(0,1);  
lcd.print("Access Granted");

Serial.println("Faculty: VIKAS UPADHYAY");
  Serial.println("Status: PRESENT");

digitalWrite(RELAYPIN,HIGH);
     delay (5000);
      digitalWrite (RELAYPIN,LOW);
      lcd.clear();
}
 
else
{
  lcd.clear();
  delay(100);
 lcd.setCursor(0,1);
lcd.print("Access Denied");

}
entry_control=false;
tag_status=false;
}}
  
