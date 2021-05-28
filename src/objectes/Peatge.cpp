#include "./Peatge.h"
#include "../includeEveryThing.h"
Peatge::Peatge(EventScheduler* ev)
{
    setEventScheduler(ev);
    state =  State::IDLE;
}
void Peatge::crearConnexio(Queue* cua)
{
    this->cua = cua;
}
void Peatge::crearConnexio(list<Operari*> op)
{
    operaris = op;
}
void Peatge::setDistribution(float cTP, float dTP)
{
    centreTempsProcessament = cTP;
    desviacioTempsProcessament  = dTP;
}
void Peatge::recullEntitat(Entitat* ent, float time)
{
    entitatActiva = ent;
    demanarOperari(time);
}
void Peatge::tractarEsdeveniment(Esdeveniment* esd)
{
    cout<<"PEATGE "<<id<<": tractant esdeveniment "<<endl;
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
void Peatge::demanarOperari(float time)
{

    bool trobat = false;
    std::list<Operari*>::iterator it=operaris.begin();
    while(it != operaris.end() && !trobat)
    {
        trobat = (*it)->iNeedYou(time);
        if(!trobat) it++;
    }
    if(trobat)
    {
        llancarIniciServei(*it, time);
    }
    else
    {
        Operari::operariNoTrobat(this);
        state = State::WAITING;
    }
}
void Peatge::llancarIniciServei(Operari* op, float time)
{
    Esdeveniment* esdevAux = programarFinalServei(time);
    //Ens tornara el temps final de l'esdeveniment, ja que li hem passat per referencia.
    eventScheduler->afegirEsdeveniment(esdevAux);
    cout<<op->Operari::id<<endl;
    esdevAux = op->Operari::programarFinalServei(time);
    eventScheduler->afegirEsdeveniment(esdevAux);
}
Esdeveniment* Peatge::programarFinalServei(float &time/*, Entitat* ent*/)
{
    float tempsProcessament =  mates::getRandomNormalFloat(centreTempsProcessament, desviacioTempsProcessament);
    cout<<"PEATGE "<<id<<": nou fi servei programat. t: "<<tempsProcessament<<endl;
    entitatsProcessades++;
    state = State::BUSY;
    time += tempsProcessament;
    return new Esdeveniment(this, Esdeveniment::Tipus::END_SERVICE, time);
}

void Peatge::processarFiServei(Esdeveniment* esd)
{
    cout<<"PEATGE "<<id<<": servei acabat"<<endl;
    entitatsProcessades++;
    //Mirar de moure la entitat a la sink
    delete entitatActiva;

    //Agafem nova entitat de la cua
    entitatActiva = cua->alliberaEntitat(esd->getTime());
    if(entitatActiva != nullptr)
    {
        demanarOperari(esd->getTime());
    }
    else state = State::IDLE;
}
