#ifndef ESDEVENIMENT_H_
#define ESDEVENIMENT_H_


#include "Object.h"
using namespace std;
class Esdeveniment{
	public:
		enum Tipus { SIMULATION_START, NEXT_ARRIVAL, PROCESS, DELETE};
		Esdeveniment(Object* ob, Tipus tipus, float temps);
		void tractarEsdeveniment();
		float getTime();
	private:
		Object* objecte;
		Tipus tipus;
		float time;
};
#endif

