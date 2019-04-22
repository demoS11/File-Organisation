#include "kova.h"
#include <cstddef>
#include <iostream>

using namespace std;

//yapici metod 5 tane olusturuyor ve hepsine defoult degerler atiyor
// basta eger isbn e 0 veya null gibi bir deger atamasaydik arama silme gibi islemler yapamazdik
Kova::Kova()
{
	this->kitaplar = new Kitap[5];
	for(int i = 0; i < 5; i++)
	{
		Kitap kitap("0", "", "", "");
		this->kitaplar[i] = kitap;
	}
}

//bir þeyi silsek bile hic bir zaman 0 olmayacak yalnýzca bos ise 0 dir
//kovanýn dolu olup olmadýgýna bakar
bool Kova::doluMu()
{
	for(int i = 0; i < 5; i++)
	{
		Kitap kitap = this->kitaplar[i];
		if(kitap.getIsbn().compare("0") == 0)
		{
			return false;
		}
	}
	return true;
}

//evin bos olup olmadýgýna bakar
bool Kova::evBosMu(int i)
{
	if(this->kitaplar[i].getIsbn().compare("0") == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//kitabi donuyor
Kitap Kova::getKitap(int i)
{
	return this->kitaplar[i];
}

void Kova::setKitap(int i, Kitap kitap)
{
	this->kitaplar[i] = kitap;
}

string Kova::toString()
{
	string temp = "";
	for(int i = 0; i < 5; i++)
	{
		string kitap = this->kitaplar[i].toString();
		temp += kitap + "\n";
	}
	return temp;
}
