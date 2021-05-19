#include <iostream>

#include "EventScheduler.h"

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
	while(llargariaCua()>0)
	{
	    Esdeveniment* current = donamEsdeveniment();
        currentTime = current->getTime();
		cout<<current->getTime()<<endl;
		delete current;
	}
	cout<<getStatistics()<<endl;
}
//Configura el model abans de que el començem a fer servir
void EventScheduler::configurarModel()
{
    Source* ob = new Source(this);
	Esdeveniment* prova = new Esdeveniment(ob, Esdeveniment::Tipus::SIMULATION_START, currentTime+10);
	afegirEsdeveniment(prova);
}
void EventScheduler::afegirEsdeveniment(Esdeveniment* aux)
{
	eventList.push(aux);
}
int EventScheduler::llargariaCua()
{
	return eventList.size();
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
