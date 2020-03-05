#include "Haslo.h"
std::string Haslo::nowehaslo(bool outMeta) {
	std::string st;
	if (dlugosc > 1 && outMeta) pokazefekt();
	for (int i = 0; i < ilosc; i++) {

		//Initializes random number generator
		std::random_device rd;
		std::mt19937 mt(rd());
		

		////Provides boundaries for where to distribute numbers
		std::uniform_int_distribution<int> numDist(0, 9); //Random distribution for numbers
		std::uniform_int_distribution<int> letDist(0, 25); //Random distribution for letters
		std::uniform_int_distribution<int> symDist(0, 13); //Random distribution for symbols

		//Determines which options can be used for the output
		std::vector<int> choices = { 1 }; //Always include numbers
		if (malelitery) choices.push_back(2); //Include lowercase
		if (duzelitery) choices.push_back(3); //Include uppercase
		std::uniform_int_distribution<int> typeDist(0, choices.size() - 1);

		//Storage of characters available
		char lowerCase[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
		char upperCase[26] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
		char symbo[14] = { '!', '#', '@', '~', '$', '^', '.', ',', '-', '+', '%', '?', '*', '=' };
		char a;
		//Prints to output file
		for (int p = 0; p < dlugosc; p++)
		{
			switch (choices[typeDist(mt)])
			{
			case 1: //Numbers
				a= numDist(mt)+'0';
				st.push_back(a);

				break;
			case 2: //Lowercase
				a = lowerCase[letDist(mt)];
				st.push_back(a);
				break;
			case 3: //Uppercase
				a = upperCase[letDist(mt)];
				st.push_back(a);
				break;
			case 4:
				a = symbo[symDist(mt)];
				st.push_back(a);
				break;

			
			
			}
		}
		
	}
	
	return st;
}
Haslo::~Haslo() {
	
}

void Haslo::pokazefekt() {
	std::cout << "PasswordGenerator | length: " << dlugosc << " | amount: " << ilosc << "\n";
}
Haslo::Haslo() {
	dlugosc = 8;
	ilosc = 1;
	malelitery = false;
	duzelitery = false;
	symbole = false;
}

Haslo::Haslo(int len, int amt, bool smA, bool lgA, bool sym) {
	if (len < 6) dlugosc = 6;
	else if (len > 256) dlugosc = 256;
	else dlugosc = len;

	if (amt < 1) ilosc = 1;
	else if (amt > 1000) ilosc = 1000;
	else ilosc = amt;

	malelitery = smA;
	duzelitery = lgA;
	symbole = sym;
}