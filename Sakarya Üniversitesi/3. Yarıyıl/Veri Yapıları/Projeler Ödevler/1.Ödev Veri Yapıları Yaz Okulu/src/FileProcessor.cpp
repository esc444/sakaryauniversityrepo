/**
* @file  FileProcessor.h
* @description Verilen bir dosyadan iki basamaklı sayıları okuyarak bu sayıları iki farklı bağlı listeye dönüştürür.
Bu bağlı listeleri kullanıcının girdiği değerlere göre yer değiştirir.
 Listeler yer değiştirdikten sonra, indexlerine göre ortalamalarını hesaplar ve bu ortalamaların üst ve alt kısmını bulur.
* @course 1.Öğretim- A Grubu- Dr.Öğr.Üyesi MUHAMMED FATİH ADAK
* @assignment 1.Ödev
* @date 24.07.2023
* @author Ekrem Selçuk Çelik - ekrem.celik4@ogr.sakarya.edu.tr
*/
#include "FileProcessor.h"
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <iostream>

// Dosyadan veri okuma ve bağlı listeye dönüştürme işlemi
FileProcessor::FileProcessor(const std::string& fileName) : lists(NULL), listCount(0) { // Reordered initialization
    std::ifstream file(fileName);
    if (!file.is_open()) throw std::runtime_error("Could not open file");

    std::string line;
    while (std::getline(file, line)) {
        LinkedList* upList = new LinkedList();
        LinkedList* downList = new LinkedList();
        std::istringstream iss(line);
        int num;
        while (iss >> num) {
            upList->addNodeToEnd(num / 10);  
            downList->addNodeToEnd(num % 10);
        }
        LinkedList** newList = new LinkedList*[listCount + 2];
        for (int i = 0; i < listCount; i++) newList[i] = lists[i];
        newList[listCount] = upList;
        newList[listCount + 1] = downList;
        delete[] lists;
        lists = newList;
        listCount += 2;
    }
    file.close();
}

// Yapıcı metod, bellek temizleme
FileProcessor::~FileProcessor() {
    for (int i = 0; i < listCount; i++) {
        delete lists[i];
    }
    delete[] lists;
}

// İki index arasında yer değiştirme
void FileProcessor::swap(int indexA, int indexB) {
    if (indexA < 0 || indexA >= listCount / 2 || indexB < 0 || indexB >= listCount / 2)
        throw std::runtime_error("Invalid indices");
    LinkedList* temp = lists[indexA * 2];
    lists[indexA * 2] = lists[indexB * 2 + 1];
    lists[indexB * 2 + 1] = temp;
}



// Tüm listelerin ortalamasını hesaplama ve yazdırma
void FileProcessor::printAverages() {
    double upSum = 0, downSum = 0;
    for (int i = 0; i < listCount; i += 2) {
        upSum += lists[i]->getAverage();
    }
    for (int i = 1; i < listCount; i += 2) {
        downSum += lists[i]->getAverage();
    }


    std::cout << "Top: " << upSum << "\nBottom: " << downSum << std::endl;
}
void FileProcessor::printAllLists() {
    for (int i = 0; i < listCount; i++) {
        std::cout << "List " << i << ": ";
        lists[i]->printList();
    }
}
// Her bir listenin n. indexindeki elemanın ortalamasını hesaplama
double FileProcessor::calculateAverageAtNthIndex(int index) {
    double sum = 0;
    int count = 0;
    for (int i = 0; i < listCount; i++) {
        if (lists[i]->hasNthNode(index)) {
            sum += lists[i]->getNthData(index);
            count++;
        }
    }
    if (count == 0) return 0.0;
    return sum / count;
}
// En uzun listenin boyutunu hesaplama
int FileProcessor::getMaxLength() {
    int max_length = 0;
    for (int i = 0; i < listCount; i++) {
        int current_length = lists[i]->getCount();
        if (current_length > max_length) {
            max_length = current_length;
        }
    }
    return max_length;
}
// Toplam ortalama hesaplama
double FileProcessor::calculateTotalAverage(bool isUpper) {
    double total_average = 0;
    int start_index = isUpper ? 0 : 1;
    int max_length = getMaxLength();
    for (int index = 0; index < max_length; index++) {
        double sum = 0;
        int count = 0;
        for (int i = start_index; i < listCount; i += 2) {
            if (lists[i]->hasNthNode(index)) {
                sum += lists[i]->getNthData(index);
                count++;
            }
        }
        if (count > 0) {
            total_average += (sum / count);
        }
    }
    return total_average;
}
// Tüm üst listeleri yazdırma
void FileProcessor::printTopLists() {
    for (int i = 0; i < listCount; i+=2) {
        std::cout << "Top List " << i/2 << ": ";
        lists[i]->printList();
    }
}
// Tüm alt listeleri yazdırma
void FileProcessor::printBottomLists() {
    for (int i = 1; i < listCount; i+=2) {
        std::cout << "Bottom List " << i/2 << ": ";
        lists[i]->printList();
    }
}