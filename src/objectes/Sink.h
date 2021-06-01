#ifndef SINK_H_
#define SINK_H_
#include "Object.h"
#include "../forwardDeclarations.h"
class Sink: public Object
{
    public:
        Sink(EventScheduler* ev);
        int entitatsDestruides = 0;
        void rebreEntitat(Entitat* ent);
        void tractarEsdeveniment(Esdeveniment* esd) override;
        void simulationStart();
        void simulationEnd();
};
#endif
