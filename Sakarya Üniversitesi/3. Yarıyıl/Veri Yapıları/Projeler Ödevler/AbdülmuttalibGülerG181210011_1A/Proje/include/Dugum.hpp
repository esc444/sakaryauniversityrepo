/**
* @file Dugum
* @description Öncesi veya sonrasýný belirliyor
* @course 1.Öðretim A Grubu
* @assignment 1.Ödev
* @date 16/08/2020
* @author Abdülmuttalib GÜLER
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
