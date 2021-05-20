#include "../includeEveryThing.h"
void Queue::tractarEsdeveniment(Esdeveniment* esd)
{

}
void Queue::recullEntitat(float time, Entitat* et)
{

}
Entitat* Queue::alliberaEntitat(float time)
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
