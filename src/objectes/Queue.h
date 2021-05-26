#ifndef QUEUE_H_
#define QUEUE_H_
#include <queue>
#include "entitat.h"
class Queue: public Object
{
    queue<Entitat*> cua;
    Source* source;
    Peatge* peatge;
    public:
        void crearConnexio(Source* s, Peatge* p);
        void tractarEsdeveniment(Esdeveniment* esd);
        void recullEntitat(int time, Entitat* et);
        Entitat* alliberaEntitat(int time);
        int getSize();
};

#endif // QUEUE_H_
