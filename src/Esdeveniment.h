#ifndef ESDEVENIMENT_H_
#define ESDEVENIMENT_H_


#include "forwardDeclarations.h"
using namespace std;
class Esdeveniment{
	public:
		enum Tipus { SIMULATION_START, NEXT_ARRIVAL, PROCESS, DELETE, END_SERVICE};
		Esdeveniment(Object* ob, Tipus tipus, int temps);
		int getTime();
		Tipus getTipus();
	private:
		Object* objecte;
		Tipus tipus;
		int time;
};
#endif

