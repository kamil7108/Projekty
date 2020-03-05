#include "Kalendarz.h"
bool Kalendarz::czy_przestepny(int r)
{
	return (r % 4 == 0 && r % 100 != 0) || r % 400 == 0;
}

int Kalendarz::Ile_dni_ma_miesiac(int m, int r)
{
	return n[czy_przestepny(r)][m];
}

int Kalendarz::ktory_dzien_w_roku(int d, int m, int r)
{
	bool p = czy_przestepny(r);
	while (--m > 0)
		d += n[p][m];
	return d;
}

int Kalendarz::jaki_dzien_tygodnia(int d, int m, int r)
{
	if (m > 2)
		m -= 2;
	else
	{
		m += 10;
		r--;
	}
	int w = r / 100;
	r %= 100;
	return (d + (13 * m - 1) / 5 + r + r / 4 + w / 4 + 5 * w) % 7;
}

void Kalendarz::wypisz_miesiac(int m, int r,Listadni * & tmp) {
	bool tab[7] = { false,false,false,false,false,false,false };
	//Listadni * tmp2 = tmp;
	
	std::cout << std::setw((17 - Mc[m - 1].length()) / 2) << "" << Mc[m - 1] << std::setw(5) <<r<<std::endl << " Nd Po Wt Sr Cz Pt So" << std::endl;
	
	int n = jaki_dzien_tygodnia(1, m, r), max = Ile_dni_ma_miesiac(m, r);
	
	if (n > 0) {
		std::cout << std::setw(3 * n) << "";
		
	}
	int i = 0;
	int maks_d = 0;
	int maks_m = 0;
	int d;
	int ostwyp;
	for ( d = 1; d <= max; d++)
	{
	
			std::cout << std::setw(3) << d;
			if (d == tmp->dzien) {
				tab[i] = true;
				if (tmp->next != nullptr&&tmp->next->miesiac == m&&tmp->next->rok==r) {
					tmp = tmp->next;
					maks_d = tmp->dzien;
					maks_m = tmp->miesiac;
				}

			}
			++i;
			if ((d + n) % 7 == 0) {
				ostwyp = d;
				std::cout << std::endl;
				for (int a = 0; a < 7; a = a + 1) {
					if (tab[a] == true) {
						std::cout << std::setw(3) << "+";
						tab[a] = false;
					}
					else { std::cout << std::setw(3) << "-"; }
				}
				std::cout << std::endl;
				i = 0;
			}
		}
	
	if (max!=ostwyp) {
		std::cout << std::endl;
		for (int a = 0; a < max-ostwyp; a = a + 1) {
			if (tab[a] == true) {
				std::cout << std::setw(3) << "+";
				tab[a] = false;
			}
			else { std::cout << std::setw(3) << "-"; }
		}
	}
	if (d >= maks_d) {
		tmp = tmp->next;
	}
	
	std::cout << std::endl << std::endl;
}