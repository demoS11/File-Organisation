#include "islemler.h"
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

Islemler::Islemler()
{
	this->doluEvSayisi = 0;
	this->toplamEvSayisi = 41*5;
	this->toplamAramaSayisi = 0;
	this->toplamAramaUzunlugu = 0;
}
// ilk calisan fonksiyon
void Islemler::oku()
{
	this->txt.open("books.txt");
	kovalar = new Kova[41];
	for(int i = 0; i < 41; i++)
	{
		Kova kova;
		kovalar[i] = kova;
	}
	
	bin.open("booksHash.bin", ios::binary | ios::out);
	txt.seekg(0);
	
	string isbn;
	string isim;
	string yazar;
	string fiyat;
	string bos; //bos satir

	while (!txt.eof()){
		getline(txt, isbn);
		getline(txt, isim);
		getline(txt, yazar);
		getline(txt, fiyat);
		getline(txt, bos); //bos satir
		
		Kitap kitap(isbn, isim, yazar, fiyat);
		cout<< "kitap okundu:" << kitap.toString() << endl;
		kitapEkle(kitap);
	}
	
	txt.close();
	bin.close();
}

// tüm kayýtlarý kova toStringi ile yazýyor
void Islemler::hepsiniGoster()
{
	for(int i = 0; i < 41; i++)
	{
		Kova kova = this->kovalar[i];
		cout << "kova " << i << endl;
		cout << kova.toString();
		cout << "------------------------" << endl;
	}
}

// aranacak ýsbn degerini kendi alýyor,stringe donusturuyor hash ile ait oldugu kovayý buluyor
void Islemler::ara()
{
	cout << "Aranacak ISBN degerini girin." << endl;
	string terim;
	cin >> terim;
	
	stringstream stringToInt(terim);
	int hash;
	stringToInt >> hash;
	hash = hash % 41;
	bool aramaBitti = false;
	//istatistik için tutuluyor
	int aramaUzunlugu = 0;
	while(!aramaBitti)
	{
		Kova kova = this->kovalar[hash];
		for(int i = 0; i < 5; i++)
		{
			aramaUzunlugu++;
			Kitap kitap = kova.getKitap(i);
			if(kitap.getIsbn().compare(terim) == 0)
			{
				cout << "Eslesen kitap: " << endl;
				cout << kitap.toString(); 
				aramaBitti = true;
				break;
			}
			else if(kitap.getIsbn().compare("0") == 0)
			{
				cout << "Eslesen kitap bulunamadi!" << endl;
				aramaBitti = true;
				break;
			}
		}
		//overflow 
		if(!aramaBitti)
		{
			hash = (hash + 1) % 41;	
		}
	}
	this->toplamAramaSayisi++;
	this->toplamAramaUzunlugu += aramaUzunlugu;
	
	if(this->toplamAramaSayisi > 0)
	{
		float ortalamaAramaUzunlugu = (float)this->toplamAramaUzunlugu/(float)this->toplamAramaSayisi;
		if(ortalamaAramaUzunlugu > 4)
		{
			cout << "Ortalama arama uzunlugu kabul edilebilir limitin uzerinde, karma dosyasini yeniden duzenlemek arama perfomansini arttirabilir!" << endl;
		}
	}
}

//kod tekrarý olmasýn diye yazdim
void Islemler::kayitEkle()
{
	cout << "ISBN degeri girin" << endl;
	string isbn;
	cin >> isbn;
	cout << "Kitap ismi girin" << endl;
	string isim;
	cin >> isim;
	cout << "Yazar ismi girin" << endl;
	string yazar;
	cin >> yazar;
	cout << "Fiyat girin" << endl;
	string fiyat;
	cin >> fiyat;
	
	Kitap kitap(isbn, isim, yazar, fiyat);
	kitapEkle(kitap);	
}


void Islemler::kitapEkle(Kitap kitap)
{
	int hashKod = kitap.hashKodu();
	bool eklendi = false;
	while(!eklendi)
	{
		Kova kova = this->kovalar[hashKod];
		if(kova.doluMu())
		{
			hashKod = (hashKod + 1) % 41;
		}
		else
		{
			for(int kitapIndex = 0; kitapIndex < 5; kitapIndex++)
			{
				if(kova.evBosMu(kitapIndex))
				{
					kova.setKitap(kitapIndex, kitap);
					eklendi = true;
					this->doluEvSayisi++;
					break;
				}
			}
		}
	}
	
	float yogunluk = ((float)this->doluEvSayisi/(float)this->toplamEvSayisi);
	if(yogunluk > 0.9)
	{
		cout << "Karma dosyasi yogunlugu %90'i gecti!" << endl;
	}
}

//kayit sil temelde aranýn aynýsý silmek istedigim kayýt bulunursa basýna * tomb stone ekliyorum
void Islemler::kayitSil()
{
	cout << "Silinecek ISBN degerini girin." << endl;
	string terim;
	cin >> terim;
	
	stringstream stringToInt(terim);
	int hash;
	stringToInt >> hash;
	hash = hash % 41;
	bool aramaBitti = false;
	while(!aramaBitti)
	{
		Kova kova = this->kovalar[hash];
		for(int i = 0; i < 5; i++)
		{
			Kitap kitap = kova.getKitap(i);
			if(kitap.getIsbn().compare(terim) == 0)
			{
				cout << "Silinecek kitap: " << endl;
				cout << kitap.toString();
				
				Kitap yeniKitap("*"+kitap.getIsbn(), kitap.getIsim(), kitap.getYazar(), kitap.getFiyat());
				kova.setKitap(i, yeniKitap);
				
				aramaBitti = true;
				break;
			}
			else if(kitap.getIsbn().compare("0") == 0)
			{
				cout << "Silinecek kitap bulunamadi!" << endl;
				aramaBitti = true;
				break;
			}
		}
		
		if(!aramaBitti)
		{
			hash = (hash + 1) % 41;	
		}
	}
}

void Islemler::istatistikler()
{
	cout << "Dolu ev sayisi: " << this->doluEvSayisi << endl;
	cout << "Toplam ev sayisi: " << this->toplamEvSayisi << endl; 
	float yogunluk = ((float)this->doluEvSayisi/(float)this->toplamEvSayisi);
	cout << "Karma dosyasi yogunlasma degeri: %" << (yogunluk * 100) << endl;
	
	if(this->toplamAramaSayisi > 0)
	{
		cout << "Yapilan toplam arama: " << this->toplamAramaSayisi << endl;
		float ortalamaAramaUzunlugu = (float)this->toplamAramaUzunlugu/(float)this->toplamAramaSayisi;
		cout << "Ortalama arama uzunlugu: " << ortalamaAramaUzunlugu << endl;
	}
	else
	{
		cout << "Henuz arama yapilmadi." << endl;
	}
}
