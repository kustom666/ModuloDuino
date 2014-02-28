#include <Servo.h>

Servo roueGauche;
Servo roueDroite;
int zeroDroite;
int zeroGauche;
void setup() {
  // put your setup code here, to run once:
  roueGauche.attach(5);
  roueDroite.attach(3);
  zeroDroite = roueDroite.read();
  zeroGauche = roueGauche.read();
  roueDroite.write(zeroDroite);
  roueGauche.write(zeroGauche);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
}

void serialEvent()
{
  Serial.println("Event serie");
  int lu = Serial.read();
  if(lu == 71) // Roue gauche
  {
    roueDroite.write(0);
    roueGauche.write(180);
  }
  else if(lu == 68) // Roue droite
  {
    roueGauche.write(0);
    roueDroite.write(180);
  }
  else if(lu == 83)
  {
    roueGauche.write(90);
    roueDroite.write(90);
  }
}
