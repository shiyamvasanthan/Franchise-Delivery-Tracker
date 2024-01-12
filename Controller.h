
#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <iostream>
#include <string>
#include "Pierres.h"
#include "View.h"

using namespace std;

class Controller {
		
	public:
		
		void launch();

	
	private:
		void initPierres();
		void takeOrder();
		void driverPickup();
		void driverDeliver();
		
		Pierres pierres;
		View view;

};
#endif