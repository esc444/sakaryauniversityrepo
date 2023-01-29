/** 
* @file Node
* @description Kurucu fonksiyon ile dugum olusturma islemi yapiliyor.
* @course 1.Ogretim A Grubu
* @assignment 1.Odev
* @date 12.08.2021
* @author Tansu Uzun tansu.uzun@ogr.sakarya.edu.tr
*/

#include<iostream>
#include "Node.hpp"
using namespace std;

Node::Node(int& data,Node* next=NULL,Node* prev=NULL){
	this->data=data;
	this->next=next;
	this->prev=prev;
}