#ifndef QUEUE_H_
#define QUEUE_H_
#include <queue>
#include <list>
#include "Object.h"
#include "../forwardDeclarations.h"
class Queue: public Object
{
    queue<Entitat*> cua;
    queue<float> entryCurrentTime;
    Source* source;
    list<Peatge*> peatges;
    int entitatsCreuades;
    float totalStayTime, maxStayTime, minStayTime;
    public:
        enum State { EMPTY, NO_EMPTY};
        Queue(EventScheduler* ev);
        State state;
        void crearConnexio(Source* s);
        void crearConnexio(Peatge* p);
        void tractarEsdeveniment(Esdeveniment* esd) override;
        void recullEntitat(float time, Entitat* et);
        void simulationStart();
        void simulationEnd();
        Entitat* alliberaEntitat(float time);
        int getSize();
};

#endif // QUEUE_H_
