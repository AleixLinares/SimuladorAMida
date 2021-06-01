#ifndef SOURCE_H_
#define SOURCE_H_
#include "Object.h"
#include "../forwardDeclarations.h"
class Source: public Object
{
    int entitatsCreades = 0;
    Queue* cua;
    float centreTempsEntreArribades = 0, desviacioTempsEntreArribades = 0;
public:
    enum State { IDLE, WORKING};
    Source(EventScheduler* ev);
    State state;

    void setDistribution(float cTEA, float dTEA);
    void crearConnexio(Queue* q);
    void tractarEsdeveniment(Esdeveniment* esd) override;
    void simulationStart();
    void simulationEnd();
    void processNextArrival(Esdeveniment* esd);
    Esdeveniment* properaArribada(float time);
};

#endif // SOURCE_H_
