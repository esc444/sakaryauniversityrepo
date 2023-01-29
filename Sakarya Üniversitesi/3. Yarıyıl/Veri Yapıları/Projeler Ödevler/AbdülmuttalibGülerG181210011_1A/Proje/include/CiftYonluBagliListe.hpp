/**
* @file CiftYonluBagliListe
* @description dugumlerýn yapmasý gereken butun isi yapýyor ve ebob buluyor
* @course 1.Öðretim A Grubu
* @assignment 1.Ödev
* @date 16/08/2020
* @author Abdülmuttalib GÜLER
*/

#ifndef CIFTYONLUBAGLILISTE_HPP
#define CIFTYONLUBAGLILISTE_HPP

#include "Dugum.hpp"
#include "Iterator.hpp"

class CiftYonluListe {
public:
	Dugum* ilk;
	int miktar;
	Iterator itr;
	Dugum* OncekiDugumuBul(int index) {
		Dugum* Onceki = ilk;
		int i = 1;
		for (Dugum* itr = ilk; i != index; itr = itr->Sonraki, i++) {
			Onceki = Onceki->Sonraki;
		}
		return Onceki;
	}

	CiftYonluListe() {
		ilk = NULL;
		miktar = 0;
	}

	int SayiMiktari(){
		return miktar;
	}

	bool BosMu() {
		return miktar == 0;
	}

	void Ekle(int item) {
		DugumEkle(miktar,item);
	}

	void DugumEkle(int index,int item) {
		if (index == 0) {
			if (index == 0) {
				ilk = new Dugum(item);
				ilk->Sonraki = ilk->Onceki = ilk;
			}
			else {
				ilk = new Dugum(item, ilk, ilk->Onceki);
				ilk->Sonraki->Onceki = ilk;
				ilk->Onceki->Sonraki = ilk;
			}
		}
		else {
			Dugum* onceki = OncekiDugumuBul(index);
			onceki->Sonraki = new Dugum(item, onceki->Sonraki, onceki);
			onceki->Sonraki->Sonraki->Onceki = onceki->Sonraki;
		}
		miktar++;
	}

	void Algorithm(int sayi) {

		int mod = 0, obeb = 0;
		if (sayi != itr.SonDugumMu()) {
			itr.SonrakiDugum();
		}
	}
	
	int IlkDugumGetir() {
		return ilk->veri;
	}

	int SonDugumGetir() {
		return ilk->Onceki->veri;
	}

	int IndexBul(int item) {
		int index = 0;
		for (Dugum* itr=ilk; index < miktar; itr = itr->Sonraki) {
			if (itr->veri == item)
				return index;
			index++;
		}
		return -1;
	}

	void Sil(int item) {
		int index = IndexBul(item);
		DugumSil(index);
	}

	void DugumSil(int index) {
		Dugum* sil;
		if (index == 0) {
			sil = ilk;
			if (miktar == 1)
				ilk = ilk->Sonraki = ilk->Onceki = NULL;
			else {
				ilk = ilk->Sonraki;
				ilk->Onceki = sil->Onceki;
				sil->Onceki->Sonraki = ilk;
			}
		}
		else {
			Dugum* onceki = OncekiDugumuBul(index);
			sil = onceki->Sonraki;
			sil->Sonraki->Onceki = onceki;
		}
		miktar--;
		delete sil;
	}

	void Temizle() {
		while (!BosMu()) {
			DugumSil(0);
		}
	}
int OBEB(int a, int b)
    {
        while (a != b)
        {
            if (a > b)
                a = a - b;
            else if (b > a)
                b = b - a;
        }
        return a;
    }
	~CiftYonluListe() {
		Temizle();
	}
};
#endif
