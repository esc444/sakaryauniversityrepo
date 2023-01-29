/** 
* @file G211210587
* @description Verilen verileri bağlı liste içine koyup yönetici ve satır listeleriyle birlikte düzenlemek.
* @course 2. Öğretim C Grubu
* @assignment 1
* @date 25.11.2022
* @author Ekrem Çelik ekrem.celik4@ogr.sakarya.edu.tr
*/

#include <iostream>
#include <fstream>
#include <string> 
#include <ostream>
#include "SatirListesi.hpp"
#include "SatirListesi.cpp"
//#include "okumayazma.hpp"
using namespace std;
void Ciz(int adet){
    for(int i=0; i< adet; i++)
        cout <<"---------  ";
    cout << endl;
}
void Bosluk(int sira){
    cout<<setw(11)<<"";

}
void Yaz(int adet){
    for(int i=0; i<8; i++)
    cout << (new int) << i <<  "  ";
    cout<<endl;
}

int main(){
    // okumayazma * veriyiOku = new okumayazma("veriler.txt");

    // SatirListesi *SatirListesi = veriyiOku->SatirListesiYaz();karıştı iyice
    int sira = 0;
while(true){
    system("cls");
    int dugumSayisi=8;

    Ciz(dugumSayisi);
    Yaz(dugumSayisi);
    Ciz(dugumSayisi);
    Yaz(dugumSayisi);
    Ciz(dugumSayisi);
    Yaz(dugumSayisi);
    return 0;
     

            }
}
