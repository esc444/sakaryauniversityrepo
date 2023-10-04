/**
* @file  FileProcessor.h
* @description * Bağlı Liste (LinkedList) sınıfını tanımlar.
* @course 1.Öğretim- A Grubu- Dr.Öğr.Üyesi MUHAMMED FATİH ADAK
* @assignment 1.Ödev
* @date 24.07.2023
* @author Ekrem Selçuk Çelik - ekrem.celik4@ogr.sakarya.edu.tr
*/
#ifndef LINKEDLIST_H
#define LINKEDLIST_H


#include "Node.h"
#include <cstddef>


class LinkedList {
public:
    Node* head;// Listenin başına bir pointer
    size_t size;

  // Kurucu ve Yıkıcı fonksiyonlar
    LinkedList();
    ~LinkedList();
    void addNode(int data); // Listenin sonuna bir düğüm ekleme metodu
    double getAverage();// Listenin ortalamasını alma metodu
    int calculateSum(); // Listenin toplamını hesaplama metodu
    int getCount();// Listenin eleman sayısını alma metodu
    void printList();// Listeyi yazdırma metodu


    bool hasNthNode(int index);// İstenilen indekste düğüm olup olmadığını kontrol etme metodu
    int getNthData(int index);// İstenilen indeksteki veriyi alma metodu
    void addNodeToEnd(int data); // Listenin sonuna bir düğüm ekleme metodu
};


#endif
