#include "Listadni.h"
#include "Kalendarz.h"

bool Listadni::dodaj_dzien(int dd, int mm, int rr) {

		if (this->dzien == 0) {
			this->dzien = dd;
			this->miesiac = mm;
			this->rok = rr;
			return true;
		}
		else {
			Listadni * tmp = this;
			while (tmp->next != nullptr) {
				tmp = tmp->next;
			}
			if (dd != tmp->dzien || mm != tmp->miesiac || rr != tmp->rok&& tmp->dzien != 0) {
				Listadni * tmap = new Listadni;
				tmap->dzien = dd;
				tmap->miesiac = mm;
				tmap->rok = rr;
				tmp->next = tmap;
				return true;
			}
			else {
				std::cout << "Juz jest taki dzien " << std::endl;
				return false;
			}
		}
	}


Listadni & Listadni::operator +(Listadni * & tmp) {
	if (this !=tmp) {
		Listadni * to = this;
		while (to->next != nullptr) { to = to->next; }
		to->next = tmp;
		return *this;
	}
	else{ return *this; }
}
void Listadni::wyswietl_liste_dni() {
	Listadni * tmp = this;
	while (tmp != nullptr) {
		std::cout << tmp->dzien << "." << tmp->miesiac <<"."<<tmp->rok<< std::endl;
		tmp = tmp->next;
	}
}
bool Listadni::sprawdzdate(int dzien, int miesiac, int rok) {
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
void Listadni::wypisz_okres() {
	Listadni * tmp = this;
	Kalendarz kalendarz(tmp);
	while (tmp != nullptr&&tmp->dzien!=0) {
		kalendarz.wypisz_miesiac(tmp->miesiac, tmp->rok,tmp);
	}
}
void Listadni::wypiszokres(int od_d, int od_m, int od_rok, int do_d, int do_m, int do_rok)
{
	if (this != nullptr) {
		Listadni * tmp = this;
		tmp->wyswietl_liste_dni();
		std::cout << std::endl;
		Listadni * tab = new Listadni;
		while (tmp != nullptr && tmp->rok < od_rok) {
			
			tmp = tmp->next;
		}

		while (tmp != nullptr&&tmp->miesiac < od_m&& tmp->rok == od_rok) {
		
			tmp = tmp->next;
		}

		while (tmp != nullptr &&tmp->dzien < od_d&& tmp->miesiac == od_m && tmp->rok == od_rok) {
			tmp = tmp->next;
		}
		if (tmp != nullptr) {

			tab->dzien = tmp->dzien;
			tab->miesiac = tmp->miesiac;
			tab->rok = tmp->rok;
			tmp = tmp->next;

			while (tmp != nullptr&&tmp->rok < do_rok) {
				Listadni * data = new Listadni;
				data->dzien = tmp->dzien;
				data->miesiac = tmp->miesiac;
				data->rok = tmp->rok;
				tab ->operator+ (data);
				tmp = tmp->next;
			}
			while (tmp != nullptr&& tmp->rok == do_rok && tmp->miesiac < do_m) {
				Listadni * data = new Listadni;
				data->dzien = tmp->dzien;
				data->miesiac = tmp->miesiac;
				data->rok = tmp->rok;
				tab ->operator+ (data);
				tmp = tmp->next;
			}
			while (tmp != nullptr&&tmp->rok == do_rok && tmp->miesiac == do_m && tmp->dzien <= do_d) {
				Listadni * data = new Listadni;
				data->dzien = tmp->dzien;
				data->miesiac = tmp->miesiac;
				data->rok = tmp->rok;
				tab ->operator+ (data);
				tmp = tmp->next;
			}




			if (tab == nullptr) {
				std::cout << "Nie ma takiej daty" << std::endl;
				delete tab;

			}
			else {
				tab->wypisz_okres();


			}

		}

	}
}



