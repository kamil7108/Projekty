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
/**
Klasa administrator jest jedna z 2 klas pracownikow w firmie.
Klasa administrator posiada wieksze mozliwosci od klasy pracownik moze drukowac raporty , sprawdzac dni pracy innym pracownikow firmy ,dodawac nowych pracownikow.
*/
class Administrator :public Pracownik
{
	protected:

	std::string link_firmy;
	Listapracownikow * listapracownikow;
public:
	
	Administrator(std::string sciezka) : Pracownik(sciezka) , listapracownikow(nullptr){  }
	Administrator() :Pracownik(),listapracownikow(nullptr){ }
	void wyswietl_administratora();
	/**
	Metoda sluzy do utworzenia nowego pracownika i dodanie go do bazy danych firmy oraz listy pracownikow firmy.
	*/
	void dodajpracownikadofirmy();
	/**
	Metoda tworzy personalny login dla nowego pracownika.
	@param imie 
	@param nazwisko
	@return login
	*/
	std::string stworzlogin(std::string imie, std::string nazwisko);
	/**
	Metoda tworzy personalne haslo dla nowego pracownika
	@return haslo 
	*/
	std::string stworzhaslo();
	/**
	Metoda tworzy personalny link do bazy danych pracownika dla nowego pracownika.
	*/
	std::string stworzlink(std::string login);
	/**
	Metoda dodaje link do bazy danych praconika do bazy danych firmy.
	@param linkp ,link pracownika
	@param linkf ,link firmy
	*/
	void dodajdofirmy(std::string linkp, std::string linkf);
	/**
	Metoda dodaje obiekt do listypraconikow firmy.
	@pram obiekt nowo powstaly pracownik
	*/
	void dodaj_pracownikow_do_firmy(Listapracownikow * obiekt);
	/**
	Metoda drukuje raport wszystkich pracownikow firmy z danego okresu.
	*/
	void drukujraportpracownikow( int od_d, int od_m, int od_r, int do_d, int do_m, int do_r);
	/**
	Virtualny destruktor. */
	virtual ~Administrator() {
	}
	void dodajadministratoradofirmy(std::string linkf,std::string nazwaf);
	void dodajdofirmyadm(std::string linkp, std::string linkf,std::string nazwaf);
};

