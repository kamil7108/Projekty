#pragma once
#include "Administrator.h"
#include "Pracownik.h"
#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>
/**
Klasa spelnia obiekt listy administratorow
*/
class Lista_administratorow :
	public Administrator
{
protected:
	Lista_administratorow * next;
public:
	Lista_administratorow() : next(nullptr),Administrator() {}
	/**
	Czyta plik administratora .
	@param link do bazy danych administratora
	*/
	void czytajplikpracownikow(std::string sciezka);
	/**
	Medota dodaje administratora do listy administratorow.
	@param sciezka
	*/
	void dodaj_administratora(std::string sciezka);
	/**
	Sprawadza czy napis spelnia format linku do pliku.
	@param napis
	*/
	bool sprawdzlinie(std::string linia);
	void pokazlisteadministratorow();
	/**
	Uzupelnia dane pracownika o o dane i dni pracy
	@param linia ,link do bazy danych
	*/
	void uzupelnijdanepracownicze(std::string linia);
	/**
	Metoda znajduje administratora po loginie i hasle w liscie administratorow.
	@return wskaznik na obiekt administrator
	*/
	Administrator * znajdz_pracownika(std::string login, std::string haslo);
	/**
	Sprawdz czy jest taki dzien w roku.*/
	bool sprawdzdate(int dzien, int miesiac, int rok);
	/**
	Metoda dodaje wskaznik na liste pracownikow firmy  do administratora.
	*/
	void dodaj_podwladnych(Listapracownikow * tmp, std::string link_f);
	 ~Lista_administratorow() {
		 while(next != nullptr) {
			 next->pokazlisteadministratorow();
			 delete next;
			 next = nullptr;
		 }

	 }
	
};

