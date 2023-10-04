/**
* @file  FileProcessor.h
* @description Verilen bir dosyadan iki basamaklı sayıları okuyarak bu sayıları iki farklı bağlı listeye dönüştürür.
* Bu bağlı listeleri kullanıcının girdiği değerlere göre yer değiştirir.
* Listeler yer değiştirdikten sonra, indexlerine göre ortalamalarını hesaplar ve bu ortalamaların üst ve alt kısmını bulur.
* @course 1.Öğretim- A Grubu- Dr.Öğr.Üyesi MUHAMMED FATİH ADAK
* @assignment 1.Ödev
* @date 24.07.2023
* @author Ekrem Selçuk Çelik - ekrem.celik4@ogr.sakarya.edu.tr
*/
#include "LinkedList.h"
#include <cstddef>
#include <iostream>
using namespace std;
// Yapıcı metod, yeni bir bağlı liste oluşturma
LinkedList::LinkedList() : head(nullptr), size(0) {}

// Yıkıcı metod, belleği temizleme
LinkedList::~LinkedList() {
    while (head) {
        Node* next = head->next;
        delete head;
        head = next;
    }
}

// Verilen datayı listeye ekler
void LinkedList::addNode(int data) {
    Node* node = new Node(data);
    node->next = head;
    head = node;
    size++;
}

// Listenin ortalamasını hesaplama
double LinkedList::getAverage() {
    if (size == 0) return 0.0;


    double sum = 0.0;
    Node* node = head;
    while (node) {
        sum += node->data;
        node = node->next;
    }
    return sum / size;
}

// Listenin toplamını hesaplama
int LinkedList::calculateSum() {
    Node* temp = head;
    int sum = 0;
    while (temp != NULL) {
        sum += temp->data;
        temp = temp->next;
    }
    return sum;
}

// Liste boyutunu hesaplama
int LinkedList::getCount() {
    Node* temp = head;
    int count = 0;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}
// Listeyi yazdırma
void LinkedList::printList() {
    Node* temp = head;
    while (temp != NULL) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}
// Belirtilen indexte bir düğümün olup olmadığını kontrol etme
bool LinkedList::hasNthNode(int index) {
    Node* temp = head;
    int count = 0;
    while (temp != NULL) {
        if (count == index) return true;
        count++;
        temp = temp->next;
    }
    return false;
}
// Belirtilen indexteki düğümün datasını alma
int LinkedList::getNthData(int index) {
    Node* temp = head;
    int count = 0;
    while (temp != NULL) {
        if (count == index) return temp->data;
        count++;
        temp = temp->next;
    }
    // If no node exists at this index, return 0
    return 0;
}
// Listenin sonuna düğüm ekler
void LinkedList::addNodeToEnd(int data) {
    Node* node = new Node(data);
    if (head == nullptr) {
        head = node;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = node;
    }
    size++;
}