#include "Source.h"
Source::Source(EventScheduler* ev)
{
    setEventScheduler(ev);
    state =  State::IDLE;
}

void Source::crearConnexio(/*Peatge p*/)
{

}
void Source::tractarEsdeveniment(Esdeveniment* esd)
{
    switch(esd->getTipus()){

        case Esdeveniment::Tipus::SIMULATION_START:
            simulationStart();
            break;
        case Esdeveniment::Tipus::NEXT_ARRIVAL:
            processNextArrival(esd);
            break;
    }
}
void Source::simulationStart()
{

}
void Source::processNextArrival(Esdeveniment* esd)
{

}
Esdeveniment* Source::properaArribada(float time)
{

}
