#ifndef PEATGE_H_
#define PEATGE_H_
#include "Entitat.h"
#include "Object.h"
class Peatge: public Object{
        int entitatsProcessades = 0;
        float centreTempsProcessament = 0, desviacioTempsProcessament  = 0;
    public:
        enum State { IDLE, WORKING, WAITING};
        Peatge(EventScheduler* ev);
        State state;
        Entitat* entitatActiva;

        void crearConnexio(/*Operari o, Peatge p*/);
        void setDistribution(float cTP, float dTP);
        void recullEntitat(Entitat* ent);
        void tractarEsdeveniment(Esdeveniment* esd);
        void simulationStart();
        Esdeveniment* programarFinalServei(float time, Entitat* ent);
        void processarFiServei(Esdeveniment* esd);
};

#endif
