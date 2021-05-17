#ifndef OBJECT_H_
#define OBJECT_H_

#include <string>
#include <queue>
#include "EventScheduler.h"
using namespace std;
class Object{
	private:
		EventScheduler eventScheduler;
	public:
		void setEventScheduler(EventScheduler ev);
		void tractarEsdeveniment(Esdeveniment esd);
};
#endif
