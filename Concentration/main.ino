#include <Oversampling.h>

Oversampling adc(10, 16, 2);
void setup() 
{
  Serial.begin(115200); //This code sets up the Serial port at 115200 baud rate
  
}

void loop() //This function loops while the Arduino is powered
{
  // Calculations of voltage and concentration
  double volt = adc.read(0)*(5.0/65535.0); 
  double concVal = // insert equation connecting volt to concentration
 
  //Print results w/ units
  Serial.print("\nVoltage: ");
  Serial.print(volt);
  Serial.println(" volts");
  Serial.print("Concentration : ");
  Serial.print(concVal);
  Serial.println(" ppm");
  delay(3000); //Wait for 3 seconds 
}
