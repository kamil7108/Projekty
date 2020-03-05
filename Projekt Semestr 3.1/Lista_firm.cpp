#include "Lista_firm.h"


void Lista_firm::czytajplik(std::string nazwa) {
	std::string linia;
	std::fstream plik;
	
	plik.open(nazwa, std::ios::in);
	
	if (plik.good() == true)
	{
		getline(plik, linia);
		while (!plik.eof())
		{
			
			getline(plik, linia);
			if ( sprawdzlinie(linia) == true) {
			
			dodaj_firme(linia);
			}
			
		}
		
		
		plik.close();
	}
}

void Lista_firm::dodaj_firme(std::string sciezka) {
	if (link.empty()==0) {
		link = sciezka;
	}
	else {
		Lista_firm * tmp = this;
		while (tmp->nastepna != nullptr) {
			tmp = tmp->nastepna;
		}
		tmp->nastepna = new Lista_firm;
		tmp->nastepna->link = sciezka;
		tmp->nastepna->czytajplikfirmy(sciezka);
	}
}
bool Lista_firm::sprawdzlinie(std::string napis) {
	if (napis.empty() == false) {
		int dlugosc = napis.length();
		if (napis[dlugosc-1] == 't' && napis[dlugosc - 2] == 'x'&& napis[dlugosc - 3] == 't' && napis[dlugosc - 4] =='.') {
			return true;
		}
		else { return false; }
	}
	else { return false ; }
}

Lista_firm * Lista_firm::znajdz_firme (std::string nazwa_firmy) {
	if (this != nullptr) {
		Lista_firm * tmp = this;
		
	while (tmp->nazwa != nazwa_firmy && tmp->nastepna != nullptr) {

		tmp = tmp->nastepna;
	}
	if (tmp->nazwa == nazwa_firmy) {
		std::cout << "Znalazlem" << std::endl;
		return tmp;
	}
	else {
		std::cout << "Nie ma takiej firmy." << std::endl;
		return nullptr;
	}
	}
	else { 
		return nullptr; }
}
void Lista_firm::wyswietl_liste() {
	Lista_firm * tmp = this;
	while (tmp != nullptr) {
		std::cout << tmp->link<<" "<< tmp->nazwa << std::endl;
		tmp = tmp->nastepna;
	}
}

