#include "../includeEveryThing.h"
Operari::Operari(EventScheduler* ev)
{
    setEventScheduler(ev);
    state =  State::IDLE;
}

void Operari::addPeatge(Peatge* p)
{
    peatges.push_back(p);
}
void Operari::tractarEsdeveniment(Esdeveniment* esd)
{
    switch(esd->getTipus()){

        case Esdeveniment::Tipus::SIMULATION_START:
            simulationStart();
            break;
        case Esdeveniment::Tipus::NEXT_ARRIVAL:
            //processNextArrival(esd);
            break;
    }
}
void Operari::simulationStart()
{
    state = State::IDLE;
    clientsServits = 0;
}
