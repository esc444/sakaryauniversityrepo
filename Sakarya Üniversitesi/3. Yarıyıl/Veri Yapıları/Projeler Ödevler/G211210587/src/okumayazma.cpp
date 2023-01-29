#include "okumayazma.hpp"

SatirListesi* okumayazma::SatirListesiYaz();
int say=satirsay();
for(int i=0; i<say;++i){
    gec->add(this->satirlarListe[i]);
    return gec;
}