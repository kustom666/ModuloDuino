#include "PanBus.h"

/**
* Constructeur du gestionnaire de bus PAN
* @param[in] pinHigh le numéro du pin correspondant à l'état haut du bus
* @param[in] pinLow le numéro du pin correspondant à l'étatt bas du bus
* @param[in] pinLock le numéro du pin correspondant au fil de réserve du bus
* @author Paul Forti
*/
PanBus::PanBus(int pinHigh = 8, int pinLow = 7, int pinLock = 4)
{
	this->pinHigh = pinHigh;
	this->pinLow = pinLow;
	this->pinLock = pinLock;

	// On lit sur le pin low et écrit sur le pin high
	pinMode(pinHigh, OUTPUT);
	pinMode(pinLow, INPUT);

	// Pour le pin lock, on le met en input, toujours le lire avant de l'écrire
	pinMode(pinLock, INPUT);
}

/**
* Destructeur du gestionnaire de bus PAN
*/
PanBus::~PanBus()
{

}

int getPinHigh()
{
	return pinHigh;
}

int getPinLow()
{
	return pinLow;
}
int getPinLock()
{
	return pinLock;
}

void setPinHigh(int pinHigh)
{
	this->pinHigh = pinHigh;
	pinMode(pinHigh, OUTPUT);
}

void setPinLow(int pinLow)
{
	this->pinLow = pinLow;
	pinMode(pinLow, INPUT);
}	

void setPinLock(int pinLock)
{
	this->pinLock = pinLock;
	pinMode(pinLock, INPUT);
}