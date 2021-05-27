#ifndef QUEUE_H_
#define QUEUE_H_
#include <queue>
#include <list>
#include "entitat.h"
class Queue: public Object
{
    queue<Entitat*> cua;
    Source* source;
    list<Peatge*> peatges;
    public:
        enum State { EMPTY, NO_EMPTY};
        Queue(EventScheduler* ev);
        State state;
        void crearConnexio(Source* s);
        void crearConnexio(Peatge* p);
        void tractarEsdeveniment(Esdeveniment* esd) override;
        void recullEntitat(float time, Entitat* et);
        void simulationStart();
        Entitat* alliberaEntitat(float time);
        int getSize();
};

#endif // QUEUE_H_
