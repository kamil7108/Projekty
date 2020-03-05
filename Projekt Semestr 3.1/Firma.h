#pragma once
#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>
#include "Lista_pracownikow.h"
#include "Lista_administratorow.h"
/**
Klasa firma odpowiada rzeczywistemu obiektowi firma. 
*/
class Firma
{
	friend class Logowanie;
protected:
	std::string link;
	std::string nazwa;
	Listapracownikow * Pracownicy;
	Lista_administratorow * Administratorzy;

public:
	
	Firma(std::string dopliku) : link(dopliku), nazwa("pusta") {
		Pracownicy = new Listapracownikow;
		Administratorzy = new Lista_administratorow;
	}
	Firma() :link(), nazwa(){
		Pracownicy = new Listapracownikow;
		Administratorzy = new Lista_administratorow;
	}
	/**
	Metoda czyta plik firmy i tworzy listy pracownikow oraz administratorow.
	@param link do pliku firmy
	*/
	void czytajplikfirmy(std::string);
	/**
	Metoda sprawdza czy linki do baz danych maja poprawny format.
	*/
	bool sprawdzlinie(std::string napis);
	/**
	Sprawdzenie czy dany link odpowiada za link do bazy danych administratora czy zwyklego pracownika.
	@param link
	*/
	bool sprawdzczyadministrator(std::string link);
	/**
	Destruktro wirtualny.
	*/
	virtual ~Firma() {
		while (Pracownicy != nullptr)
		{
			delete Pracownicy;
			Pracownicy = nullptr;
		}
		while (Administratorzy != nullptr) {
			delete Administratorzy;
			Administratorzy = nullptr;
		}
	}
	
};


