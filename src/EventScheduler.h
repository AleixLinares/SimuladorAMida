#ifndef EVENTSCHEDULER_H_
#define EVENTSCHEDULER_H_

#include <queue>
#include "./includeEveryThing.h"
#include <bits/stdc++.h>
using namespace std;
class EventScheduler{
	float currentTime =0;
	float tempsMaximExecucio = FLT_MAX;
	queue<Esdeveniment*> eventList;
	void configurarModel();
	public:
	    float getCurrentTime();
	    Esdeveniment* donamEsdeveniment();
	    void run();
		void afegirEsdeveniment(Esdeveniment* aux);
		int llargariaCua();
		int getStatistics();
};
#endif
