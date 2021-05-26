#ifndef SOURCE_H_
#define SOURCE_H_

#include "../includeEveryThing.h"
class Source: public Object
{
    int entitatsCreades = 0;
    Queue* cua;
    int centreTempsEntreArribades = 0, desviacioTempsEntreArribades = 0;
public:
    enum State { IDLE, WORKING};
    Source(EventScheduler* ev);
    State state;

    void setDistribution(int cTEA, int dTEA);
    void crearConnexio(Queue* q);
    void tractarEsdeveniment(Esdeveniment* esd);
    void simulationStart();
    void processNextArrival(Esdeveniment* esd);
    Esdeveniment* properaArribada(int time);
};

#endif // SOURCE_H_
