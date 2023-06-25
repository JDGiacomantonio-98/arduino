const int Vin = 5;
float Vread = 0;
float R0 = 10000;
float R1 = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Vread = (analogRead(0) * Vin)/1024.0;
  R1 = R0*((Vin/Vread)-1);
  Serial.print("Voltage after Rx = ");
  Serial.print(Vread);
  Serial.print(" => Resistance = ");
  Serial.print(R1);
  Serial.println();
  delay(1000);
}