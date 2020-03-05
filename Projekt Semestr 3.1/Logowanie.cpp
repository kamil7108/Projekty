#include "Logowanie.h"

void Logowanie::logowanie() {
	if (login.empty() == false && haslo.empty() == false && firma.empty() == false) {

		Lista_firm * tmp = this->znajdz_firme(firma);
		bool rozpoczecie = true;
		int sterownik = 0;
		int od_d = 0;
		int od_m = 0;
		int od_r = 0;
		int do_d = 0;
		int do_m = 0;
		int do_r = 0;	
		int suma_od=0;
		int suma_do=0;
		char kropka;
		int blad = 1;
		if (tmp != nullptr) {

			
			Pracownik * obj = tmp->Pracownicy->znajdz_pracownika(login, haslo);
			Administrator * obj1 = tmp->Administratorzy->znajdz_pracownika(login, haslo);
			system("cls");
			if (this->tmp->sprawdzczyzarzadzajacy(haslo, login) == true) {
				std::cout << "Procedura dodawania firmy" << std::endl;
				this->tmp->dodaj_firme();
			}
			else if (obj != nullptr) {

				while (rozpoczecie) {
					system("cls");
					this->instrukcjaPRA();
					std::cin >> sterownik;
					switch (sterownik)
					{
					case 1:
						obj->zamelduj_w_pracy();
						std::cout << "System zarejstrowal przybycie" << std::endl;
						system("pause");//funkcja lekko do zmiany
						break;
					case 2:
					
						while (suma_do - suma_od <= 0) {
							std::cout << "Date wpisuj w formacie dd.mm.rrrr" << std::endl;
							std::cout << "Sprawdz okres od :";
							std::cin >> od_d >> kropka >> od_m >> kropka >> od_r;
							
							while (sprawdzdate(od_d, od_m, od_r) == false) {
								system("cls");
								std::cout << "Date wpisuj w formacie dd.mm.rrrr" << std::endl; 
								std::cout << "Sprawdz okres od :";
								std::cin >> od_d >> kropka >> od_m >> od_r;
								blad++;
							}
							suma_od = od_d + od_m * 100 + od_r * 10000;
							std::cout << "Date wpisuj w formacie dd.mm.rrrr" << std::endl;
							std::cout << "Sprawdz okres do :";
							std::cin >> do_d >> kropka >> do_m >> kropka >> do_r;
							while (sprawdzdate(do_d, do_m, do_r) == false) {
								system("cls");
								 std::cout << "Date wpisuj w formacie dd.mm.rrrr" << std::endl; 
								std::cout << "Sprawdz okres do :";
								std::cin >> do_d >> kropka >> do_m >> kropka >> do_r;
								blad++;
							}
							suma_do = do_d + do_m * 100 + do_r * 10000;
							system("cls");
						}
						obj->sprawdzokres(od_d, od_m, od_r, do_d, do_m, do_r);
						od_d = 0; od_m = 0; od_r = 0; do_r = 0; do_m = 0; do_d = 0; blad = 0; suma_od = 0; suma_do = 0;
						system("pause");
						break;
					case 3: rozpoczecie = false;
						break;
					}
				}
			}
			
			else {
				while (rozpoczecie) {
					system("cls");
					this->instrukcjaADM();
					std::cin >> sterownik;
					switch (sterownik)
					{
					case 1:
						obj1->zamelduj_w_pracy();
						std::cout << "System zarejstrowal przybycie" << std::endl;
						system("pause");// funkcja lekko do zmiany
						break;
					case 2:
						while (suma_do - suma_od <= 0) {
							std::cout << "Date wpisuj w formacie dd.mm.rrrr" << std::endl;
							std::cout << "Sprawdz okres od :";
							std::cin >> od_d >> kropka >> od_m >> kropka >> od_r;
							while (sprawdzdate(od_d, od_m, od_r) == false) {
								system("cls");
								std::cout << "Date wpisuj w formacie dd.mm.rrrr" << std::endl; 
								std::cout << "Sprawdz okres od :";
								std::cin >> od_d >> kropka >> od_m >> od_r;
								blad++;
							}
							suma_od = od_d + od_m * 100 + od_r * 10000;
							std::cout << "Date wpisuj w formacie dd.mm.rrrr" << std::endl;
							std::cout << "Sprawdz okres do :";
							std::cin >> do_d >> kropka >> do_m >> kropka >> do_r;
							while (sprawdzdate(do_d, do_m, do_r) == false) {
								system("cls");
								std::cout << "Date wpisuj w formacie dd.mm.rrrr" << std::endl;
								std::cout << "Sprawdz okres do :";
								std::cin >> do_d >> kropka >> do_m >> kropka >> do_r;
								blad++;
							}
							suma_do = do_d + do_m * 100 + do_r * 10000;
						}
						obj1->sprawdzokres(od_d, od_m, od_r, do_d, do_m, do_r);
						od_d = 0; od_m = 0; od_r = 0; do_r = 0; do_m = 0; do_d = 0; blad = 0; suma_od = 0; suma_do = 0;
						system("pause");
						break;
					case 3:
						while (suma_do - suma_od <= 0) {
							std::cout << "Date wpisuj w formacie dd.mm.rrrr" << std::endl;
							std::cout << "Sprawdz okres od :";
							std::cin >> od_d >> kropka >> od_m >> kropka >> od_r;
							while (sprawdzdate(od_d, od_m, od_r) == false) {
								system("cls");
								std::cout << "Date wpisuj w formacie dd.mm.rrrr" << std::endl; 
								std::cout << "Sprawdz okres od :";
								std::cin >> od_d >> kropka >> od_m >> od_r;
								blad++;
							}
							suma_od = od_d + od_m * 100 + od_r * 10000;
							std::cout << "Date wpisuj w formacie dd.mm.rrrr" << std::endl;
							std::cout << "Sprawdz okres do :";
							std::cin >> do_d >> kropka >> do_m >> kropka >> do_r;
							while (sprawdzdate(do_d, do_m, do_r) == false) {
								system("cls");
								std::cout << "Date wpisuj w formacie dd.mm.rrrr" << std::endl; 
								std::cout << "Sprawdz okres do :";
								std::cin >> do_d >> kropka >> do_m >> kropka >> do_r;
								blad++;
							}
							suma_do = do_d + do_m * 100 + do_r * 10000;
						}
						obj1->drukujraportpracownikow(od_d, od_m, od_r, do_d, do_m, do_r);
						od_d = 0; od_m = 0; od_r = 0; do_r = 0; do_m = 0; do_d = 0; blad = 0; suma_od = 0; suma_do = 0;
						system("pause");
						break;
					case 4:
						obj1->dodajpracownikadofirmy();
						std::cout << "Pracownik dodany" << std::endl;
						system("pause");
						break;
					

					case 5:
						rozpoczecie = false;
					}
				}
			}
		}
	}
}
void Logowanie::instrukcjaADM() {
	std::cout << "Dostepne funkcje programu:" << std::endl;
	std::cout << "1.Zamelduj w pracy \n";
	std::cout << "2.Sprawdz swoje dni pracy w danym okresie \n";
	std::cout << "3.Drukuj raporty wszystkich pracownikow z danego okresu\n";
	std::cout << "4.Dodaj nowego pracownika \n";

	std::cout << "5.Zakoncz \n";
}
void Logowanie::instrukcjaPRA(){
	std::cout << "Dostepne funkcje programu:" << std::endl;
	std::cout << "1.Zamelduj w pracy \n";
	std::cout << "2.Sprawdz swoje dni pracy w danym okresie \n";
	std::cout << "3.Zakoncz \n";
	
}
bool Logowanie::sprawdzdate(int dzien, int miesiac, int rok) {
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

void Logowanie::stworz_zarzadce(std::string spis, Lista_firm * & lista) {
	this->tmp->dodaj_zarzadzajacego(spis,lista);
}
