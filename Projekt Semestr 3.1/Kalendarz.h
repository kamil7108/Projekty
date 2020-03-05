#pragma once
#include <iostream>
#include <string.h>
#include <string>
#include <iomanip>
#include "Listadni.h"
#include "Lista_administratorow.h"
/**
Klasa kalendarz wypisuje dni pracy z danego okresu w formie kalendarza 
*/
class Kalendarz
{ 
	Listadni * lista;
	const int n [2][13] = { {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
					 {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31} };
	std::string Mc[12] = { "Styczen", "Luty", "Marzec", "Kwiecien", "Maj", "Czerwiec", "Lipiec", "Sierpien", "Wrzesien", "Pazdziernik", "Listopad", "Grudzien" };
	public:
	Kalendarz(Listadni * tmp):lista(tmp){}
	~Kalendarz() {
		if (lista != nullptr) {
			delete lista;
			lista = nullptr;
		}
	 }
	/**
	Metoda sprawdza, czy rok r jest przestepny.
	*/
	bool czy_przestepny(int r);
	/**
	Metoda zwraca liczbe dni miesiaca m roku r.
	*/
	int Ile_dni_ma_miesiac(int m, int r);
	/**
	Metoda oblicza, ktory z kolei dzien w roku przedstawia data d, m, r.
	*/
	int ktory_dzien_w_roku(int d, int m, int r);
	/**
	Metoda oblicza, jaki dzien tygodnia przedstawia data d, m, r.
	*/
	int jaki_dzien_tygodnia(int d, int m, int r);
	/**
	Metoda wypisuje dni pracy danego pracownika w formie kalendarza
	*/
	void  wypisz_miesiac(int m, int r,Listadni * & tmp);
};

