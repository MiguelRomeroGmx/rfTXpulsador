#include <VirtualWire.h>

int buttonPin = 8;


void setup()
{
    Serial.begin(9600);	  
    pinMode(buttonPin, INPUT);
    Serial.println("Emisor RF");

    // Se inicializa el RF
    vw_setup(2000); // velocidad: Bits per segundo
    vw_set_tx_pin(2); //Pin 2 como salida para el RF 
}

void loop()
{


 int buttonState = digitalRead(buttonPin);

 if(buttonState == 1){
    
      char dato[1];
      dato[0] = 'a';
      //Enviamos el carácter recibido al RF
      vw_send((uint8_t*)dato,sizeof(dato));
      vw_wait_tx();         
    }
    delay(80);
}