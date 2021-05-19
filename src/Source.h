#ifndef SOURCE_H_
#define SOURCE_H_
#include "Object.h"
class Source: public Object
{
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
