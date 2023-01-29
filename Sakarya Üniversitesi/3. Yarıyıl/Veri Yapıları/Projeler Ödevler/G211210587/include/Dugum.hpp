/** 
* @file G211210587
* @description Verilen verileri bağlı liste içine koyup yönetici ve satır listeleriyle birlikte düzenlemek.
* @course 2. Öğretim C Grubu
* @assignment 1
* @date 25.11.2022
* @author Ekrem Çelik ekrem.celik4@ogr.sakarya.edu.tr
*/
#ifndef Dugum_hpp
#define Dugum_hpp
#include <iostream>
using namespace std;

class Dugum{
public:
  Dugum(int veri);
  ~Dugum();
  int veri;
  Dugum* sonraki;

};

#endif