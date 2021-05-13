#ifndef OBJECT_H_
#define OBJECT_H_

#include <string>
#include <queue>
#include "Esdeveniment.cpp"
#include "EventScheduler.cpp"
using namespace std;
class Object{
	private:
	EventScheduler eventScheduler;
	public:
		void setEventScheduler(EventScheduler ev);
		void notificacioEsdeveniment(Esdeveniment esd);
};
#endif
