#include "../includeEveryThing.h"
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
    Esdeveniment* nou = properaArribada(0);
    eventScheduler->afegirEsdeveniment(nou);
}
void Source::processNextArrival(Esdeveniment* esd)
{
    Entitat* ent = new Entitat();
    //Passar pel peatge
}
Esdeveniment* Source::properaArribada(float time)
{
    float tempsEntreArribades = 5.0f;
    entitatsCreades++;
    state = State::WORKING;
    return new Esdeveniment(this, Esdeveniment::Tipus::NEXT_ARRIVAL , time+tempsEntreArribades);
}
