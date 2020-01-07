/*
 * MYTASK_B.H
 *
 *  Created on: 27.11.2019
 *      Author: jojosfp
 */

#ifndef MYTASK_B_H_
#define MYTASK_B_H_

#include "TASK3.H"
#include "SIMPLESOCKET.H"

class MyTCPserver : public TCPserver
{
	public:
		MyTCPserver(int port, int maxDataSizeRecv): TCPserver(port, maxDataSizeRecv)
		{
			myWorld = new TASK3::World;
			myWorld->printBoard();
		}

	protected:
		virtual string myResponse(string input);

	private:
		TASK3::World *myWorld;
};


#endif /* MYTASK_B_H_ */
