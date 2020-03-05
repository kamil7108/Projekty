#include "Lista_pracownikow.h"

void Listapracownikow::czytajplikpracownikow(std::string sciezka){
	
		std::string linia;
		std::fstream plik;

		plik.open(sciezka, std::ios::in);
		if (plik.good() == true)
		{
            while (!plik.eof())
			{
				getline(plik, linia);
				if (sprawdzlinie(linia) == true) {
					
						dodaj_pracownikow(linia);
					
				}
			}
			plik.close();
		}
	}


void Listapracownikow::dodaj_pracownikow(std::string sciezka) {
	if (link.empty() == 1) {
		link = sciezka;
		this->uzupelnijdanepracownicze(link);
	
	}
	else {
		Listapracownikow * tmp = this;
		while (tmp->nastepny != nullptr) {
			tmp = tmp->nastepny;
		}
		tmp->nastepny = new Listapracownikow;
		tmp->nastepny->Pracownik::link = sciezka;
		tmp->nastepny->uzupelnijdanepracownicze(tmp->nastepny->link);
		
	}
}


bool Listapracownikow::sprawdzlinie(std::string napis) {
	if (napis.empty() == false) {
		int dlugosc = napis.length();
		if (napis[dlugosc - 1] == 't' && napis[dlugosc - 2] == 'x'&& napis[dlugosc - 3] == 't' && napis[dlugosc - 4] == '.') {
			return true;
		}
		else { return false; }
	}
	else { return false; }
}

void Listapracownikow::pokazlistepracownikow() {
	Listapracownikow * tmp = this;
	while (tmp != nullptr) {
		tmp->wyswietl_pracownika();
		tmp = tmp->nastepny;
	}
}

void Listapracownikow::uzupelnijdanepracownicze(std::string nazwa) {
	std::string linia;
	std::fstream plik;
	int dzien=0;
	int miesiac=0;
	int rok=0;
	int i = 0;
	char znak;
	plik.open(nazwa, std::ios::in);
	if (plik.good() == true)
	{	getline(plik, linia);
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
			if (sprawdzdate(dzien, miesiac, rok)==true) {
	
				this->lista->dodaj_dzien(dzien, miesiac, rok);
			}
		}
		plik.close();
	}
}

Pracownik * Listapracownikow::znajdz_pracownika(std::string login, std::string haslo) {
	if (this != nullptr) {
		Listapracownikow * tmp = this;
		while (tmp->login != login && tmp->nastepny != nullptr&& tmp->haslo != haslo) {
			tmp = tmp->nastepny;
		}
		if (tmp->login == login && tmp->haslo == haslo) {
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
Pracownik * Listapracownikow::znajdz_pracownika_adm(std::string imie, std::string nazwisko) {
	if (this != nullptr) {
		Listapracownikow * tmp = this;

		while (tmp->imie != imie && tmp->nastepny != nullptr&& tmp->nazwisko != nazwisko) {
			//	std::cout << tmp->nazwa << tmp->link << std::endl;
			tmp = tmp->nastepny;
		}
		if (tmp->imie == imie && tmp->nazwisko == nazwisko) {
			//std::cout << tmp->nazwa << tmp->link<< std::endl;;
			std::cout << "Znalazlem" << std::endl;
			tmp->wyswietl_pracownika();
			//	tmp->lista->wyswietl_liste_dni();
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

	bool Listapracownikow::sprawdzdate(int dzien, int miesiac, int rok) {
		if (rok % 4 == 0) {
			if (miesiac == 2) {
				if (dzien < 30) { return true; }
				else { return false; }
			}

			else if (miesiac == 4 || miesiac == 6 || miesiac == 9 || miesiac == 11) {
				if (dzien < 31) { return true; }
				else { return false; }
			}
			else if(miesiac<13) {
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
			else if(miesiac<13) {
				if (dzien < 32) { return true; }
				else { return false; }

			}
			else { return false; }

		}
	}

	
