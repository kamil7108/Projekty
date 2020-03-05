#include "Lista_administratorow.h"

void Lista_administratorow::czytajplikpracownikow(std::string sciezka) {

	std::string linia;
	std::fstream plik;

	plik.open(sciezka, std::ios::in);
	if (plik.good() == true)
	{
		while (!plik.eof())
		{
			getline(plik, linia);
			if (sprawdzlinie(linia) == true) {
				dodaj_administratora(linia);
			}
		}
		plik.close();
	}
}

/*
Funkcja tworzy listê pracowników danej firmy
@param sciezka , link do pliku pracownika
*/
void Lista_administratorow::dodaj_administratora(std::string sciezka) {
	
	if (this->Pracownik::link.empty()==true) {
		
		link = sciezka;	
		std::cout << link;
		
		this->uzupelnijdanepracownicze(link);
	
	}
	else {
		std::cout << "a";
		Lista_administratorow * tmp = this;
		while (tmp->next != nullptr) {
			tmp = tmp->next;
		}
		//std::cout << "a";
		tmp->next = new Lista_administratorow;
		tmp->next->link = sciezka;
		tmp->next->uzupelnijdanepracownicze(tmp->next->link);

	}
}
/*
Funkcja sprawdza linie wczytana z pliku
@param napis ,linia wczytana z pliku
@return true ,gdy w pobranej lini 4 ostatnie znaki to .txt
*/
bool Lista_administratorow::sprawdzlinie(std::string napis) {
	if (napis.empty() == false) {
		int dlugosc = napis.length();
		if (napis[dlugosc - 1] == 't' && napis[dlugosc - 2] == 'x'&& napis[dlugosc - 3] == 't' && napis[dlugosc - 4] == '.') {
			return true;
		}
		else { return false; }
	}
	else { return false; }
}

void Lista_administratorow::pokazlisteadministratorow() {
	Lista_administratorow * tmp = this;
	while (tmp != nullptr) {
		tmp->wyswietl_administratora();
		tmp = tmp->next;
	}
}
/*
Funkcja uzupe³nia dane pracowników
@param nazwa linker do pliku ,w którym zapisane s¹ dane pracownika
*/
void Lista_administratorow::uzupelnijdanepracownicze(std::string nazwa) {
	std::string linia;
	std::fstream plik;
	int dzien = 0;
	int miesiac = 0;
	int rok = 0;
	int i = 0;
	char znak;
	plik.open(nazwa, std::ios::in);
	if (plik.good() == true)
	{
		getline(plik, linia);
		stanowisko = linia;
		getline(plik, linia);
		imie = linia;
		getline(plik, linia);
		nazwisko = linia;
		getline(plik, linia);
		login = linia;
		getline(plik, linia);
		haslo = linia;

		while (!plik.eof())
		{
			plik >> dzien >> znak >> miesiac >> znak >> rok;
			if (sprawdzdate(dzien, miesiac, rok) == true) {

				this->lista->dodaj_dzien(dzien, miesiac, rok);
			}
		}
		plik.close();
	}
}
Administrator * Lista_administratorow::znajdz_pracownika(std::string login, std::string haslo) {
	if (this != nullptr) {
		Lista_administratorow * tmp = this;

		while (tmp->login != login && tmp->next != nullptr&& tmp->haslo != haslo) {
			tmp = tmp->next;
		}
		if (tmp->login == login && tmp->haslo == haslo) {
		std::cout << "Znalazlem" << std::endl;
			return tmp;
		}
		else {
			std::cout << "Nie ma takiego pracownika." << std::endl;
			return nullptr;
		}
	}
	else {
		return nullptr;
	}
}
/*
Funkcja sprawdza czy taka data istnieje
@param dzien
@param miesiac
@param rok
retrun true ,gdy data jest dobra
*/

bool Lista_administratorow::sprawdzdate(int dzien, int miesiac, int rok) {
	if (rok % 4 == 0) {
		if (miesiac == 2) {
			if (dzien < 30) { return true; }
			else { return false; }
		}

		else if (miesiac == 4 || miesiac == 6 || miesiac == 9 || miesiac == 11) {
			if (dzien < 31) { return true; }
			else { return false; }
		}
		else if (miesiac < 13) {
			if (dzien < 32) { return true; }
			else { return false; }

		}
		else { return false; }
	}
	else {
		if (miesiac == 2) {
			if (dzien < 29) { return true; }
			else { return false; }
		}

		else if (miesiac == 4 || miesiac == 6 || miesiac == 9 || miesiac == 11) {
			if (dzien < 31) { return true; }
			else { return false; }
		}
		else if (miesiac < 13) {
			if (dzien < 32) { return true; }
			else { return false; }

		}
		else { return false; }

	}
}
void Lista_administratorow::dodaj_podwladnych(Listapracownikow * tmp,std::string link_f) {
	Lista_administratorow * obj = this;
	while (obj != nullptr) {
		obj->listapracownikow = tmp;
		obj->link_firmy = link_f;
		obj = obj->next;
	}
}
