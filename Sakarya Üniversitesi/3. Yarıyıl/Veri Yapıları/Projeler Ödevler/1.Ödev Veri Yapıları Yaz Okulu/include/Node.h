/**
* @file  FileProcessor.h
* @description Düğüm (Node) sınıfını tanımlar.
* @course 1.Öğretim- A Grubu- Dr.Öğr.Üyesi MUHAMMED FATİH ADAK
* @assignment 1.Ödev
* @date 24.07.2023
* @author Ekrem Selçuk Çelik - ekrem.celik4@ogr.sakarya.edu.tr
*/
#ifndef NODE_H
#define NODE_H


class Node {
public:
    int data;    // Düğümde saklanacak veri
    Node *next; // Sonraki düğüme işaret eden pointer


    Node(int data);
};


#endif
