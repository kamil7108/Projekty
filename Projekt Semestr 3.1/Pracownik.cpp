#include "Pracownik.h"

void Pracownik::wyswietl_pracownika() {
	std::cout <<"Haslo: "<<haslo << "Login: " << login << "Imie: " << imie << "Nazwisko: " << nazwisko << "Stanowisko: "
		<< stanowisko << "Link: " << link << std::endl;
	
}
void Pracownik::wpisz_do_bazy( const Dzien * data) {
	std::ofstream plik;
	plik.open(this->link, std::ios::out | std::ios::app);
	plik <<std::endl<< data->dzien << "." << data->miesiac << "." << data->rok;
	plik.close();
}
void Pracownik::zamelduj_w_pracy() {
	
		SYSTEMTIME  st;
		GetSystemTime(&st);
		Dzien * data = new Dzien(st.wDay, st.wMonth, st.wYear);
		bool czy_juz_jest=this->lista->dodaj_dzien(st.wDay, st.wMonth, st.wYear);
		if (czy_juz_jest == true) {
			this->wpisz_do_bazy(data);
		}
		delete data;
}


void Pracownik::sprawdzokres(int od_d, int od_m, int od_rok, int do_d, int do_m, int do_rok)
{
	if (this->lista != nullptr) {
		Listadni * tmp = this->lista;
	
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
				if (tab->dzien > do_d || tab->miesiac > do_m || tab->rok > do_rok) { delete tab; }
				else {
					tab->wypisz_okres();
				}

			}

		}

	}
}
	
	

void Pracownik::stworzplikpracownika() {
	std::ofstream plik(link);
	if(plik.good()) {
		plik << stanowisko << std::endl;
		plik << imie << std::endl;
		plik << nazwisko << std::endl;
		plik << login << std::endl;
		plik << haslo;
	}
	plik.close();
}


					
Listadni *   Pracownik::dnipracy(int od_d, int od_m, int od_rok, int do_d, int do_m, int do_rok)
{
	if (this->lista != nullptr) {
		Listadni * tmp = this->lista;
	
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


			return tab;




		}
		delete tab;
		return nullptr;


	}
	return nullptr;
}
				



