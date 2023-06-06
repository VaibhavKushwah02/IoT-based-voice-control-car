 #include<SoftwareSerial.h>
  SoftwareSerial BT(2,3);//TX,
  String readvoice;
  #define MLa 8   //left motor 1st pin
  #define MLb 9   //left motor 2nd pin
  #define MRa 10  //right motor 1st pin
  #define MRb 11  //right motor 2nd pin
  void setup() {
  BT.begin(9600);
  Serial.begin(9600);
  //declaring Motors pin as output pin
  pinMode(MLa,OUTPUT);
  pinMode(MLb,OUTPUT);
  pinMode(MRa,OUTPUT);
  pinMode(MRb,OUTPUT);
  }
void loop() {
  while(BT.available())
  {
  delay(10);                                 //delay added to make thing stable
  char c=BT.read();                          //Conduct a serial read
  readvoice+=c;                              //build the string-"forward","reverse","left"and"right"
  }
  if(readvoice.length()>0) {
  Serial.println(readvoice);
  }
  // from this code we move in forward direction.
  if(readvoice=="forward"){
  digitalWrite(MLa,HIGH);
  digitalWrite(MLb,LOW);
  digitalWrite(MRa,HIGH);
  digitalWrite(MRb,LOW);
  delay(100);
  }
  // from this code we move in backward direction.
  else if(readvoice=="back"){
  digitalWrite(MLa,LOW);
  digitalWrite(MLb,HIGH);
  digitalWrite(MRa,LOW);
  digitalWrite(MRb,HIGH);
  delay(100);
  }
  // from this code we move in Right direction.
  else if(readvoice=="turn right"){
  digitalWrite(MLa,HIGH);
  digitalWrite(MLb,LOW);
  digitalWrite(MRa,LOW);
  digitalWrite(MRb,LOW);
  delay(100);
  }
  // from this code we move in Left direction.
  else if(readvoice=="turn left"){
  digitalWrite(MLa,LOW);
  digitalWrite(MLb,LOW);
  digitalWrite(MRa,HIGH);
  digitalWrite(MRb,LOW);
  delay(100);
  }
  // from this code we stop movement.
  else if(readvoice=="stop"){
  digitalWrite(MLa,LOW);
  digitalWrite(MLb,LOW);
  digitalWrite(MRa,LOW);
  digitalWrite(MRb,LOW);
  delay(100);
  }
  //Read the variable
  readvoice="";}