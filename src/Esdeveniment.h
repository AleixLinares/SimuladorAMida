#ifndef ESDEVENIMENT_H_
#define ESDEVENIMENT_H_


#include "forwardDeclarations.h"
using namespace std;
class Esdeveniment{
	public:
		enum Tipus { SIMULATION_START, NEXT_ARRIVAL, PROCESS, DELETE, END_SERVICE};
		Esdeveniment(Object* ob, Tipus tipus, float temps);
		float getTime();
		Tipus getTipus();
		Object* getObjecte();
	private:
		Object* objecte;
		Tipus tipus;
		float time;
};
#endif

