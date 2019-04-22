#ifndef KITAP_H 
#define KITAP_H

#include <string>

using namespace std;

class Kitap{
  private:
	string isbn;
	string isim;
	string yazar;
	string fiyat;
	
  public:
  	Kitap();
  	Kitap(string, string, string, string);
  	string toString();
  	string getIsim();
  	string getIsbn();
  	string getYazar();
  	string getFiyat();
  	int hashKodu();
};


#endif


