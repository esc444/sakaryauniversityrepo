/**
* @file  FileProcessor.h
* @description Programın başladığı yer. Kullanıcıdan dosya ismi alır ve bu dosyadan verileri okur. 
* Verileri işler ve belirli sonuçları ekrana yazdırır.
* @course 1.Öğretim- A Grubu- Dr.Öğr.Üyesi MUHAMMED FATİH ADAK
* @assignment 1.Ödev
* @date 24.07.2023
* @author Ekrem Selçuk Çelik - ekrem.celik4@ogr.sakarya.edu.tr
*/
#include "FileProcessor.h"
#include <iostream>


int main() {
    // "Sayilar.txt" dosyasını okumak ve işlemek üzere bir dosya işleyici oluştur
    FileProcessor processor("Sayilar.txt");
    int indexA, indexB;

 // Kullanıcıdan hangi verinin yerlerinin değiştirileceğine dair girdi alır
    std::cout << "Enter Location A: ";
    std::cin >> indexA;


    std::cout << "Enter Location B: ";
    std::cin >> indexB;

// Listelerin mevcut durumunu yazdırır. Burası kontrol amaçlı eklemiştim.
    //std::cout << "Before Swap:\n";
    //processor.printAllLists();
    //processor.printTopLists();
    //processor.printBottomLists();



// Değiştirme işlemini burda gerçekleştiriyorum.
    processor.swap(indexA, indexB);



// Değiştirmeden sonra listelerin durumunu yazdırırıyorum. Kontrol amaçlı yapıyorum.
    //std::cout << "\nAfter Swap:\n";
    //processor.printAllLists();
    //processor.printTopLists();
    //processor.printBottomLists();

    //processor.printAverages();
     // Üst ve alt listelerin toplam ortalamalarını yazdır
    //std::cout << "Average at index 3: " << processor.calculateAverageAtNthIndex(3) << std::endl;
     std::cout << "Total average of upper lists: " << processor.calculateTotalAverage(true) << std::endl;
    std::cout << "Total average of lower lists: " << processor.calculateTotalAverage(false) << std::endl;
    return 0;
}
