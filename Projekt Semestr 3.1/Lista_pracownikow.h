#pragma once
#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>
#include "Pracownik.h"
/**
Klasa jest jest lista pracownikow 
*/
class Listapracownikow :
public Pracownik
{
	friend class Administrator;
   protected:
	  Listapracownikow * nastepny;
   public:
	   Listapracownikow() : nastepny(nullptr) { }
	   Listapracownikow(std::string h, std::string l, std::string i, std::string n, std::string s, std::string li) :Pracownik(h, l, i, n, s, li), nastepny(nullptr){}
	   void czytajplikpracownikow(std::string sciezka);
	   /**
	Funkcja tworzy liste pracownikow danej firmy
	@param sciezka , link do pliku pracownika
	*/
	   void dodaj_pracownikow(std::string sciezka);
	   /**
	Funkcja sprawdza linie wczytana z pliku
	@param napis ,linia wczytana z pliku
	@return true ,gdy w pobranej lini 4 ostatnie znaki to .txt
	*/
	   bool sprawdzlinie(std::string linia);
	   void pokazlistepracownikow();
	/**
	Funkcja uzupelnia dane pracownikow
	@param nazwa linker do pliku ,w ktorym zapisane sa dane pracownika
	*/
	   void uzupelnijdanepracownicze(std::string linia);
	   /**
	   Metoda szuka pracownika po loginie i hasle i zwraca wskaznik na obiekt
	   @return wskaznik na obiekt Pracownik
	   */
	   Pracownik * znajdz_pracownika(std::string login,std::string haslo);
	   bool sprawdzdate(int dzien, int miesiac, int rok);
	   /**
	   Metoda szuka pracownika po imieniu i nazwisku i zwraca wskaznik na obiekt.
	   @return wskaznik na obiekt Pracownik
	   */
	   Pracownik * znajdz_pracownika_adm(std::string imie, std::string nazwisko);
	   virtual ~Listapracownikow(){
			while (nastepny != nullptr) {
				 delete nastepny;
				 nastepny = nullptr;
				
		}
		}
		Listapracownikow * nastpna() { return this->nastepny; }

	

		
	
	  

};

