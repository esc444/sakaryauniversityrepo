/**
* @file Main.cpp
* @description Node.h başlık dosyasında tanımlanan Node yapısının kurucu fonksiyonunun implementasyonunu içeriyor.
* @course 1.Öğretim- A Grubu- Dr.Öğr.Üyesi MUHAMMED FATİH ADAK
* @assignment 2.Ödev
* @date 06.08.2023
* @author Melih Tufan Atlı- melih.atli@ogr.sakarya.edu.tr            
          Ekrem Selçuk Çelik-ekrem.celik4@ogr.sakarya.edu.tr
*/
#include "Node.h"

Node::Node(int val) : data(val), left(nullptr), right(nullptr) {}// Yapıcı fonksiyon
