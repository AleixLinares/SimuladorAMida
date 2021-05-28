#ifndef EVENTSCHEDULER_H_
#define EVENTSCHEDULER_H_

#include <queue>
#include "forwardDeclarations.h"
#include "Esdeveniment.h"
#include <bits/stdc++.h>
using namespace std;
class EventScheduler{
	float currentTime =0;
	float tempsMaximExecucio = FLT_MAX;
	//queue<Esdeveniment*> eventList;
	priority_queue<Esdeveniment*, vector<Esdeveniment*>, CompareEsdeveniment> eventList;
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
