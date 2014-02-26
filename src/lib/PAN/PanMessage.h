#ifndef DEF_PAN_MESSAGE
#define DEF_PAN_MESSAGE

#include "Arduino.h"

/**
*	Représente un message envoyé sur le bus PAN
*/
class PanMessage
{
public:
	PanMessage();
	PanMessage(const char* data);
	~PanMessage();
	
};
#endif // DEF_PAN_MESSAGE