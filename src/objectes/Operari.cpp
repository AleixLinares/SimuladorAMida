#include "Operari.h"
#include "../includeEveryThing.h"
Operari::Operari(EventScheduler* ev)
{
    setEventScheduler(ev);
    state =  State::IDLE;
}
queue<Peatge*> Operari::cuaServei;
void Operari::addPeatge(Peatge* p)
{
    peatges.push_back(p);
}
void Operari::crearConnexio(list<Peatge*> p)
{
    while(!p.empty())
    {
        addPeatge(p.front());
        p.pop_front();
    }
}
void Operari::tractarEsdeveniment(Esdeveniment* esd)
{
    switch(esd->getTipus()){

        case Esdeveniment::Tipus::SIMULATION_START:
            simulationStart();
            break;
        case Esdeveniment::Tipus::NEXT_ARRIVAL:
            //processNextArrival(esd);
        case Esdeveniment::Tipus::END_SERVICE:
            processarFiServei(esd);
            break;
    }
}
void Operari::simulationStart()
{
    state = State::IDLE;
    clientsServits = 0;
}
void Operari::processarFiServei(Esdeveniment* esd)
{
    cout<<"OPERARI "<<id<<": servei acabat"<<endl;
    if(cuaServei.empty())
    {
        state = State::IDLE;
        cout<<"OPERARI "<<id<<": esperant nou servei"<<endl;
    }
    else
    {
        Peatge* p = cuaServei.front();
        cuaServei.pop();
        p->llancarIniciServei(this, esd->getTime());
        cout<<"OPERARI "<<id<<": nou servei trobat"<<endl;
    }
}
bool Operari::iNeedYou(float time)
{
    bool aux = (state == State::IDLE);
    if(aux)
    {
        state = State::BUSY;
        cout<<"OPERARI "<<id<<": operari solicitat. disponible: "<<aux<<endl;
    }
    return aux;
}
void Operari::operariNoTrobat(Peatge* p)
{
    cout<<"Operari no trobat. Guardat a la cua"<<endl;
    cuaServei.push(p);
}
Esdeveniment* Operari::programarFinalServei(float finishTime)
{
    cout<<"OPERARI "<<id<<": nou fi servei programat. finishTime:"<<finishTime<<endl;
    clientsServits++;
    state = State::BUSY;
    return new Esdeveniment(this, Esdeveniment::Tipus::END_SERVICE, finishTime);
}
