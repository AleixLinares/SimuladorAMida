#ifndef EVENTSCHEDULER_H_
#define EVENTSCHEDULER_H_

#include <queue>
#include "./includeEveryThing.h"
#include <bits/stdc++.h>
using namespace std;
class EventScheduler{
	int currentTime =0;
	int tempsMaximExecucio = INT_MAX;
	queue<Esdeveniment*> eventList;
	void configurarModel();
	public:
	    int getCurrentTime();
	    Esdeveniment* donamEsdeveniment();
	    void run();
		void afegirEsdeveniment(Esdeveniment* aux);
		int llargariaCua();
		int getStatistics();
};
#endif
