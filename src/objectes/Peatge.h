#ifndef PEATGE_H_
#define PEATGE_H_
#include "Entitat.h"
#include "Object.h"
class Peatge: public Object{
        int entitatsProcessades = 0;
    public:
        enum State { IDLE, WORKING};
        Peatge(EventScheduler* ev);
        State state;
        Entitat* entitatActiva;

        void crearConnexio(/*Operari o, Peatge p*/);
        void recullEntitat(Entitat* ent);
        void tractarEsdeveniment(Esdeveniment* esd);
        void simulationStart();
        Esdeveniment* programarFinalServei(int time, Entitat* ent);
        void processarFiServei(Esdeveniment* esd);
};

#endif
