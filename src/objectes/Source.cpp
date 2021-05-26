#include "../includeEveryThing.h"
Source::Source(EventScheduler* ev)
{
    setEventScheduler(ev);
    state =  State::IDLE;
}

void Source::crearConnexio(Queue* p)
{
    cua = p;
}
void Source::setDistribution(int cTEA, int dTEA)
{
    centreTempsEntreArribades = cTEA;
    desviacioTempsEntreArribades = dTEA;
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
    Esdeveniment* nou = properaArribada(eventScheduler->getCurrentTime());
    eventScheduler->afegirEsdeveniment(nou);
}
void Source::processNextArrival(Esdeveniment* esd)
{
    Entitat* ent = new Entitat();
    //Passar pel peatge
}
Esdeveniment* Source::properaArribada(int time)
{
    int tempsEntreArribades = 5;
    entitatsCreades++;
    state = State::WORKING;
    return new Esdeveniment(this, Esdeveniment::Tipus::NEXT_ARRIVAL , time+tempsEntreArribades);
}
