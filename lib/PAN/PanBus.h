#ifndef DEF_PAN_BUS
#define DEF_PAN_BUS

#include "Arduino.h"

/*
*	Gère la communication sur bus PAN (Paul Area Network)
*	@author Paul Forti
*/
class PanBus
{
public:
	PanBus();
	~PanBus();
private:
	int pinHigh; 	//!< numéro du pin high
	int pinLow;		//!< numéro du pin low
	int pinLock;	//!< numéro du pin de lock (notification de ligne utilisée)
};

#endif // DEF_PAN_BUS