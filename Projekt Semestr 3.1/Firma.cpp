#include "Firma.h"

void Firma::czytajplikfirmy(std::string link) {
	std::string linia;
	std::fstream plik;
	plik.open(link, std::ios::in);
	if (plik.good() == true)
	{
		getline(plik, linia);
		nazwa = linia;
		while (!plik.eof())
		{
	
			getline(plik, linia);
			
			if (sprawdzlinie(linia) == true) {
				if(sprawdzczyadministrator(linia)==true){
					Administratorzy->dodaj_administratora(linia);
				}
				else {
					Pracownicy->dodaj_pracownikow(linia);
				}
				
			}

			
			
		}
		Pracownicy->pokazlistepracownikow();
		Administratorzy->dodaj_podwladnych(this->Pracownicy,this->link);
		plik.close();
	}
}

bool Firma::sprawdzlinie(std::string napis) {
	if (napis.empty() == false) {
		int dlugosc = napis.length();
		if (napis[dlugosc - 1] == 't' && napis[dlugosc - 2] == 'x'&& napis[dlugosc - 3] == 't' && napis[dlugosc - 4] == '.') {
			return true;
		}
		else { return false; }
	}
	else { return false; }
}

bool Firma::sprawdzczyadministrator(std::string link) {
	std::string linia;
	std::fstream plik;
	plik.open(link, std::ios::in);
	if (plik.good() == true)
	{
		getline(plik, linia);
		
		plik.close();
		if (linia == "Administrator") { return true; }
		else { return false; }
	}
	else { return false; }
}
