#include <iostream>

#include "EventScheduler.h"

using namespace std;
int main(int argc, char * argv[])
{
	EventScheduler ev = EventScheduler();
	Esdeveniment prova = Esdeveniment();
	ev.afegirEsdeveniment(prova);
	cout<<ev.tractarEsdeveniment().time<<endl;
}


//Event List functions
void EventScheduler::afegirEsdeveniment(Esdeveniment aux)
{
	eventList.push(aux);
}
Esdeveniment EventScheduler::tractarEsdeveniment()
{
	return eventList.front();
}
