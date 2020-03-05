#pragma once
/**
Klasa sluzy do przechowywania danych takich jak daty,czyli dnia w roku.
*/
class Dzien
{
	friend class Pracownik;
	friend class Kalendarz;
	friend class Administrator;
protected:
	int dzien;
	int miesiac;
	int rok;
public:
	Dzien() :dzien(0), miesiac(0), rok(0){}
	Dzien(int d,int m,int r) :dzien(d), miesiac(m), rok(r) {}
	virtual ~Dzien(){}
};

