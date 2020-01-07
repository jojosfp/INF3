/*
 * STRATEGY.C
 *
 *  Created on: 07.01.2020
 *      Author: JojoDPC
 */

#include "STRATEGY.H"
#include "SIMPLESOCKET.H"
#include "TASK3.H"
#include "MYTASK_B.H"

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <unistd.h>

using namespace std;

void StrategyOne::strat(){

	srand(time(NULL));
	TCPclient c;
	string host = "localhost";
	string msg;

	// Zwischenspeicher f�r Daten
	fstream data;

	// Treffer, Schusszaehler, Spielzaehler
	int hitcounter, shotcounter, gamecounter=1;
	int x, y;

	// Verbindung zum Host
	c.conn(host , 2021);

	// Boolsche Variable die beschreibt ob ein weiteres Spiel gefordert ist
	bool goOn = 1;

	// Erstellen einer spezifischen Speicherdatei
	data.open("data_stratOne.txt", ios::out);

	// Textfeld der Ausgabedatei
	data << "Anzahl der benoetigten Schuesse zum beenden des Spiels mittels StrategyOne" << endl;
	data << endl << "Benoetigte Schuesse:" << endl << endl;


	while(goOn)
	{
		shotcounter = 0;
		hitcounter = 0;

		x = 1;
		y = 1;

		while(y <= 10)
		{
			while (x <= 10)
			{
				//Koordinaten ausgeben
				msg = "COORD[" + to_string(x) + ";" + to_string(y) + "]";
				
				//Koordinaten an Server senden
				cout << "client:	" << msg << endl;
				c.sendData(msg);

				//Server antwortet, msg wird zur Antwort
				msg = c.receive(24);
				cout << "server:	" << msg << endl;

				//Treffer Zaehler
				if(msg.compare(0,6, "RES[1]") == 0)
				{
					hitcounter++;

					cout << hitcounter << endl;
				}
				else if (msg.compare(0,6, "RES[2]") == 0)
				{
					hitcounter++;

					cout << hitcounter << endl;
				}

				if(msg.compare(0,6, "RES[4]") == 0)
				{
					hitcounter++;

					cout << hitcounter << endl;

					y = 11;

					shotcounter++;

					break;
				}

				//Schuesse werden gezaehlt
				shotcounter++;

				x++;
			}

			y++;
			x = 1;
		}

		//Shotcounter Ausgabe
		cout << endl << "shots needed:   " << shotcounter << endl;

		//Durchgang und Anzahl an Schuesse werden in Datei geschrieben
		data << "Spiel # " << gamecounter << " :   ";
		data << shotcounter << endl;

		//Beenden des Alg. bei 20 Durchgaengen
		if (gamecounter >= 20)
		{
			goOn = 0;
			break;
		}
		else
		{
			//New Game Message
			msg = "NEWGAME";

			//Message wird gesendet
			cout << "client:	" << msg << endl;
			c.sendData(msg);
		}

		//msg wird zur Antwort des Servers
		msg = c.receive(24);
		cout << "server:	" << msg << endl;

		//Neuer Durchgang
		gamecounter++;
	}

	//Datei wird geschlossen
	data.close();

	cout << "Erfolgreich gespeichert" << endl;

	cout << "client says: ";
	c.sendData("BYEBYE");

}
