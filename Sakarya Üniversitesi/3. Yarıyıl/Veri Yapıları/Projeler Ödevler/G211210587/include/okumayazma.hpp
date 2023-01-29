/** 
* @file G211210587
* @description Verilen verileri bağlı liste içine koyup yönetici ve satır listeleriyle birlikte düzenlemek.
* @course 2. Öğretim C Grubu
* @assignment 1
* @date 25.11.2022
* @author Ekrem Çelik ekrem.celik4@ogr.sakarya.edu.tr
*/
#ifndef okumayazma_hpp
#define okumayazma_hpp
#include <sstream>
#include <fstream>
#include <iostream>
#include "SatirListesi.hpp"
#include "Dugum.hpp"

class okumayazma {

    public:
    okumayazma(std::string);
    ~okumayazma();
    SatirListesi* SatirListesiYaz();

    private:
    std::string dosyaadi;
    int satirsay;
    SatirListesi **satirlarListe;
    void okuSatir();
};

#endif