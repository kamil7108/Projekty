#pragma once
#include "Firma.h"
#include <string>
/**
Klasa towrzy liste firm
*/
class Lista_firm :
	public Firma
{
	friend class Zarzadzajacy;
  protected:
		  Lista_firm * nastepna;
public:
	Lista_firm() :  nastepna(nullptr), Firma() {  }
	Lista_firm(std::string link):nastepna(nullptr),Firma(link){}
/**
Funkcja czyta plik z spisem firm i tworzy liste firm
@param nazwa ,nazwa pliku z dopiskiem .txt gdzie znajduja sie nazwy plikow kazdej z firm
*/
	void czytajplik(std::string nazwa);
/**
Funkcja tworzy liste firm i uzupelni dane kazdej z firm
@param sciezka , nazwa pliku firmy 
*/
	void dodaj_firme(std::string sciezka);
	bool sprawdzlinie(std::string napis);
/**
Funkcja szuka firmy o danej nazwie i zwraca wskaznik na nia
@param nazwa_firmy , nazwa firmy ,ktorej szukamy
@return wskaznik do szukanego obiektu
*/
	Lista_firm * znajdz_firme(std::string nazwa_firmy);
	void wyswietl_liste();
	 ~Lista_firm() {
		 while (nastepna != nullptr) {
			 delete nastepna;
			 nastepna = nullptr;
		}
	}
	Lista_firm * ta() { return this->nastepna;}
	
};

