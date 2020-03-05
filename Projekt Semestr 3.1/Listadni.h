#pragma once
#include "Dzien.h"
#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>


/**
Klasa odopiwada za tworzenie listy dni
*/
class Listadni :
	public Dzien
{
	friend class Pracownik;
	friend class Kalendarz;
	friend class Administrator;

	
	protected:
		Listadni * next;
		
	public:
		Listadni() :Dzien(),next(nullptr) {}
		/**
		Metoda dodaje dzien do listy dni 
		@return true ,jesli dzien sie nie potworzyl
		@return false gdy jest juz taki dzien
		*/
		bool dodaj_dzien(int, int, int);
		void wyswietl_liste_dni();
		bool sprawdzdate(int dzien, int miesiac, int rok);
		/**
		Operator doadaje dzien do liste dni
		*/
		Listadni & operator +(Listadni * & tmp);
		/**
		W tej metodzie towrzy sie i wypisuje kaledarz.
		*/
		void wypisz_okres();
		/**
		Metoda tworzy liste dni spelniajacych warunki
		*/
		void wypiszokres(int od_d, int od_m, int od_rok, int do_d, int do_m, int do_rok);
		 ~Listadni(){
			 while (next != nullptr) {
				 delete next;
				 next = nullptr;
			 }
		 }
		Listadni(const Listadni * & tmp) {
			next = tmp -> next;
		}
		Listadni * nastepna() { return this->next; }
};

