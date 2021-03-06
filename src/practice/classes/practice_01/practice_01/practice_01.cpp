// practice_01.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include "pch.h"
#include <iostream>




class Kiste {

private: //private member variables
	int m_height, m_width, m_depth;

public: // constructor overrides the standard constructor and forces input of the member variables.
	Kiste(int height, int width, int depth) {
		m_height = height;
		m_width = width;
		m_depth = depth;
	}

	// operator overload compares the with values of two Kiste objects
	bool operator<(Kiste vgl)
	{
		return (m_width< vgl.m_width);
	}
};
int main()
{
	Kiste kiste(3,4,5);
	Kiste kiste2(2, 3, 4);

	std::cout << (kiste < kiste2) << (kiste2 < kiste) << std::endl;

}

// Programm ausführen: STRG+F5 oder "Debuggen" > Menü "Ohne Debuggen starten"
// Programm debuggen: F5 oder "Debuggen" > Menü "Debuggen starten"

// Tipps für den Einstieg: 
//   1. Verwenden Sie das Projektmappen-Explorer-Fenster zum Hinzufügen/Verwalten von Dateien.
//   2. Verwenden Sie das Team Explorer-Fenster zum Herstellen einer Verbindung mit der Quellcodeverwaltung.
//   3. Verwenden Sie das Ausgabefenster, um die Buildausgabe und andere Nachrichten anzuzeigen.
//   4. Verwenden Sie das Fenster "Fehlerliste", um Fehler anzuzeigen.
//   5. Wechseln Sie zu "Projekt" > "Neues Element hinzufügen", um neue Codedateien zu erstellen, bzw. zu "Projekt" > "Vorhandenes Element hinzufügen", um dem Projekt vorhandene Codedateien hinzuzufügen.
//   6. Um dieses Projekt später erneut zu öffnen, wechseln Sie zu "Datei" > "Öffnen" > "Projekt", und wählen Sie die SLN-Datei aus.
