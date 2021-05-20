#ifndef EVENTSCHEDULER_H_
#define EVENTSCHEDULER_H_

#include <queue>
#include "Esdeveniment.h"
#include "./objectes/Source.h"
#include "./objectes/Peatge.h"
using namespace std;
class EventScheduler{
	float currentTime =0;
	queue<Esdeveniment*> eventList;
	void configurarModel();
	public:
	    Esdeveniment* donamEsdeveniment();
	    void run();
		void afegirEsdeveniment(Esdeveniment* aux);
		int llargariaCua();
		int getStatistics();
};
#endif
