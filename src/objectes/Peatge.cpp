#include "../includeEveryThing.h"
Peatge::Peatge(EventScheduler* ev)
{
    setEventScheduler(ev);
    state =  State::IDLE;
}
void Peatge::crearConnexio(/*Operari o, Peatge p*/)
{

}
void Peatge::setDistribution(float cTP, float dTP)
{
    centreTempsProcessament = cTP;
    desviacioTempsProcessament  = dTP;
}
void Peatge::recullEntitat(Entitat* ent)
{
    entitatActiva = ent;
    state = State::WORKING;
    float tempsProcessament =  mates::getRandomNormalFloat(centreTempsProcessament, desviacioTempsProcessament);
    Esdeveniment* esdevAux = programarFinalServei(tempsProcessament, ent);
    cout<<"PEATGE: nou fi servei programat. t: "<<tempsProcessament<<endl;
    eventScheduler->afegirEsdeveniment(esdevAux);
}
void Peatge::tractarEsdeveniment(Esdeveniment* esd)
{
    switch(esd->getTipus()){

        case Esdeveniment::Tipus::SIMULATION_START:
            simulationStart();
            break;
        case Esdeveniment::Tipus::END_SERVICE:
            processarFiServei(esd);
            break;
    }
}
void Peatge::simulationStart()
{
    state = State::IDLE;
    entitatsProcessades = 0;
}
Esdeveniment* Peatge::programarFinalServei(float time, Entitat* ent)
{
    float tempsServei = 2;
    entitatsProcessades++;
    state = State::WORKING;
    return new Esdeveniment(this, Esdeveniment::Tipus::END_SERVICE, time + tempsServei);
}
void Peatge::processarFiServei(Esdeveniment* esd)
{
    cout<<"PEATGE: servei acabat"<<endl;
    entitatsProcessades++;
    //Mirar de moure les entitats
    state = State::IDLE;
}
