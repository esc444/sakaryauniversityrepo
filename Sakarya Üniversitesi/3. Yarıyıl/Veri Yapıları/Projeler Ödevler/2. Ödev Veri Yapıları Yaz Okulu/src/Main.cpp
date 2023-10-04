/**
* @file Main.cpp
* @description Programın başladığı yer. Kullanıcıdan dosya ismi alır ve bu dosyadan verileri okur. 
* Verileri işler ve belirli sonuçları ekrana yazdırır.
* @course 1.Öğretim- A Grubu- Dr.Öğr.Üyesi MUHAMMED FATİH ADAK
* @assignment 2.Ödev
* @date 06.08.2023
* @author Melih Tufan Atlı- melih.atli@ogr.sakarya.edu.tr            
          Ekrem Selçuk Çelik-ekrem.celik4@ogr.sakarya.edu.tr
*/
#include "BST.h"
#include <fstream>
#include <windows.h>

int main() {
    std::ifstream inputFile("numbers.txt");// Dosyayı okumak için 
    std::string line;

 // Her satırı işler
    while (std::getline(inputFile, line)) {
        BST bestTree;
        BST::processLine(line, bestTree);
        bestTree.postorderPrint();
        Sleep(10); // 10ms bekler
    }
    inputFile.close();// Dosyayı kapatmak için
    return 0;
}
