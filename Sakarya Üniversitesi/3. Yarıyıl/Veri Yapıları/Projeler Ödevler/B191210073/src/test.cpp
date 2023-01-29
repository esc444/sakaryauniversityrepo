/** 
* @file Test
* @description Dosyadan sayilari okuyup listeye atama, dugumlerin degerleri karsilastirilarak gerekli islemlerin yapilmasi vb. isleri yapiyor.
* @course 1.Ogretim A Grubu
* @assignment 1.Odev
* @date 12.08.2021
* @author Tansu Uzun tansu.uzun@ogr.sakarya.edu.tr
*/

#include <iostream>
#include <fstream>
#include <string> 
#include <ostream>
#include "DoubleLinkedList.hpp"
using namespace std;

int main(){
	
	DoubleLinkedList *liste1=new DoubleLinkedList();
	DoubleLinkedList *liste2=new DoubleLinkedList();
		 
    ifstream dosyaOku(".\\doc\\Sayilar.txt");
	string satir = "";
	string sayi1="";
	string sayi2="";
	

    if (dosyaOku.is_open())
	{
		while (getline(dosyaOku, satir))
		{
			char character = '#';
			int position = 0;
			string sayi;
			while ((position = satir.find(character)) != -1) 
			{
				//# karakterinin bulundugu indekse kadar satirdaki ilk sayi sayi1'e atiliyor
				sayi1+= satir.substr(0, position);
				//# karakterine kadar olan sayi siliniyor
				satir.erase(0, position + 1);
			}
			//Kalan sayi (#'dan sonraki sayi) sayi2 degiskenine atiliyor
			sayi2+=satir;
		}
	}
    
	dosyaOku.close();
	
	//# karakterine kadar olan ilk sayiyi uc basamakli sayilara ayiriyor ve liste1'e ekliyor
	int i=0;
	while(i!=sayi1.length()){
		int number;
	    //Uc basamakli sayi 0'la basliyorsa 0 yerine 1 yaziyor
		if(sayi1.substr(i,3).substr(0,1)=="0")
		{
		    number = stoi(sayi1.substr(i,3).replace(0,1,"1"));
		}else{ 
			number = stoi(sayi1.substr(i,3));
		}
		liste1->add(number);
		i+=3;
	}
   
   	//# karakterinden sonraki sayiyi uc basamakli sayilara ayiriyor ve liste2'ye ekliyor
	int j=0;
	 while(j!=sayi2.length()){ 
		int number;
		//Uc basamakli sayi 0'la basliyorsa 0 yerine 1 yaziyor
	    if(sayi2.substr(j,3).substr(0,1)=="0")
		{
		    number = stoi(sayi2.substr(j,3).replace(0,1,"1"));
		}else{ 
			number = stoi(sayi2.substr(j,3));
		}
		liste2->add(number);
		j+=3;
	}
	
	
	int index=0;
	//Listelerin dugumlerindeki sayilari karsilastiriyor
	while(index<liste1->count()){
		if(liste1->returnNode(index)->data > liste2->returnNode(index)->data)
		{
			liste1->reverse();
		}
		else if(liste1->returnNode(index)->data == liste2->returnNode(index)->data)
		{
			liste2->reverse();
		}
		else
		{
			liste1->swap(liste2,liste1->returnNode(index),liste2->returnNode(index));
		}
		index++;
	}
	cout<<"Sayi 1:"<<*liste1<<endl;
	cout<<"Sayi 2:"<<*liste2<<endl;			
			
	delete liste1;
	delete liste2;
	return 0;
	 
}

