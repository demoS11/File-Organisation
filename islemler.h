#ifndef ISLEMLER_H
#define ISLEMLER_H

#include "kova.h"
#include <fstream>
#include "kitap.h"


class Islemler{
	private:
		std::ifstream txt;
		std::fstream bin;
		Kova * kovalar;
		// bundan sonraki degerler istatistikler için tutuldu
		int toplamEvSayisi;
		int doluEvSayisi;
		int toplamAramaSayisi;
		int toplamAramaUzunlugu;
	public:
		Islemler();
		void oku();
		void hepsiniGoster();
		void ara();
		void kayitEkle();
		void kayitSil();
		void istatistikler();
		void kitapEkle(Kitap);
};

#endif

