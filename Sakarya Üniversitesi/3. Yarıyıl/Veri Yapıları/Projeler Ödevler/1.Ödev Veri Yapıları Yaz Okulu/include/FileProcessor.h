/**
* @file  FileProcessor.h
* @description * Dosya İşleyici (FileProcessor) sınıfını tanımlar.
* @course 1.Öğretim- A Grubu- Dr.Öğr.Üyesi MUHAMMED FATİH ADAK
* @assignment 1.Ödev
* @date 24.07.2023
* @author Ekrem Selçuk Çelik - ekrem.celik4@ogr.sakarya.edu.tr
*/
#ifndef FILEPROCESSOR_H
#define FILEPROCESSOR_H


#include "LinkedList.h"
#include <string>


class FileProcessor {
public:
    LinkedList** lists;
    int listCount;


    FileProcessor(const std::string& fileName);// Kurucu ve Yıkıcı fonksiyonlar
    ~FileProcessor();// Kurucu ve Yıkıcı fonksiyonlar
    void swap(int indexA, int indexB); // Verilen indekslerdeki iki düğümü takas etme metodu
    // Listeler için yazdırma metodları
    void printAverages();
    void printAllLists();
    void printTopLists();
    void printBottomLists();


    double calculateAverageAtNthIndex(int index); // N'inci indeksteki ortalamayı hesaplama metodu
    int getMaxLength(); // Maksimum uzunluğu alma metodu
    double calculateTotalAverage(bool isUpper);// Toplam ortalama hesaplama metodu (üst veya alt listeler için)
};


#endif
