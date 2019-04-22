#include <iostream>
#include <string>
#include "islemler.h"

using namespace std;

int main(int argc, char** argv) {


	char secim = ' ';
    // yonetici katolog sisteminin arayuzu
    Islemler islemler;
    //islemler.oku books.txt yi acýyor ve tum okuma islemlerini yapiyor
	islemler.oku();
    bool dongu = true;
   	cout << "KUTUPHANE YONETICI KATALOG SISTEMI" << endl;  


    while(dongu)
	{
		cout << "1. ISBN'ye gore ara" << endl;
		cout << "2. Kayit ekle" << endl;
		cout << "3. Kayit sil" << endl;
		cout << "4. Karma dosyasini yazdir" << endl;
		cout << "5. Istatistikler" << endl;
	    cout << "9. cikis" << endl;	
		cin >> secim;
		switch(secim)
		{
			case '1':
				islemler.ara();
				break;
			case '2':
				islemler.kayitEkle();
				break;
			case '3':
				islemler.kayitSil();
				break;
			case '4':
				islemler.hepsiniGoster();
				break;
			case '5':
				islemler.istatistikler();
				break;
			case '9':
				dongu = false;
				break;
			default:
				cout << "Gecersiz secim tekrar deneyin" << endl;
				break;
		}
	}
	cout << "Gule gule." << endl;
	return 0;
}

