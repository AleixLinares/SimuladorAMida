#include <iostream>

#include "EventScheduler.h"

using namespace std;
int main(int argc, char * argv[])
{
	EventScheduler ev = EventScheduler();
	ev.run();
}
//Event List functions
//Funci� principal
void EventScheduler::run()
{
    configurarModel();
	while(llargariaCua()>0 && currentTime<tempsMaximExecucio)
	{
	    Esdeveniment* current = donamEsdeveniment();
        currentTime = current->getTime();
        current->getObjecte()->tractarEsdeveniment(current);
		cout<<current->getTipus()<<":"<<current->getTime()<<endl;
		delete current;
		std::this_thread::sleep_for(
             std::chrono::milliseconds(1000));
	}
	cout<<getStatistics()<<endl;
}
//Configura el model abans de que el comen�em a fer servir
void EventScheduler::configurarModel()
{/*
    Source* ob = new Source(this);
	Esdeveniment* prova = new Esdeveniment(ob, Esdeveniment::Tipus::SIMULATION_START, currentTime+10);
	afegirEsdeveniment(prova);*/


	//Configuraci� de la source
	Source* source = new Source(this);
	float centreTempsEntreArribades, desviacioEntreArribades;
	cout<<"indica la mitjana de la distribuci� normal del temps entre arribades: "<<endl;
	cin>>centreTempsEntreArribades;
	cout<<"indica la desviaci� de la distribuci� normal del temps entre arribades: "<<endl;
	cin>>desviacioEntreArribades;
    source->setDistribution(centreTempsEntreArribades, desviacioEntreArribades);
    Esdeveniment* prova = new Esdeveniment(source, Esdeveniment::Tipus::SIMULATION_START, currentTime);
    afegirEsdeveniment(prova);

    //Configuracio de la cua
    Queue* cua = new Queue(this);
    source->crearConnexio(cua);
    cua->crearConnexio(source);
    //Configuraci� dels peatges
	float centreTempsProcessament, desviacioTempsProcessament;
	cout<<"indica la mitjana de la distribuci� normal del temps de processament: "<<endl;
	cin>>centreTempsProcessament;
	cout<<"indica la desviaci� de la distribuci� normal del temps de processament: "<<endl;
	cin>>desviacioTempsProcessament;

	int numPeatges;
	cout<<"indica el nombre de peatges"<<endl;
	cin>>numPeatges;

    for(int i = 0; i<numPeatges; i++)
    {
        Peatge* peatge = new Peatge(this);
        peatge->setDistribution(centreTempsProcessament, desviacioTempsProcessament);
        cua->crearConnexio(peatge);
    }

    float tempsMaximExecucioAux;
    cout<<"indica el temps maxim d'execucio (-1 �s infinit)"<<endl;
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
    Esdeveniment* aux = eventList.front();
    eventList.pop();
    return aux;
}
int EventScheduler::getStatistics()
{
	return currentTime;
}
