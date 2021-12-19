import processing.serial.*; //<>// //<>// //<>// //<>// //<>// //<>// //<>// //<>// //<>// //<>// //<>// //<>// //<>// //<>// //<>// //<>// //<>//
import java.text.*;
import java.util.*;
import java.awt.*;
import java.awt.event.*;
import java.io.*;
import javax.swing.*;

PrintWriter output;
DateFormat fnameFormat = new SimpleDateFormat("yyMMdd_HHmm");
DateFormat timeFormat = new SimpleDateFormat("hh:mm:ss:SSS");

String fileName;

Serial mySerial; // creates local variable from serial library
char HEADER = 'H';

/*//Variable transfers from Serial Port
 double temperature; //variable to store calculated temperature
 float voltage; // variable to store detected voltage*/
String myData = null;

//ASCII
int nl = 10;// ASCII code for carage return in serial
float myValue; // float for storing convered ASCII serial data
void setup() {
  
  // link processing to the correct port
  String arduinoLocation = Serial.list() [0];
  mySerial = new Serial(this, arduinoLocation, 115200);
  Date now = new Date();
  fileName = fnameFormat.format(now);
  output = createWriter(fileName + ".csv"); // save the file in the sketch folder
}//setup

void draw() {
  
  
  // check for data and then retrieve it
  while (mySerial.available() > 0) {
    myData = mySerial.readStringUntil(nl);// Retrieves data from serial port
    //If my data there is data on the serial port
    if (myData != null) {
      background(0);
      myValue = float(myData); // takes serial port data and turns it into a number
    }
    if ( mySerial.available() >= 15)  // wait for the entire message to arrive
    {
      if ( mySerial.read() == HEADER) // is this the header
      {
        String timeString = timeFormat.format(new Date());
        println(timeString);
        myValue = mySerial.read();
        output.println(timeString);
        // header found
        // get the integer containing the bit values
        myValue = mySerial.read();
        // print the analog value
        for (int i=0; i < 1; i ++) {
          myValue = mySerial.read();
          println(myValue);
          output.println(myValue);
        }
      }
    }
  }
}//draw

void keyPressed() {
  output.flush(); // Writes the remaining data to the file
  output.close(); // Finishes the file
  exit(); // Stops the program
}