#pragma once
#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>
#include <windows.h>
#include <winbase.h>
#include <cstdlib>
#include <stdlib.h>
#include <sstream>
#include <iomanip>
#include <ctime>
#include "Listadni.h"
#include "Pracownik.h"
#include "Haslo.h"
#include"Lista_pracownikow.h"
#include "Lista_administratorow.h"
#include "Administrator.h"
#include "Lista_firm.h"
/**
Klasa z ktorej mozna dodawac firmy
*/
class Zarzadzajacy : public Administrator
{protected:
	Lista_firm * listafirm;
	std::string login;
	std::string haslo;
	std::string linkdospisu;
public:
	Zarzadzajacy() :listafirm(nullptr){}
	~Zarzadzajacy()
	{
	}
	bool sprawdzlinie(std::string );
	void dodaj_zarzadzajacego(std::string link, Lista_firm * & lista);
	void dodaj_firme();
	bool sprawdzczyzarzadzajacy(std::string h, std::string l);
	void dodajfirmedospisu(Lista_firm * tmp);
	

};

