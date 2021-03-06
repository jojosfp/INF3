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

	// Schusszaehler, Spielzaehler
	int shotcounter, gamecounter=1;
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

		x = 1;
		y = 1;

		while(y <= 10)
		{
			while (x <= 10)
			{
				// Koordinaten in msg schreiben
				msg = "COORD[" + to_string(x) + "," + to_string(y) + "]";

				// msg (Koordinaten) an Server senden
				cout << "client:	" << msg << endl;
				c.sendData(msg);

				// Server antwortet, msg wird zur Antwort
				msg = c.receive(24);
				cout << "server:	" << msg << endl;

				// Antwort auswerten (RES[4] = GAME-OVER)
				if(msg.compare(0,6, "RES[4]") == 0)
				{
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

		//Shotcounter Ausgabe im Clientenfenster
		cout << endl << "shots needed:   " << shotcounter << endl;

		//Durchgang und Anzahl an Schuesse werden in Datei geschrieben
		data << "Spiel # " << gamecounter << " :   ";
		data << shotcounter << endl;

		// Abbruchkriterium fuer Spieleanzahl
		if (gamecounter >= 100)
		{
			goOn = 0;
			break;
		}
		else
		{
			// Neustart
			msg = "NEWGAME";
			cout << "client:	" << msg << endl;
			c.sendData(msg);
		}

		msg = c.receive(24);
		cout << "server:	" << msg << endl;

		gamecounter++;
	}

	// Schliessen der Datei
	data.close();

	cout << "Erfolgreich gespeichert" << endl;

	// Beenden des Servers
	cout << "client says: ";
	c.sendData("BYEBYE");

}

void StrategyTwo::strat()
{
	srand(time(NULL));
	TCPclient c;
	string host = "localhost";
	string msg;

	// Zwischenspeicher f�r Daten
	fstream data;

	// Schusszaehler, Spielzaehler
	int shotcounter, gamecounter=1;
	int x, y;


	// Verbindung zum Host
	c.conn(host , 2021);

	// Boolsche Variable die beschreibt ob ein weiteres Spiel gefordert ist
	bool goOn = 1;

	// Erstellen einer spezifischen Speicherdatei
	data.open("data_stratTwo.txt", ios::out);

	// Textfeld der Ausgabedatei
	data << "Anzahl der benoetigten Schuesse zum beenden des Spiels mittels StrategyTwo" << endl;
	data << endl << "Benoetigte Schuesse:" << endl << endl;


	while(goOn)
	{
		shotcounter = 0;
		int m[10][10] = {{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0}};

		for (int i=0; i<100; i++)
		{
			x = rand() %10 + 1;
			y = rand() %10 + 1;

			if (m[x-1][y-1]==1)
			{
				i = 0;
			}
			if (m[x-1][y-1] == 0)
			{
				m[x-1][y-1] = 1;
				shotcounter++;

				// Koordinaten in msg schreiben
				msg = "COORD[" + to_string(x) + "," + to_string(y) + "]";

				// msg (Koordinaten) an Server senden
				cout << "client:	" << msg << endl;
				c.sendData(msg);

				// Server antwortet, msg wird zur Antwort
				msg = c.receive(24);
				cout << "server:	" << msg << endl;

				// Antwort auswerten (RES[4] = GAME-OVER)
				if(msg.compare(0,6, "RES[4]") == 0)
				{
					break;
				}
			}
		}

		//Shotcounter Ausgabe im Clientenfenster
		cout << endl << "shots needed:   " << shotcounter << endl;

		//Durchgang und Anzahl an Schuesse werden in Datei geschrieben
		data << "Spiel # " << gamecounter << " :   ";
		data << shotcounter << endl;

		// Abbruchkriterium fuer Spieleanzahl
		if (gamecounter >= 100)
		{
			goOn = 0;
			break;
		}
		else
		{
			// Neustart
			msg = "NEWGAME";
			cout << "client:	" << msg << endl;
			c.sendData(msg);
		}

		msg = c.receive(24);
		cout << "server:	" << msg << endl;

		gamecounter++;
	}

	// Schliessen der Datei
	data.close();

	cout << "Erfolgreich gespeichert" << endl;

	// Beenden des Servers
	cout << "client says: ";
	c.sendData("BYEBYE");
};
