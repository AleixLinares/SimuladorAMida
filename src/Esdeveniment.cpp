#include "Esdeveniment.h"
#include "./includeEveryThing.h"
Esdeveniment::Esdeveniment(Object* ob, Tipus tipus, float temps)
{
	time = temps;
	objecte = ob;
	this->tipus = tipus;
}
float Esdeveniment::getTime(){ return time;}
Esdeveniment::Tipus Esdeveniment::getTipus(){return tipus;}
Object* Esdeveniment::getObjecte(){return objecte;}

bool CompareEsdeveniment::operator()(Esdeveniment* lhs, Esdeveniment* rhs) const
    {
        float lhst = lhs->getTime();
        float rhst = rhs->getTime();
        return lhst>rhst;
    }
