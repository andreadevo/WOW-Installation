#include <SparkFun_CAP1203_Registers.h>
#include <SparkFun_CAP1203_Types.h>
#include <Wire.h>

CAP1203 sensor;

unsigned long startTime;          // Time at whick button pressed
unsigned long stopTime = 30000;   // Stop interactions after 30 seconds

void setup() {
  Wire.begin();   // Join I2C bus
  Serial.begin(9600);

  // Setup sensor 
  if (sensor.begin() == false) {
    Serial.println("Not connected");
    while(1);
  } else {
    Serial.println("Connected!");
  }
}

void loop() {
  if (sensor.isLeftTouched() == true) {
    // Left pad connects to CS1 touch pad
    Serial.println("Touched!");

    // Start motion and light interactions
    //startMotor(); 
    //startNeopixels();

    // Turn on interactions for 30 seconds 
    startTime = millis();
    while ((millis() - startTime) < stopTime); 

    // Stop motion and light interactions
    //stopMotor();
    //stopNeopixels();

    delay(1000);
  }
}

/*
void stopMotor() {
  
}

void startNeopixels() {
  
}

void stopMotor() {
  
}

void startNeopixels() {
  
}
*/
