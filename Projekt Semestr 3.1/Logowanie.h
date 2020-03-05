#pragma once
#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>
#include "Lista_pracownikow.h"
#include "Lista_firm.h"
#include "Firma.h"
#include "Zarzadzajacy.h"
class Logowanie
	:public Lista_firm
{
	friend class Zarzadzajacy;
protected:
	Zarzadzajacy * tmp;
public:
	std::string login="";
	std::string haslo="";
	std::string firma="";
	Logowanie(std::string login, std::string haslo, std::string firma) :login(login), haslo(haslo), firma(firma) {tmp = new Zarzadzajacy; }
	Logowanie() { tmp = new Zarzadzajacy; }
	/**
	Metoda sterujaca wszystkimi dzialaniami ,czesc integralna programu.
	*/
	void logowanie();
	/**
	Wypisuje insturkcje dla administratra.
	*/
	void instrukcjaADM();
	/**
		Wypisuje insturkcje dla pracownika.
	*/
	void instrukcjaPRA();
	bool sprawdzdate(int dzien, int miesiac, int rok);
	 ~Logowanie() {
		 while (nastepna != nullptr) {
			 delete nastepna;
			 nastepna = nullptr;
		 }
		 if (tmp != nullptr) {
			 delete tmp;
			 tmp = nullptr;
		 }
	}
	 void stworz_zarzadce(std::string spis,Lista_firm * & lista);
};

