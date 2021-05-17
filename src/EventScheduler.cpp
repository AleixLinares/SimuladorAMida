#include <iostream>

#include "EventScheduler.h"

using namespace std;
int main(int argc, char * argv[])
{

	int maxIters = 10;
	EventScheduler ev = EventScheduler();
	Object* ob = new Object();
	Esdeveniment* prova = new Esdeveniment(ob, Esdeveniment::Tipus::SIMULATION_START, 10);
	ev.afegirEsdeveniment(prova);
	while(ev.llargariaCua()>0 && --maxIters>=0)
	{
		cout<<ev.processaNextEsdeveniment()->getTime()<<endl;
		cout<<maxIters<<endl;
	}
	cout<<ev.getStatistics()<<endl;

}


//Event List functions
void EventScheduler::afegirEsdeveniment(Esdeveniment* aux)
{
	eventList.push(aux);
}
int EventScheduler::llargariaCua()
{
	return eventList.size();
}
Esdeveniment* EventScheduler::processaNextEsdeveniment()
{
    Esdeveniment* aux = eventList.front();
    eventList.pop();
    return aux;
}
int EventScheduler::getStatistics()
{
	return currentTime;
}
