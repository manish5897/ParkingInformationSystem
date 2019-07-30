#define trigpin 13
#define echopin1 12
#define echopin2 11
#define echopin3 10
#define echopin4 9
void setup() {
pinMode(echopin1,INPUT);
pinMode(echopin2,INPUT);
pinMode(echopin3,INPUT);
pinMode(echopin4,INPUT);
pinMode(trigpin,OUTPUT);
Serial.begin(115200);

}
void loop() {
long duration1;
long duration2;
long duration3;
long duration4;
float distance1;
float distance2;
float distance3;
float distance4;
digitalWrite(trigpin,LOW);
delayMicroseconds(100);
digitalWrite(trigpin,HIGH);
delayMicroseconds(100);
digitalWrite(trigpin,LOW);
duration1=pulseIn(echopin1,HIGH);
digitalWrite(trigpin,LOW);
delayMicroseconds(100);
digitalWrite(trigpin,HIGH);
delayMicroseconds(100);
digitalWrite(trigpin,LOW);
duration2=pulseIn(echopin2,HIGH);
digitalWrite(trigpin,LOW);
delayMicroseconds(100);
digitalWrite(trigpin,HIGH);
delayMicroseconds(100);
digitalWrite(trigpin,LOW);
duration3=pulseIn(echopin3,HIGH);
digitalWrite(trigpin,LOW);
delayMicroseconds(100);
digitalWrite(trigpin,HIGH);
delayMicroseconds(100);
digitalWrite(trigpin,LOW);
duration4=pulseIn(echopin4,HIGH);
distance1=(duration1*0.034)/2;
distance2=(duration2*0.034)/2;
distance3=(duration3*0.034)/2;
distance4=(duration4*0.034)/2;
//digitalWrite(trigpin,HIGH);
//delayMicroseconds(100);
//digitalWrite(trigpin,LOW);


//digitalWrite(trigpin,HIGH);
//delayMicroseconds(100);
//digitalWrite(trigpin,LOW);


//digitalWrite(trigpin,HIGH);
//delayMicroseconds(100);
//digitalWrite(trigpin,LOW);



Serial.print(distance1);
Serial.println(" cm1");
delay(1000);
Serial.print(distance2);
Serial.println(" cm2");
delay(1000);
Serial.print(distance3);
Serial.println(" cm3");
delay(1000);
Serial.print(distance4);
Serial.println(" cm4");
delay(1000);
}
