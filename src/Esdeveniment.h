#ifndef ESDEVENIMENT_H_
#define ESDEVENIMENT_H_


#include "forwardDeclarations.h"
using namespace std;
class Esdeveniment{
	public:
		enum Tipus { SIMULATION_START, NEXT_ARRIVAL, END_SERVICE, SIMULATION_END};
		Esdeveniment(Object* ob, Tipus tipus, float temps);
		float getTime();
		Tipus getTipus();
		Object* getObjecte();

	private:
		Object* objecte;
		Tipus tipus;
		float time;
};
struct CompareEsdeveniment
{
    bool operator()(Esdeveniment* lhs, Esdeveniment* rhs) const;
};
#endif

