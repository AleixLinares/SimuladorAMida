#include "../includeEveryThing.h"
void Queue::crearConnexio(Source* s, Peatge* p)
{
    source = s;
    peatge = p;
}
void Queue::tractarEsdeveniment(Esdeveniment* esd)
{

}
void Queue::recullEntitat(int time, Entitat* et)
{

}
Entitat* Queue::alliberaEntitat(int time)
{
    if(cua.size()>=1)
    {
        Entitat* aux = cua.front();
        cua.pop();
        return aux;
    }
    return nullptr;
}
int Queue::getSize()
{
    return cua.size();
}
