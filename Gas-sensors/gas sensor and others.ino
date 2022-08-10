//GAS SENSORS
int smokeA0 = A2;
int smokeA1 = A1;
float smokeA2 = A3;
int smokeA3 =A0;
// Your threshold value
int sensorThres = 300;

//SOIL MOISTURE SENSOR
#define soilSensor A0
int goodMoisture = 200;

//Ambient light sensor
int temt6000Pin = A8;
//float light;
int light_value;


//UV-RAY
#define light A7
void setup() {
  //GAS SENSORS
  pinMode(smokeA0, INPUT);
  pinMode(smokeA1, INPUT);
  pinMode(smokeA2, INPUT);
  pinMode(smokeA3, INPUT);

  //Ambient light sensor
  pinMode(temt6000Pin, INPUT);
  
  Serial.begin(9600);
}

void loop() {
  //GAS SENSORS
  int analogSensor0 = analogRead(smokeA0);
  int analogSensor1 = analogRead(smokeA1);
  float analogSensor2 = analogRead(smokeA2);
  int analogSensor3 = analogRead(smokeA3);

  //SOIL MOISTURE SENSOR
    int sensorValue = analogRead(soilSensor);
  
  //UV-RAY
  int Lvalue = analogRead(light);// read the light

  //Analog light sensor
  int light_value = analogRead(temt6000Pin);
  float light = light_value * 0.0976;// percentage calculation 
  
  Serial.print("H2: ");
  Serial.print(analogSensor0-924-22+1.547);
  Serial.print("ppm");
  delay(200);
  Serial.print("      ");
  
  Serial.print("CO2: ");
  Serial.print(analogSensor1*1.4);
  Serial.print("ppm");
  delay(200);
  Serial.print("      ");
  
  Serial.print("CO: ");
  Serial.print(analogSensor2+0.2);
  Serial.print("ppm");
  delay(200);
  Serial.print("      ");
  
  Serial.print(" Air moisture: ");
  Serial.print(analogSensor3/7);
  Serial.print("%");
  //UV-RAY
  Serial.print("      ");
  Serial.print("UV ray: ");
  Serial.print(20);
  
  //SOIL MOISTURE SENSOR
  Serial.print("     ");
  Serial.print("Soil moisture: ");
  Serial.print(sensorValue-412-65+2+2);
  Serial.print("%");
  //Analog light sensor:
  Serial.print("      ");
  Serial.print("Analog light: ");
  Serial.print(light);
  Serial.print("%");
  
  Serial.println();
  delay(100);

  // Checks if it has reached the threshold value
  //if (analogSensor > sensorThres)
  {
//    digitalWrite(redLed, HIGH);
  //  digitalWrite(greenLed, LOW);
    //tone(buzzer, 1000, 200);
  }
  //else
  {
//    digitalWrite(redLed, LOW);
  //  digitalWrite(greenLed, HIGH);
    //noTone(buzzer);
  }
  delay(100);
}
