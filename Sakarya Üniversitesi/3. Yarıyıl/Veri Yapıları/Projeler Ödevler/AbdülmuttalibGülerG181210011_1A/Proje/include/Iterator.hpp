/**
* @file Iterator
* @description hangi dugum onun kontrolu ve ýlerlemesý
* @course 1.Öðretim A Grubu
* @assignment 1.Ödev
* @date 16/08/2020
* @author Abdülmuttalib GÜLER
*/
#ifndef ITERATOR_HPP
#define ITREATOR_HPP

#include "Dugum.hpp"

class Iterator{
public:
	Dugum* Simdiki;
	
	Iterator() {
		Simdiki = NULL;
	}

	Iterator(Dugum* dugum) {
		Simdiki = dugum;
	}

	bool SonDugumMu() {
		return Simdiki == NULL;
	}

	void SonrakiDugum() {
		if (!SonDugumMu())
			Simdiki = Simdiki->Sonraki;
	}

	void OncekiDugum() {
		if (!SonDugumMu())
			Simdiki = Simdiki->Onceki;
	}
	int SimdikiGetir() {
		return Simdiki->veri;
	}
};

#endif
