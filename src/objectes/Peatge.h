#ifndef PEATGE_H_
#define PEATGE_H_
#include "../forwardDeclarations.h"
#include "Object.h"
#include <list>
class Peatge: public Object{
        int entitatsProcessades = 0;
        float centreTempsProcessament = 0, desviacioTempsProcessament  = 0;
        Queue* cua;
        list<Operari*> operaris;
    public:
        int id = 0;
        enum State { IDLE, BUSY, WAITING};
        Peatge(EventScheduler* ev);
        State state;
        Entitat* entitatActiva;

        void crearConnexio(Queue* cua);
        void crearConnexio(list<Operari*> op);
        void setDistribution(float cTP, float dTP);
        void recullEntitat(Entitat* ent, float time);
        void tractarEsdeveniment(Esdeveniment* esd) override;
        void simulationStart();
        void iniciarServei(float time);
        void demanarOperari(float time);
        void llancarIniciServei(Operari* op, float time);
        Esdeveniment* programarFinalServei(float& time/*, Entitat* ent*/);
        void processarFiServei(Esdeveniment* esd);
};

#endif
