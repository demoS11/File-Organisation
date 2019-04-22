#ifndef KOVA_H 
#define KOVA_H

#include "kitap.h"

class Kova{
	private:
		Kitap *kitaplar;
	public:
		Kova();
		bool doluMu();
		bool evBosMu(int i);
		Kitap getKitap(int);
		void setKitap(int, Kitap);
		string toString();
};

#endif
