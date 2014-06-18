#include <Servo.h>

Servo bras;
int zeroBras;
char recv[10];
int noRecv;
int nbModules;
int posX;
double angle;
unsigned long backTime;
extern volatile unsigned long timer0_overflow_count;

void setup() {
  // put your setup code here, to run once:
  backTime = 0;
  bras.attach(3);
  bras.write(90);
  nbModules = 0;
  posX = 1;
  Serial1.begin(9600);
  Serial1.write("NEW");
  reset();
  noRecv = 0;
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial1.available() > 0)
  {
    handleSerial();
  }
  unsigned long time = timer0_overflow_count;  
  if((time-backTime) >= 200)
  {
    backTime = time;
    double angle = sin(time + posX);
    int angleDeg = (angle * 4068) / 71;
    bras.write(90+angleDeg);
  }
}

void handleSerial()
{
  char lu = Serial1.read();
  if(noRecv < 2)
  {
    recv[noRecv] = lu;
    noRecv++;
  }
  else
  {
    recv[noRecv] = lu;    
    if(recv[0] == 'R' && recv[1] == 'E' && recv[2] == 'S')
    {
        reset();
    }
    else if(recv[0] == 'N' && recv[1] == 'E' && recv[2] == 'W')
    {
        reset();
        nbModules++;
        Serial1.write("MAJ"); 
        Serial1.write(nbModules);
        
    }
    else if(recv[0] == 'M' && recv[1] == 'A' && recv[2] == 'J')
    {
       char nbModulesRecv = Serial1.read();
       nbModules = nbModulesRecv;
       posX = nbModules;
    }
    noRecv = 0;
  }

}

void reset()
{
  bras.write(90);
  timer0_overflow_count = 0;
}
