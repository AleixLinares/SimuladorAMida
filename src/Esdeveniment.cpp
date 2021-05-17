#include "Esdeveniment.h"
Esdeveniment::Esdeveniment(Object* ob, Tipus tipus, float temps)
{
	time = temps;
	objecte = ob;
	this->tipus = tipus;
}
void Esdeveniment::tractarEsdeveniment()
{
	objecte->tractarEsdeveniment(this);
}
float Esdeveniment::getTime(){ return time;}
