#ifndef EVENTSCHEDULER_H_
#define EVENTSCHEDULER_H_

#include <queue>
#include "Esdeveniment.h"
#include "Object.h"
using namespace std;
class EventScheduler{
	float currentTime =0;
	queue<Esdeveniment*> eventList;
	public:
	    Esdeveniment* processaNextEsdeveniment();
		void afegirEsdeveniment(Esdeveniment* aux);
		int llargariaCua();
		int getStatistics();
};
#endif
