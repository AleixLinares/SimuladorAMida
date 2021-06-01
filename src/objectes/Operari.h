#ifndef OPERARI_H_
#define OPERARI_H_

#include "Object.h"
#include "../forwardDeclarations.h"
#include <list>
#include <queue>
class Operari: public Object
{
    int clientsServits = 0;
    list<Peatge*> peatges;
    static queue<Peatge*> cuaServei;

public:
    enum State { IDLE, BUSY};
    Operari(EventScheduler* ev);
    State state;
    float timeWorking;
    int id;

    void crearConnexio(list<Peatge*> p);
    void addPeatge(Peatge* p);
    void tractarEsdeveniment(Esdeveniment* esd);
    void simulationStart();
    void simulationEnd(Esdeveniment* esd);
    void processarFiServei(Esdeveniment* esd);
    Esdeveniment* programarFinalServei(float finishTime);
    bool iNeedYou(float time);
    static void operariNoTrobat(Peatge* p);

    /*void processNextArrival(Esdeveniment* esd);
    Esdeveniment* properaArribada(float time);*/
};

#endif // OPERARI_H_
