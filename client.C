/*
 * client.C
 *
 *  Created on: 11.09.2019
 *      Author: aml
 */

#include <string>
#include <iostream>
#include <unistd.h> //contains various constants

#include "STRATEGY.H"
#include "SIMPLESOCKET.H"

using namespace std;

int main() {

	StrategyOne tryMeHarder;
	tryMeHarder.strat();

	//StrategyTwo tryALittle;
	//tryALittle.strat();

}


