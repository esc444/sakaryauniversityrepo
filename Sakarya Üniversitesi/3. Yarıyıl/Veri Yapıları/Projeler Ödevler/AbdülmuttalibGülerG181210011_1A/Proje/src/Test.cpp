/**
* @file Test
* @description programýn calýstýgý kýsým
* @course 1.Öðretim A Grubu
* @assignment 1.Ödev
* @date 16/08/2020
* @author Abdülmuttalib GÜLER
*/
#include "CiftYonluBagliListe.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

int main()
{
	CiftYonluListe* sayilar = new CiftYonluListe();

	ifstream dosyaOku("Sayilar.txt");
	string satir = "";
	string sayi = "";
	if (dosyaOku.is_open()) {

		while (getline(dosyaOku, satir)) {
			//cout << satir << endl;
			sayilar = new CiftYonluListe();
			stringstream stream(satir);
			while (getline(stream, sayi, ' ')) {
				cout << sayi + " ";

				int sayi1 = stoi(sayi);

			}
			cout << endl;
			delete sayilar;
		}
		dosyaOku.close();
	}
	return 0;
}
