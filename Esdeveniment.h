#ifndef ESDEVENIMENT_H_
#define ESDEVENIMENT_H_

#include <string>
#include <queue>
using namespace std;
class Esdeveniment{
	public:
		enum Tipus { SIMULATION_START, NEXT_ARRIVAL, PROCESS, DELETE};
		float time;
		EventScheduler();
};
#endif

