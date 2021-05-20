#ifndef SOURCE_H_
#define SOURCE_H_

#include "Entitat.h"
#include "Object.h"

class Source: public Object
{
    int entitatsCreades = 0;

public:
    enum State { IDLE, WORKING};
    Source(EventScheduler* ev);
    State state;

    void crearConnexio(/*Peatge p*/);
    void tractarEsdeveniment(Esdeveniment* esd);
    void simulationStart();
    void processNextArrival(Esdeveniment* esd);
    Esdeveniment* properaArribada(float time);
};

#endif // SOURCE_H_
