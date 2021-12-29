#include <Oversampling.h>
const double electrode_quotient = .2; // quotient of the distance between the electrodes and the area of the electrodes 
Oversampling adc(10, 15, 2);
void setup() 
{
  Serial.begin(115200); //This code sets up the Serial port at 115200 baud rate
  
}

void loop() //This function loops while the Arduino is powered
{
  // Calculations of voltage and concentration
  double volt = adc.read(0)*(5.0/32767.0); 
  double concVal = pow((50000-10000*volt)/volt,-1)*electrode_quotient;
 
  //Print results w/ units
  Serial.print("\nVoltage: ");
  Serial.print(volt);
  Serial.println(" volts");
  Serial.print("Concentration : ");
  Serial.print(concVal);
  Serial.println(" ppm");
  delay(1000); //Wait for 1 second 
}
