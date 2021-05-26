#ifndef OPERARI_H_
#define OPERARI_H_

#include "Entitat.h"
#include "Object.h"
#include <list>

class Operari: public Object
{
    int clientsServits = 0;
    list<Peatge*> peatges;
public:
    enum State { IDLE, WORKING};
    Operari(EventScheduler* ev);
    State state;

    void addPeatge(Peatge* p);
    void tractarEsdeveniment(Esdeveniment* esd);
    void simulationStart();
    /*void processNextArrival(Esdeveniment* esd);
    Esdeveniment* properaArribada(float time);*/
};

#endif // OPERARI_H_
