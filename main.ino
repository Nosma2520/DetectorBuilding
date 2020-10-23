

void setup() 
{
  Serial.begin(115200); //This code sets up the Serial port at 115200 baud rate
  pinMode(8, OUTPUT); // sets the digital pin 8 as output for Red
  pinMode(10, OUTPUT); // sets the digital pin 10 as output for Green
  pinMode(13, OUTPUT); // sets the digital pin 13 as output for Blue
}

void loop() //This function loops while the Arduino is powered
{
  // Definition of the Variables
  double R = 300; // value for which the Red LED will turn on
  double G = 10; // value for which the Greed LED will turn on
  double B = 200; // value for which the Blue LED will turn on 
  int B_value = 3950; // B coefficient Input actual value
  float NOMINAL_R = 516; // input actual value
  
  
  float val = (1023/analogRead(0))-1; //Read the analog port 0 converts the reading to resistance, and store the value in val
  double volt = (3.3 * 10000) / (10000+ val); // Creates an integer variable for voltage
  double temp =(298.15*B_value)/(B_value+298.15*log((NOMINAL_R+10000)/(val+10000)))-273.15; //Runs the math using B-parameter Equation

  //Prints to the display the temperature and voltage throud the serail port.
  Serial.print("\nTemperature:");
  Serial.print(temp); //Prints the value to the serial port
  Serial.print("°C"); // Units
  Serial.print("\nVoltage: ");
  Serial.print(volt); // Prints the voltage to serial port
  Serial.print(" volts"); // Units 
  Serial.print("\n"); // adds space between measurements
  delay(3000); //Wait 3 seconds before we do it again

  // Condiitionals that control the LEDs.
  if (temp <= R)
  {
    digitalWrite(8, HIGH);
    digitalWrite(10, LOW);
    digitalWrite(13, LOW);
  }
  else if (temp <= G)
  {
    digitalWrite(8, LOW);
    digitalWrite(10, HIGH);
    digitalWrite(13, LOW);
  }
  else
  {
    digitalWrite(8, LOW);
    digitalWrite(10, LOW);
    digitalWrite(13, HIGH);
  }
  
}
