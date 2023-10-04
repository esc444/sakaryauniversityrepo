/**
* @file BST.h
* @description İkili Arama Ağacı (BST - Binary Search Tree) için sınıf tanımı yapıyoruz bu dosyada.
* @course 1.Öğretim- A Grubu- Dr.Öğr.Üyesi MUHAMMED FATİH ADAK
* @assignment 2.Ödev
* @date 06.08.2023
* @author Melih Tufan Atlı- melih.atli@ogr.sakarya.edu.tr            
          Ekrem Selçuk Çelik-ekrem.celik4@ogr.sakarya.edu.tr
*/
#ifndef BST_H
#define BST_H

#include "Node.h"
#include <stack>
#include <string>
// İkili Arama Ağacı sınıfı
class BST {
public:
    Node* root;// Ağacın kök düğümü

    BST();
    ~BST();
    void insert(int value);// Değer ekler
    int height() const;
    int sum() const;
    void postorderPrint() const;// Post-order düzeninde ağacı yazdırır

    static BST constructTreeFromStack(std::stack<int>& s);// Stack'ten ağaç oluşturur
    static void processLine(const std::string& line, BST& bestTree);
    BST(const BST& other); // Kopya yapıcı
    BST& operator=(const BST& other); // Kopya atama operatörü

private:
    Node* insertRec(Node* node, int value) const;// Recursive ekleme fonksiyonu
    int heightRec(Node* node) const;// Recursive yükseklik hesaplama fonksiyonu
    int sumRec(Node* node) const; // Recursive toplam hesaplama fonksiyonu
    void postorderRec(Node* node) const;// Recursive post-order yazdırma fonksiyonu
    void clearRec(Node* node);// Ağacı recursive olarak temizler
     Node* copyTree(const Node* source);// Bir ağacın kopyasını oluşturur
};

#endif
