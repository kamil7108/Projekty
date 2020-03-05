#include "Zarzadzajacy.h"

void Zarzadzajacy::dodaj_zarzadzajacego(std::string link, Lista_firm * & lista) {
	std::string linia;
	std::fstream plik;
	
	linkdospisu = link;
	plik.open(link, std::ios::in);
	if (plik.good() == true)
	{
		getline(plik, linia);
		link = linia;
		plik.close();
	}
	plik.open(link, std::ios::in);
	if (plik.good() == true)
	{
		getline(plik, linia);
		Zarzadzajacy * tmp = this;
		tmp->login = linia;
		getline(plik, linia);
		tmp->haslo = linia;
		plik.close();
	}
	listafirm = lista;
}
bool Zarzadzajacy::sprawdzlinie(std::string napis) {
	if (napis.empty() == false) {
		int dlugosc = napis.length();
		if (napis[dlugosc - 1] == 't' && napis[dlugosc - 2] == 'x'&& napis[dlugosc - 3] == 't' && napis[dlugosc - 4] == '.') {
			return true;
		}
		else { return false; }
	}
	else { return false; }
}
void Zarzadzajacy::dodaj_firme() {
	if (this->listafirm == nullptr) {
		this->listafirm = new Lista_firm;
		std::string link;
		std::string nazwa;
		while (sprawdzlinie(link) != true) {
			std::cout << "Podaj nazwe firmy: ";
			std::cin >> nazwa;
			link = nazwa + ".txt";
			system("cls");
		}
		this->listafirm->dodaj_firme(link);
		this->dodajfirmedospisu(this->listafirm);
		this->dodajdofirmy(link,link);
		this->dodajadministratoradofirmy(link,nazwa);
		
		
	}
	Lista_firm *tmp=this->listafirm;
	while (tmp->nastepna != nullptr) {
		tmp = tmp->nastepna;
	}
	std::string link;
	std::string nazwa;
	while (sprawdzlinie(link) != true) {
	std::cout << "Podaj nazwe firmy: ";
	std::cin >> nazwa;
	link = nazwa + ".txt";
	system("cls");
	}
	tmp->nastepna = new Lista_firm(link);
	tmp->nastepna->dodaj_firme(link);
	this->dodajfirmedospisu(tmp->nastepna);
	this->dodajadministratoradofirmy(link,nazwa);

}
bool Zarzadzajacy::sprawdzczyzarzadzajacy(std::string h, std::string l) {
	if (this->login == login && this->haslo == h) { return true; }
	else { return false; }
}
void Zarzadzajacy::dodajfirmedospisu(Lista_firm * tmp) {
	std::ofstream plik;
	plik.open(this->linkdospisu, std::ios::out | std::ios::app);
	plik << std::endl << tmp->link;
	plik.close();
}

