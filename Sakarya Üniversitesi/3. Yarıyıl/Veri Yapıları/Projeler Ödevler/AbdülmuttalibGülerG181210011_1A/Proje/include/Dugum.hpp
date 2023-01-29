/**
* @file Dugum
* @description �ncesi veya sonras�n� belirliyor
* @course 1.��retim A Grubu
* @assignment 1.�dev
* @date 16/08/2020
* @author Abd�lmuttalib G�LER
*/
#ifndef DUGUM_HPP
#define DUGUM_HPP

#include <iostream>
using namespace std;
struct Dugum {
	int veri;
	Dugum *Sonraki;
	Dugum *Onceki;

	Dugum(int veri, Dugum* Sonraki=NULL, Dugum* Onceki=NULL) {
		this->veri = veri;
		this->Onceki = Onceki;
		this->Sonraki = Sonraki;
	}
};
#endif
