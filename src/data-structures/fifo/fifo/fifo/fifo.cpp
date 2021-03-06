// fifo.cpp : This file contains a First-in-First-out datastructure. 
// In this queue elements added to the end, and taken from the front.
//

#include "pch.h"
#include <iostream>

class Node		// Node of the chained list
{
public:
	int data;		// data, here integer values;
	Node *next;	// next element in the chain
};


class Fifo {

public:
	Fifo();
	~Fifo();
	void push(int);	// adds information to the end
	int pop();		// takes information from the start

private:
	Node * front;	// first element in the queue
	Node * back;	// last element in the queue
};

// the constructor creates an empty queue
Fifo::Fifo() 
{
	front = back = 0;	// empty queue
}

// the destructor deletes every element of the queue
Fifo::~Fifo()
{
	Node * last = back; //saves the last element
	while (front!=back)
	{
		last = back;
		back = back->next; //gets the next element
		delete last; // deletes the last element
	}
}

void Fifo::push(int d)
{
	
	Node *node = new Node;
	
	node->data = d; // writes the data
	node->next = back; // adds the element to the queue
	if (front = back)
		front = node;
	back = node;	// this element is now the end
}

int Fifo::pop() 
{
	int inhalt = 0;
	if (front != back)
	{
		Node *old = front;
		front = front->next;
		inhalt = old->data;
		delete old;
	}
	return inhalt;
}




int main()
{
	Fifo fifo;
	fifo.push(2);
	fifo.push(3);
	fifo.push(4);

	std::cout << fifo.pop() << std::endl;
	std::cout << fifo.pop() << std::endl;
	std::cout << fifo.pop() << std::endl;
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
