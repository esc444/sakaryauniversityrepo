/**
* @file  FileProcessor.h
* @description Bu dosya, düğüm (node) sınıfının uygulama dosyasıdır.
* Her düğümün içerisinde veri saklanır ve bir sonraki düğüme işaret eder.
* @course 1.Öğretim- A Grubu- Dr.Öğr.Üyesi MUHAMMED FATİH ADAK
* @assignment 1.Ödev
* @date 24.07.2023
* @author Ekrem Selçuk Çelik - ekrem.celik4@ogr.sakarya.edu.tr
*/
#include "Node.h"

// Node kurucu fonksiyonu, veriyi başlatır ve sonraki değeri null olarak ayarlar
Node::Node(int data) : data(data), next(nullptr) {}