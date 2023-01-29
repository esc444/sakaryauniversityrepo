/** 
* @file G211210587
* @description Verilen verileri bağlı liste içine koyup yönetici ve satır listeleriyle birlikte düzenlemek.
* @course 2. Öğretim C Grubu
* @assignment 1
* @date 25.11.2022
* @author Ekrem Çelik ekrem.celik4@ogr.sakarya.edu.tr
*/
#ifndef SatirListesi_hpp
#define SatirListesi_hpp
#include<iostream>
#include "Dugum.hpp"
class SatirListesi{
    public:
    // BagliListe();
    // ~BagliListe();
    // void ekle(int veri);
    // void yazdir();
    void cizgiCizdir(int adet);
    void boslukBirak(int sira);
    void degerYazdir(int adet);

    private:
    Dugum* ilk;

};



#endif