#ifndef OBJECT_H_
#define OBJECT_H_

#include "../Esdeveniment.h"
#include <iostream>
using namespace std;
class Object{
	protected:
		EventScheduler* eventScheduler;
	public:
		void setEventScheduler(EventScheduler* ev);
		virtual void tractarEsdeveniment(Esdeveniment* esd);
};
#endif
