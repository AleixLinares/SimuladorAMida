#include <iostream>

#include "EventScheduler.h"
#include "./includeEveryThing.h"
using namespace std;
int main(int argc, char * argv[])
{
	EventScheduler ev = EventScheduler();
	ev.run();
}
//Event List functions
//Funció principal
void EventScheduler::run()
{
    configurarModel();
	while(llargariaCua()>0 && currentTime<tempsMaximExecucio)
	{
	    cout<<"TRACTANT NOU ESDEVENIMENT..."<<endl;
	    Esdeveniment* current = donamEsdeveniment();
        currentTime = current->getTime();
        current->getObjecte()->tractarEsdeveniment(current);
		cout<<"Tipus esdeveniment: "<<current->getTipus()<<endl;
		cout<<"Temps esdeveniment finalitzat: "<<current->getTime()<<endl<<endl;
		delete current;
		std::this_thread::sleep_for(
             std::chrono::milliseconds(2500));
	}
	cout<<getStatistics()<<endl;
}
//Configura el model abans de que el començem a fer servir
void EventScheduler::configurarModel()
{/*
    Source* ob = new Source(this);
	Esdeveniment* prova = new Esdeveniment(ob, Esdeveniment::Tipus::SIMULATION_START, currentTime+10);
	afegirEsdeveniment(prova);*/


	//Configuració de la source
	Source* source = new Source(this);
	float centreTempsEntreArribades, desviacioEntreArribades;
	cout<<"indica la mitjana de la distribució normal del temps entre arribades: "<<endl;
	cin>>centreTempsEntreArribades;
	cout<<"indica la desviació de la distribució normal del temps entre arribades: "<<endl;
	cin>>desviacioEntreArribades;
    source->setDistribution(centreTempsEntreArribades, desviacioEntreArribades);
    Esdeveniment* prova = new Esdeveniment(source, Esdeveniment::Tipus::SIMULATION_START, currentTime);
    afegirEsdeveniment(prova);

    //Configuracio de la cua
    Queue* cua = new Queue(this);
    source->crearConnexio(cua);
    cua->crearConnexio(source);
    //Configuració dels peatges
	float centreTempsProcessament, desviacioTempsProcessament;
	cout<<"indica la mitjana de la distribució normal del temps de processament: "<<endl;
	cin>>centreTempsProcessament;
	cout<<"indica la desviació de la distribució normal del temps de processament: "<<endl;
	cin>>desviacioTempsProcessament;

	int numPeatges;
	cout<<"indica el nombre de peatges"<<endl;
	cin>>numPeatges;
    list<Peatge*> peatges;
    for(int i = 0; i<numPeatges; i++)
    {
        Peatge* peatge = new Peatge(this);
        peatge->id = i+1;
        peatge->setDistribution(centreTempsProcessament, desviacioTempsProcessament);
        cua->crearConnexio(peatge);
        peatge->crearConnexio(cua);
        peatges.push_back(peatge);
    }

    int numOperaris;
	cout<<"indica el nombre d'operaris"<<endl;
	cin>>numOperaris;
    list<Operari*> operaris;
    for(int i = 0; i<numOperaris; i++)
    {
        Operari* operari= new Operari(this);
        operari->id = i+1;
        operari->crearConnexio(peatges);
        operaris.push_back(operari);
    }
    std::list<Peatge*>::iterator it;
    for (it = peatges.begin(); it != peatges.end(); ++it)
    {
        (*it)->crearConnexio(operaris);
    }
    float tempsMaximExecucioAux;
    cout<<"indica el temps maxim d'execucio (-1 és infinit)"<<endl;
    cin>>tempsMaximExecucioAux;
    if(tempsMaximExecucioAux == -1) tempsMaximExecucio = INT_MAX;
    else tempsMaximExecucio = tempsMaximExecucioAux;

}
void EventScheduler::afegirEsdeveniment(Esdeveniment* aux)
{
	eventList.push(aux);
}
int EventScheduler::llargariaCua()
{
	return eventList.size();
}
float EventScheduler::getCurrentTime()
{
    return currentTime;
}
Esdeveniment* EventScheduler::donamEsdeveniment()
{
    Esdeveniment* aux = eventList.top();
    eventList.pop();
    return aux;
}
int EventScheduler::getStatistics()
{
	return currentTime;
}
