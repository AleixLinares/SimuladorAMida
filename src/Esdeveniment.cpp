#include "Esdeveniment.h"
Esdeveniment::Esdeveniment(Object* ob, Tipus tipus, int temps)
{
	time = temps;
	objecte = ob;
	this->tipus = tipus;
}
int Esdeveniment::getTime(){ return time;}
Esdeveniment::Tipus Esdeveniment::getTipus(){return tipus;}
