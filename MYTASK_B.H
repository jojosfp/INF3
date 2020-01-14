/*
 * MYTASK_B.H
 *
 *  Created on: 27.11.2019
 *      Author: jojosfp
 */

/**
 * \file	MYTASK_B.H
 *
 * \brief	Contains the definition of the classes for MyTCP/IP server.
 *
 */

#ifndef MYTASK_B_H_
#define MYTASK_B_H_

#include "TASK3.H"
#include "SIMPLESOCKET.H"

/**
 * \class	MyTCPserver
 *
 * \brief	The class defining the of a TCP/IP server.
 *
 */

class MyTCPserver : public TCPserver
{
	public:

		/**
		 *\brief	constructor
		 *
		 *\param 	port int number of the server
		 *
		 *\param	maxDataSizeRecv int maximal size of the messages the server can receive.
		 *
		 */

		MyTCPserver(int port, int maxDataSizeRecv): TCPserver(port, maxDataSizeRecv)
		{
			myWorld = new TASK3::World;
			myWorld->printBoard();
		}

	protected:

		/**
		 * \brief 	Responds to the client with a string containing the response data.
		 *
		 * \param 	string with input to client.
		 *
		 * \return 	string contains the response after receiving data.
		 *
		 */

		virtual string myResponse(string input);

	private:

		TASK3::World *myWorld;
};


#endif /* MYTASK_B_H_ */
