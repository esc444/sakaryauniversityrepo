#ifndef BagliListe_hpp
#define BagliListe_hpp
#include "Dugum.hpp"

class BagliListe{
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