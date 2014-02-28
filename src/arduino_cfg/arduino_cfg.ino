int block = 0;

void setup() {
  Serial.begin(9600);
}

/** 
* Boucle principale d'évènements
*/
void loop() {
}

/**
*  Callback appellé lors de réception de données sur série
*/
void serialEvent(){
  if(Serial.available() > 0)
  {
    int incoming = Serial.read();
    Serial.print("Recieved : ");
    Serial.write(incoming);
  }
}
