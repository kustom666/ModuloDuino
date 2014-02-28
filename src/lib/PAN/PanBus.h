#ifndef DEF_PAN_BUS
#define DEF_PAN_BUS

#include "Arduino.h"
#include "PanMessage.h"

/**
*	Gère la communication sur bus PAN (Paul Area Network)
*	@author Paul Forti
*/
class PanBus
{
public:
	PanBus(int pinHigh = 8, int pinLow = 7, int pinLock = 4);
	~PanBus();

	// Getters et setters
	int getPinHigh();
	int getPinLow();
	int getPinLock();

	void setPinHigh(int pinHigh);
	void setPinLow(int pinLow);
	void setPinLock(int pinLock);
	QAction *actionOpen;
	

private:
	int pinHigh; 	//!< numéro du pin high
	int pinLow;		//!< numéro du pin low
	int pinLock;	//!< numéro du pin de lock (notification de ligne utilisée)
};

#endif // DEF_PAN_BUS