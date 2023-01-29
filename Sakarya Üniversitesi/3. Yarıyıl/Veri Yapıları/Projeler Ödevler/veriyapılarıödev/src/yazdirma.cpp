#include <iostream>
#include <iomanip>
using namespace std;

void cizgiCizdir(int adet){
    for(int i=0: i< adet: i++)
        cout <<"---------  ";

    cout << endl;

}
void boslukBirak(int sira){
    cout<<setw(11*sira)<<"";

}
void degerYazdir(int adet){
    for(int i=0; i< adet; i++)
    cout << (new int) << i <<  "  ";
    cout<<endl;
}




int main(){
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

            }
}