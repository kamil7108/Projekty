#include "Administrator.h"
void Administrator::wyswietl_administratora() {
	std::cout << haslo << "Login: " << login << "Imie: " << imie << "Nazwisko: " << nazwisko << "Stanowisko: "
		<< stanowisko << "Link: " << link << " "<<link_firmy<< std::endl;

}
void Administrator::dodajpracownikadofirmy(){
	std::string imie;
	std::string nazwisko;
	std::string stanowisko;
	std::string link;
	std::string haslo;
	std::string login;
	while (imie.length() < 3 && nazwisko.length() < 3) {
		std::cout << "Podaj imie pracownika:";
		std::cin >> imie;
		std::cout << "Podaj nazwisko pracownika:";
		std::cin >> nazwisko;
		std::cout << "Podaj stanowisko:";
		std::cin >> stanowisko;
	}
	haslo = stworzhaslo();
	login = stworzlogin(imie, nazwisko);
	std::cout << std::endl;
	std::cout << "Login pracownika: " << login << std::endl<<"Haslo pracownika: "<<haslo<<std::endl;
	link = stworzlink(login);
	Listapracownikow * nowy= new Listapracownikow(haslo, login, imie, nazwisko, stanowisko, link);
	nowy->stworzplikpracownika();
	dodajdofirmy(link, link_firmy);
	dodaj_pracownikow_do_firmy(nowy);
}
void Administrator::dodajadministratoradofirmy(std::string linkf,std::string nazwaf){
	std::string imie;
	std::string nazwisko;
	std::string stanowisko="Administrator";
	std::string link;
	std::string haslo;
	std::string login;
	system("cls");
	while (imie.length() < 3 && nazwisko.length() < 3) {
		std::cout << "Podaj imie administratora:";
		std::cin >> imie;
		std::cout << "Podaj nazwisko administratora:";
		std::cin >> nazwisko;
	}
	haslo = stworzhaslo();
	login = stworzlogin(imie, nazwisko);
	std::cout << std::endl;
	std::cout << "Login pracownika: " << login << std::endl << "Haslo pracownika: " << haslo << std::endl;
	link = stworzlink(login);
	Listapracownikow * nowy = new Listapracownikow(haslo, login, imie, nazwisko, stanowisko, link);
	nowy->stworzplikpracownika();
	dodajdofirmyadm(link, linkf,nazwaf);
	delete nowy;

}


std::string Administrator::stworzlink(std::string login) {
	std::string link=".txt";
	link = login + link;
	return link;
}

std::string Administrator::stworzlogin(std::string imie, std::string nazwisko) {
std::string Login;
char c;
for (int i = 0; i < 2; i++) {
	 c = (char)imie[i];
	Login.push_back(c);
}
for (int i = 0; i < 3; i++) {
	c =(char)nazwisko[i];
	Login.push_back(c);
}
return Login;
}
std::string Administrator::stworzhaslo(){
	bool showMeta = true;
	int dlugosc = 10; //Length of password to be generated
	int amountGen = 1; //Amount of passwords to generate
	bool smallAlpha = true; //Inclusion of lowercase letters
	bool largeAlpha = true; //Inclusion of uppercase letters
	bool symbole = false; //Whether or not to include symbols
	std::string s;
	
	Haslo pg(dlugosc, amountGen, smallAlpha, largeAlpha, symbole);
	//Output based on amount requested
	s = pg.nowehaslo(showMeta);
	std::cout << s;
	return s;
		
}
void Administrator::dodajdofirmy(std::string linkp, std::string linkf) {
	std::ofstream plik;
	plik.open(linkf, std::ios::out | std::ios::app);
	plik << std::endl << linkp;
	plik.close();
}
void Administrator::dodajdofirmyadm(std::string linkp, std::string linkf,std::string nazwaf) {
	std::ofstream plik;
	plik.open(linkf, std::ios::out | std::ios::app);
	plik << nazwaf << std::endl;
	plik << linkp;
	plik.close();
}

void Administrator::dodaj_pracownikow_do_firmy(Listapracownikow * obiekt) {
	if (this->listapracownikow == nullptr) {
		this->listapracownikow = obiekt;
	}
	Listapracownikow * tmp = this->listapracownikow;
	while (tmp->nastepny != nullptr) {
		tmp = tmp->nastepny;
	}
	tmp->nastepny = obiekt;
}

void Administrator::drukujraportpracownikow(int od_d,int od_m,int od_r,int do_d,int do_m,int do_r)
{
	Listapracownikow *tmp = this->listapracownikow;
	while (tmp != nullptr) {
	std::string raport = "raport";
	raport = raport + tmp->link;
	
	std::ofstream plik(raport);
	if (plik.good()) {
		
		std::cout << std::endl;
		plik << std::endl;
		Listadni* dni = tmp->dnipracy(od_d, od_m, od_r, do_d, do_m, do_r);
		Listadni* a = dni;
		std::cout << "Pracownik : " << tmp->imie << " " << tmp->nazwisko << std::endl << "Dni pracy pracownika w okresie : " << od_d << "." << od_m << "." << od_r << " - " << do_d<<"." << do_m << "." << do_r << std::endl;
		plik << "Pracownik : " << tmp->imie << " " << tmp->nazwisko << std::endl << "Dni pracy pracownika w okresie : " << od_d << "." << od_m << "." << od_r << " - " << do_d << "." << do_m << "." << do_r << std::endl;
		int i = 1;
		while (a != nullptr) {
			
			std::cout << "Dzien." << i << "  " << a->dzien << "." << a->miesiac << "." << a->rok << std::endl;
			plik << "Dzien." << i << "  " << a->dzien << "." << a->miesiac << "." << a->rok << std::endl;
			a = a->next;
			i++;
		}
		i = 1;
		tmp = tmp->nastepny;
		delete dni;
		
		plik.close();
	
	}
	}
	 

}


