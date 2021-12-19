#include <Oversampling.h>

Oversampling adc(10, 16, 2);
void setup() 
{
  Serial.begin(115200); //This code sets up the Serial port at 115200 baud rate
  
}

void loop() //This function loops while the Arduino is powered
{
  // Calculations of voltage and conductance
  double volt = adc.read(0)*(5.0/1023.0); 
  double condVal = pow((50000-10000*volt)/volt,-1)*1e6; 
 
  //Print results w/ units
  Serial.print("\nVoltage: ");
  Serial.print(volt);
  Serial.println(" volts");
  Serial.print("Conductance: ");
  Serial.print(condVal);
  Serial.println(" µS");
  delay(3000); //Wait for 3 seconds 
}