// Projekt Semestr 3.1.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include "Firma.h"
#include "Lista_firm.h"
#include "Logowanie.h"
#include "Haslo.h"
#include <stdio.h>
#include <vld.h>
#include <vld_def.h>

//Projekt 3 semestr
int main(int argc, char * argv[])
{
	std::string login = "";
	std::string haslo = "";
	std::string nazwafirmy = "";
	std::string spisfirm= "";
	std::cout << "Zarzadzanie czasem pracy" << std::endl;
	if (argc == 9) {
		for (int i = 1; i < argc; i = i + 2) {
			if (strcmp(argv[i], "-l") == 0) { login = argv[i + 1]; continue; }
			if (strcmp(argv[i], "-h") == 0) { haslo = argv[i + 1]; continue; }
			if (strcmp(argv[i], "-n") == 0) { nazwafirmy = argv[i + 1]; continue; }
			if (strcmp(argv[i], "-s") == 0) { spisfirm = argv[i + 1]; continue; }
		}
	Logowanie * obiekt1 = new Logowanie;
	obiekt1->login = login;
	obiekt1->haslo = haslo;
	obiekt1->firma = nazwafirmy;
	obiekt1->czytajplik(spisfirm);
	Lista_firm* tmp = obiekt1->ta();
	obiekt1->stworz_zarzadce(spisfirm,tmp);
	obiekt1->logowanie();
	delete obiekt1;
	}

	else {
		spisfirm = "Spis.txt";
		std::cout << "Podaj nazwe firmy: ";
		std::cin >> nazwafirmy;
		std::cout << "Podaj login: ";
		std::cin >> login;
		std::cout << "Podaj haslo: ";
		std::cin >> haslo;

	}
	Logowanie * obiekt1 = new Logowanie;
	obiekt1->login = login;
	obiekt1->haslo = haslo;
	obiekt1->firma = nazwafirmy;

	obiekt1->czytajplik(spisfirm);
	Lista_firm* tmp = obiekt1->ta();
	obiekt1->stworz_zarzadce(spisfirm, tmp);
	obiekt1->logowanie();
	delete obiekt1;

	}


	
	


// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
