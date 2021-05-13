#ifndef EVENTSCHEDULER_H_
#define EVENTSCHEDULER_H_

#include <string>
#include <queue>
#include "Esdeveniment.h"
using namespace std;
class EventScheduler{
	float currentTime =0;
	queue<Esdeveniment> eventList;
	public:
		void afegirEsdeveniment(Esdeveniment aux);
		Esdeveniment tractarEsdeveniment();
		int llargariaCua();
		int getStatistics();
};
#endif
