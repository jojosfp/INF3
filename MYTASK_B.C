/*
 * MYTASK_B.C
 *
 *  Created on: 27.11.2019
 *      Author: jojosfp
 */

#include <sstream>
#include <iostream>
#include "MYTASK_B.H"

using namespace std;

/*
 * Shoot results
 *
 * res[0] = "Water"
 * res[1] = "SHIP_HIT"
 * res[2] = "SHIP_DESTROYED"
 * res[3] = "ALL__SHIPS_DESTROYED"
 * res[4] = "GAME_OVER"
 *
 */

string MyTCPserver::myResponse(string input)
{
	std::stringstream ss;

	int x,y;

	TASK3::ShootResult result;

	//

	if(input.compare(0,6,"COORD[") == 0)
	{
		if(2!=sscanf(input.c_str(),"COORD[%d,%d]",&x,&y))
		{
			return string("RES[-1]");
		}

		if(  (x < 1) || (y < 1) || (x > 10) || (y > 10)  )
		{
			return string("RES[-2]");
		}

		cout << "shoot(" << x << "." << y << ")";
		result = myWorld->shoot(x,y);
		ss << "RES[" << result << "]";
		return ss.str();
	};

	if(input.compare(0,7,"NEWGAME")==0)
	{
		delete myWorld;
		myWorld = new TASK3::World;
		myWorld->printBoard();

		return string("NEW GAME CREATED \n");
	};

	return string("UNKNOWN COMMAND");
};


