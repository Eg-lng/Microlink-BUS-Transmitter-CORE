// Project : Microlink BUS
// Microlink BUS Transmitter CORE
// Made by eg.lng / Follow me on Instagram @eg.lng , all right reserved, project KATZ systemes 
// PINOUT for arduino nano
// V2.0 / Last modification : 19/10/2025


#include <Arduino.h>

const int DATAOUT = 5; // PIN for the DATA
const int CLKOUT = 6; // PIN for the CLOCK
const int FAULTLED = 8; // PIN for the Fault led
const int TESTCAPTOR = 7; // PIN for an exemple of an captor

void bit1(); 
void bit0();


short int P = 0; // parity bit!!!
short int A = 0; // variable A


double currentTime = 0;
double lastTime = 0;

double getLastTime(){
   return currentTime = millis()- lastTime; // horloge
}



// ENVOIE SUR LE BUS '1'
void bit1()
{
    digitalWrite(DATAOUT,1);
    digitalWrite(CLKOUT,1);
    delayMicroseconds(40); // 40 microsecondes
    digitalWrite(DATAOUT,0);
    digitalWrite(CLKOUT,0);
    delayMicroseconds(40); // 40 microsecondes
    P++;
}
// Envoie sur le Bus 0
void bit0()
{
    digitalWrite(CLKOUT,1);
    delayMicroseconds(40); // 40 microsecondes
    digitalWrite(CLKOUT,0);
    delayMicroseconds(40); // 40 microsecondes
}

void setup(){
    pinMode(DATAOUT,OUTPUT); // pin data 
    pinMode(CLKOUT,OUTPUT); // pin clock 
    pinMode(TESTCAPTOR,INPUT);  // input variable A , just for an example !!
    pinMode(FAULTLED,OUTPUT); // LED de defaut  
}

// if  PIN CLKOUT,DATAOUT is high it's BIT 1 , if PIN CLKOUT is high but PIN DATAOUT LOW it's BIT 0

void loop(){
    lastTime = millis();

    // mettre les capteur ici

    // Exemple : 
    if (digitalRead(TESTCAPTOR) == HIGH ) {
      (A = 1);
    }


    delay((25) - (getLastTime()));
    bit1();
    bit1();
    bit1();
    bit1();
    bit1();
    bit1();
    bit1();
    bit1(); // end Label
    bit1();
    bit0(); // end SDI



   if ( A == 1 ) {
    bit1();
    bit0();
    bit0();
    bit0();
    }
    else{
        bit1();
        bit1();
        bit1();
        bit1();
        digitalWrite(FAULTLED,1);
    }


    bit0();
    bit0();
    bit0();
    bit0();
    bit0();
    bit0();
    bit0();
    bit0();
    bit0();
    bit0();
    bit0();
    bit0();
    bit0();
    bit0();
    bit0(); // end DATA
    bit0(); 
    bit0();  // end SSM

    
    if(P == 1,3,5,7,9,11,13,15,17,19,21,23,25,27,29,31) bit1();
    else bit0();
  
    digitalWrite(FAULTLED,0);

    A = 0;
    P = 0;

}