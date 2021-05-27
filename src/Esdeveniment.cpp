#include "Esdeveniment.h"
Esdeveniment::Esdeveniment(Object* ob, Tipus tipus, float temps)
{
	time = temps;
	objecte = ob;
	this->tipus = tipus;
}
float Esdeveniment::getTime(){ return time;}
Esdeveniment::Tipus Esdeveniment::getTipus(){return tipus;}
Object* Esdeveniment::getObjecte(){return objecte;}
