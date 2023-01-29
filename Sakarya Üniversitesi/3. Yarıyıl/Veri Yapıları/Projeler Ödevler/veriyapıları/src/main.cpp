#include <iostream>
#include <fstream>
#include <string> 
#include <ostream>
#include "BagliListe.hpp"
#include "BagliListe.cpp"
using namespace std;
ifstream dosyaOku("veriler.txt");
void cizgiCizdir(int adet){
    for(int i=0; i< adet; i++)
        cout <<"---------  ";
    cout << endl;
}
void boslukBirak(int sira){
    cout<<setw(11)<<"";

}
void degerYazdir(int adet){
    for(int i=0; i<8; i++)
    cout << (new int) << i <<  "  ";
    cout<<endl;
}

int main(){
    BagliListe* veriler = new BagliListe();
    ifstream dosyaOku("veriler.txt");
	string satir = "";
	string sayi = "";
	if (dosyaOku.is_open()) {

		while (getline(dosyaOku, satir)) {
			veriler = new BagliListe();
			stringstream stream(satir);
			while (getline(stream, sayi, ' ')) {
				//cout << sayi + " ";

				int sayi1 = stoi(sayi);

			}
			//cout << endl;
			delete veriler;
		}
		dosyaOku.close();
	}
	return 0;
    
    
    int sira = 0;
while(true){
    system("cls");
    int dugumSayisi=8;

    cizgiCizdir(dugumSayisi);
    degerYazdir(dugumSayisi);
    cizgiCizdir(dugumSayisi);
    degerYazdir(dugumSayisi);
    cizgiCizdir(dugumSayisi);
    degerYazdir(dugumSayisi);
    return 0;
     

            }
}