/**
* @file Node.h
* @description  İkili Arama Ağacı (BST) yapısının temel birimi olan Node yapısının
tanımını yapıyoruz bu dosyada.
* @course 1.Öğretim- A Grubu- Dr.Öğr.Üyesi MUHAMMED FATİH ADAK
* @assignment 2.Ödev
* @date 06.08.2023
* @author Melih Tufan Atlı- melih.atli@ogr.sakarya.edu.tr            
          Ekrem Selçuk Çelik-ekrem.celik4@ogr.sakarya.edu.tr
*/
#ifndef NODE_H
#define NODE_H
// Ağaç düğümü yapısının tanımı
struct Node {
    int data;// Veri
    Node* left;// Sol çocuk
    Node* right;// Sağ çocuk

    Node(int val);// Kurucu fonksiyon
};

#endif
