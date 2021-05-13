#include <iostream>

#include "EventScheduler.h"

using namespace std;
int main(int argc, char * argv[])
{
	int maxIters = 10
	EventScheduler ev = EventScheduler();
	Esdeveniment prova = Esdeveniment();
	ev.afegirEsdeveniment(prova);
	while(ev.llargariaCua()>0 && --maxiters>=0)
	{
		cout<<ev.tractarEsdeveniment().time<<endl;
		cout<<maxiters<<endl;
	}
	cout<<ev.getStatistics()<<endl;
}


//Event List functions
void EventScheduler::afegirEsdeveniment(Esdeveniment aux)
{
	eventList.push(aux);
}
Esdeveniment EventScheduler::tractarEsdeveniment()
{
	Esdeveniment aux = eventList.front();
	currentTime += aux.time;
	eventList.pop();
	return aux;
}
int EventScheduler::llargariaCua()
{
	return eventList.size();
}
int EventScheduler::getStatistics()
{
	return currentTime;
}
