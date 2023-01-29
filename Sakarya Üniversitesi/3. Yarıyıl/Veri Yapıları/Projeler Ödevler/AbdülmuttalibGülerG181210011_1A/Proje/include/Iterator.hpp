/**
* @file Iterator
* @description hangi dugum onun kontrolu ve �lerlemes�
* @course 1.��retim A Grubu
* @assignment 1.�dev
* @date 16/08/2020
* @author Abd�lmuttalib G�LER
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
