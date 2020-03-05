#pragma once
#include <iostream>
#include <random> 
#include <algorithm> 
#include <cstdlib>
#include <stdlib.h>
#include <string>
/**
Klasa haslo tworzy skomplikowane haslo.
*/
class Haslo
{
public:
	Haslo();
	~Haslo();


	Haslo(int len, int amt, bool smA, bool lgA, bool sym);

	
	std::string nowehaslo(bool outMeta);
	void pokazefekt();

protected:
	int dlugosc;
	int ilosc;
	bool malelitery;
	bool duzelitery;
	bool symbole;

};


