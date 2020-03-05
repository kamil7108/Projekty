#pragma once
#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <windows.h>
#include <winbase.h>
#include "Listadni.h"
/**
Klasa jest rzeczywistym obiektem praconika .
*/
class Pracownik
{
	
	
	
   protected:
	   std::string haslo;
	   std::string login;
	   std::string imie;
	   std::string nazwisko;
	   std::string stanowisko;
	   std::string link;
	   Listadni * lista;
       public:
		   Pracownik(std::string h, std::string l, std::string i, std::string n, std::string s,std::string li) :haslo(h), login(l), imie(i), nazwisko(n), stanowisko(s),link(li) {
			   lista = new Listadni;
		
		   }
		   Pracownik(std::string sciezka) :haslo("Puste"), login("Puste"), imie("Puste"), nazwisko("Puste"), stanowisko("Puste"), link(sciezka) { lista = new Listadni;  }
		   Pracownik() :haslo("Puste"), login("Puste"), imie("Puste"), nazwisko("Puste"), stanowisko("Puste"), link() { lista = new Listadni; }
		   /**
		   Metoda rejstruje przybycie do pracy w danym dni
		   */
		   void zamelduj_w_pracy();
		   /**
		   Wpisuje dzien do bazy danych pracownika
		   */
		   void wpisz_do_bazy( const Dzien * data);
		   void wyswietl_pracownika();
		
			void sprawdzokres (int od_d, int od_m, int od_rok, int do_d, int do_m, int do_rok);
			/**
			Metoda zwraca liste dni spelniajacych warunki
			@return wskaznik na liste dni
			*/
			Listadni * dnipracy(int od_d, int od_m, int od_rok, int do_d, int do_m, int do_rok);
			/**
			Tworzy plik nowego pracownika
			*/
			void stworzplikpracownika();
			virtual ~Pracownik() {
				while (lista != nullptr) {
					delete lista;
					lista = nullptr;
				}
			}
};

