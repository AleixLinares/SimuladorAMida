#ifndef OBJECT_H_
#define OBJECT_H_

#include "Esdeveniment.h"
using namespace std;
class Object{
	private:
		EventScheduler* eventScheduler;
	public:
		void setEventScheduler(EventScheduler* ev);
		void tractarEsdeveniment(Esdeveniment* esd);
};
#endif
