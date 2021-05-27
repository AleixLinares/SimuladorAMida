#include "../includeEveryThing.h"

Queue::Queue(EventScheduler* ev)
{
    setEventScheduler(ev);
    state =  State::EMPTY;
}

void Queue::crearConnexio(Source* s)
{
    source = s;
}
void Queue::crearConnexio(Peatge* p)
{
    peatges.push_back(p);
}
void Queue::tractarEsdeveniment(Esdeveniment* esd)
{
    cout<<"tractant esdeveniment queue"<<endl;
    switch(esd->getTipus()){
        case Esdeveniment::Tipus::SIMULATION_START:
            simulationStart();
            break;
    }
}
void Queue::simulationStart()
{
    state =  State::EMPTY;
}
void Queue::recullEntitat(float time, Entitat* et)
{
    //Intentem enviar l'entitat per algun peatge
    list<Peatge*>::const_iterator it = peatges.begin();
    while(it != peatges.end() && (*it)->state != Peatge::State::IDLE) ++it;
    if(it != peatges.end())
    {
        cout<<"Entitat enviada al peatge a la cua"<<endl;
        (*it)->recullEntitat(et);
    }
    else
    {
        cout<<"Entitat recollida a la cua"<<endl;
        cua.push(et);
    }
    if(cua.size() != 0) state =  State::NO_EMPTY;
    else state =  State::EMPTY;
}
Entitat* Queue::alliberaEntitat(float time)
{
    cout<<"Entitat alliberada de la cua"<<endl;
    if(cua.size()>=1)
    {
        Entitat* aux = cua.front();
        cua.pop();
        if(cua.size() == 0) state =  State::NO_EMPTY;
        return aux;
    }
    return nullptr;
}
int Queue::getSize()
{
    return cua.size();
}
