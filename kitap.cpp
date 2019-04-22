#include "kitap.h"
#include <sstream>
#include <string>
#include <iostream>

using namespace std;

//default (bos) yapýcý
Kitap::Kitap()
{
}
// parametre alan yapici
Kitap::Kitap(string isbn, string isim, string yazar, string fiyat){
	this->isbn = isbn;
	this->isim = isim;
	this->yazar = yazar;
	this->fiyat = fiyat; 
}
//isbn doner
string Kitap::getIsbn()
{
	return this->isbn;
}
//ismi donuyor
string Kitap::getIsim()
{
	return this->isim;
}

//yazari donuyor
string Kitap::getYazar()
{
	return this->yazar;
}

//fiyati donuyor
string Kitap::getFiyat()
{
	return this->fiyat;
}

//toString metodu
string Kitap::toString(){
	return "ISBN: " + this->isbn + "|" + "Isim: " + this->isim + "|" + "Yazar: " + this->yazar + "|" + "Fiyat: " + this->fiyat + "\r\n";
}


// hash kodu kitapta çünkü kitap bizim özetleyecegimiz nesne 
// hash kodu olarak 41in modunu sectik 
// isbn i string olarak almýþtýk
int Kitap::hashKodu()
{
	stringstream stringToInt(this->isbn);
	int x = 0;
	stringToInt >> x;
	// bu yeterli olacaktýr
	return x % 41;
}

