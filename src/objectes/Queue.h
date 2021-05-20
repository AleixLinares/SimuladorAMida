#ifndef QUEUE_H_
#define QUEUE_H_
#include <queue>
#include "entitat.h"
class Queue: public Object
{
    queue<Entitat*> cua;
    public:
        void tractarEsdeveniment(Esdeveniment* esd);
        void recullEntitat(float time, Entitat* et);
        Entitat* alliberaEntitat(float time);
        int getSize();
};

#endif // QUEUE_H_
