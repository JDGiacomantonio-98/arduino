void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for(int pin = 2; pin<6; pin++){
    pinMode(pin,OUTPUT);
    digitalWrite(pin, HIGH);
    delay(150);
    digitalWrite(pin, LOW);
  };

  for(int i = 0; i<2;i++){
      
      for(int pin = 2; pin<6; pin++){
        digitalWrite(pin, HIGH);
      };

      delay(250);

      for(int pin = 2; pin<6; pin++){
        digitalWrite(pin, LOW);
      };

      delay(100);
  };
};

void loop() {
  // put your main code here, to run repeatedly:
  float tmp36read = analogRead(A0)*(5000.0/1024.0); // temperature sensor reading in mV
  float temp = (tmp36read-500)/10.0; // temperature sensor reading in mV

  if(temp>38){
    digitalWrite(2,LOW);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,HIGH); // red light
    delay(80)
  }
  else if(temp>37.6 && temp <= 38.5){
    digitalWrite(2,LOW);
    digitalWrite(3,LOW);
    digitalWrite(4,HIGH); // yellow light
    digitalWrite(5,LOW); 
    delay(100)
  }
  else if(temp>36.5 && temp <= 37.6){
    digitalWrite(2,LOW);
    digitalWrite(3,HIGH); //green light
    digitalWrite(4,LOW); 
    digitalWrite(5,LOW);
    delay(500)
  }
  else{
    digitalWrite(2,HIGH); //blue light
    digitalWrite(3,LOW); 
    digitalWrite(4,LOW); 
    digitalWrite(5,LOW);
    delay(250)
  };

  Serial.print(tmp36read);
  Serial.print(" mV => ");
  Serial.print(temp);
  Serial.print(" °C");
  Serial.println();
}
