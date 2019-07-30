#include <SoftwareSerial.h>

SoftwareSerial mySerial(2, 3); // RX, TX

#define trigpin1 8
#define echopin1 9
#define trigpin2 10
#define echopin2 11

long duration1,duration2;
float distance1,distance2;
String apiKeyslot1 = "BNAX3A3N38W8EQCV",apiKeyslot2 = "SG1A9WUSPRZIYXS5";


void setup() {
  
pinMode(echopin1,INPUT);
pinMode(echopin2,INPUT);
pinMode(trigpin1,OUTPUT);
pinMode(trigpin2,OUTPUT);

Serial.begin(115200);
mySerial.begin(115200);
mySerial.println("AT+RST");
delay(2000);
 mySerial.println("AT+CWMODE=3");
 delay(2000);
 mySerial.println("AT+CWJAP=\"redmi\",\"xxxxxxxxx\"");
 delay(2000);
}
void loop() {
digitalWrite(trigpin1,LOW);
delayMicroseconds(100);
digitalWrite(trigpin1,HIGH);
delayMicroseconds(100);
digitalWrite(trigpin1,LOW);
duration1=pulseIn(echopin1,HIGH);
digitalWrite(trigpin2,LOW);
delayMicroseconds(100);
digitalWrite(trigpin2,HIGH);
delayMicroseconds(100);
digitalWrite(trigpin2,LOW);
duration2=pulseIn(echopin2,HIGH);

distance1=(duration1*0.034)/2;
distance2=(duration2*0.034)/2;
//////////////SLOT 1/////////////////////////SLOT 1////////////////////////////SLOT 1//////////////////////SLOT 1/////////////////SLOT 1//////////////SLOT 1/////////////////SLOT 1/////////
// convert to string////////////////////////////////////////////////////////////////////////////////////////
 float distanceuiu;
  char buf1[32];
  String strcm1=dtostrf(distance1,4,1,buf1);
  Serial.print(strcm1);
  Serial.println(" cm1");
  // TCP connection//////////////////////////////////////////////////////////////////////////////////////////
  String cmd1 = "AT+CIPSTART=\"TCP\",\"184.106.153.149\",80";
  mySerial.println(cmd1); 
  if(mySerial.find("Error")){
    Serial.println("AT+CIPSTART error");
    return;
  }
  // prepare GET string/////////////////////////////////////////////////////////////////////////////////////
  String getStr1 = "GET /update?api_key=";
  getStr1 += apiKeyslot1;
  getStr1 +="&field1=";
  getStr1 += String(strcm1);
  getStr1 += "\r\n\r\n";
  // send data length///////////////////////////////////////////////////////////////////////////////////////
  cmd1 = "AT+CIPSEND=";
  cmd1 += String(getStr1.length());
  mySerial.println(cmd1);
  if(mySerial.find(">")){
    mySerial.print(getStr1);
  }
  else{
    mySerial.println("AT+CIPCLOSE");
    Serial.println("AT+CIPCLOSE");  
  }
  delay(2000);
  //////////////SLOT 2/////////////////////////SLOT 2////////////////////////////SLOT 2//////////////////////SLOT 2/////////////////SLOT 2//////////////SLOT 2/////////////////SLOT 2/////////

// convert to string////////////////////////////////////////////////////////////////////////////////////////
  char buf2[32];
  String strcm2=dtostrf(distance2,4,1,buf2);
  Serial.print(strcm2);
  Serial.println(" cm2");
  // TCP connection//////////////////////////////////////////////////////////////////////////////////////////
  String cmd2 = "AT+CIPSTART=\"TCP\",\"184.106.153.149\",80";
  mySerial.println(cmd2); 
  if(mySerial.find("Error")){
    Serial.println("AT+CIPSTART error");
    return;
  }
  // prepare GET string/////////////////////////////////////////////////////////////////////////////////////
  String getStr2 = "GET /update?api_key=";
  getStr2 += apiKeyslot2;
  getStr2 +="&field1=";
  getStr2 += String(strcm2);
  getStr2 += "\r\n\r\n";
  // send data length///////////////////////////////////////////////////////////////////////////////////////
  cmd2 = "AT+CIPSEND=";
  cmd2 += String(getStr2.length());
  mySerial.println(cmd2);
  if(mySerial.find(">")){
    mySerial.print(getStr2);
  }
  else{
    mySerial.println("AT+CIPCLOSE");
    Serial.println("AT+CIPCLOSE");  
  }
  
  delay(16000);
  
}
