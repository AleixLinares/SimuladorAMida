#include "../includeEveryThing.h"

void Peatge::crearConnexio(/*Operari o, Peatge p*/)
{

}
void Peatge::recullEntitat(Entitat* ent)
{
    entitatActiva = ent;
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
Esdeveniment* Peatge::programarFinalServei(int time, Entitat* ent)
{
    int tempsServei = 2;
    entitatsProcessades++;
    state = State::WORKING;
    return new Esdeveniment(this, Esdeveniment::Tipus::END_SERVICE, time + tempsServei);
}
void Peatge::processarFiServei(Esdeveniment* esd)
{
    entitatsProcessades++;
    //Mirar de moure les entitats
    state = State::IDLE;
}
