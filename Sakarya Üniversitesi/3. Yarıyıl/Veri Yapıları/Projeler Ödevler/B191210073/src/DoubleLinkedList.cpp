/** 
* @file DoubleLinkedList
* @description Cift yonlu bagil liste uzerinde gerceklestirilecek islemler (insert,reverse,swap vb.) yapiliyor.
* @course 1.Ogretim A Grubu
* @assignment 1.Odev
* @date 12.08.2021
* @author Tansu Uzun tansu.uzun@ogr.sakarya.edu.tr
*/

#include<iostream>
#include "DoubleLinkedList.hpp"
#include "Node.hpp"
#include <ostream>
using namespace std;

DoubleLinkedList::DoubleLinkedList()
{
	head=NULL;
	size=0;
}

Node* DoubleLinkedList::FindPreviousByPosition(int index)
{
	Node *prv=head;
	int i=1;
	for(Node *itr=head; itr->next!=NULL && i != index;itr=itr->next,i++){
		prv=prv->next;
	}
	return prv;
}

int DoubleLinkedList::count()const{
	return size;
}
bool DoubleLinkedList::isEmpty()const{
	return size==0;
}
void DoubleLinkedList::add(int& data){
	insert(size,data);
}
void DoubleLinkedList::insert(int index, int& data){
	if(index == 0){
		Node* previous;
		head = new Node(data,head,previous=NULL);
		if(head->next != NULL){
			head->next->prev = head;
		}
	}
	else
	{
		Node *prv=FindPreviousByPosition(index);
		prv->next=new Node(data,prv->next,prv);
		if(prv->next->next!=NULL){
			prv->next->next->prev=prv->next;
		}
	}
	size++;
}

Node* DoubleLinkedList::returnNode(int index){
	if(index==0) return head;
	return FindPreviousByPosition(index)->next;	
}

int DoubleLinkedList::indexOf(Node* element)
{
	int index=0;
	for(Node *itr=head;itr!=NULL;itr=itr->next){
		if(itr->data==element->data)return index;
		index++;
	}
}

void DoubleLinkedList::removeAt(int index){
	Node* del;
	if(index==0){
		del=head;
		head=head->next;
		if(head!=NULL) head->prev=NULL;
	}else{
		Node *prv=FindPreviousByPosition(index);
		del=prv->next;
		prv->next=del->next;
		if(del->next!=NULL){
			del->next->prev=prv;
		}
	}
	size--;
	delete del;
}

void DoubleLinkedList::reverse()
{
    Node *temp;
    Node *current = head;
     
    //Listenin sonuna kadar islemleri yapiyor
    while (current != NULL)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;            
        current = current->prev;
    }
     
    // Listenin yalnizca bir dugumu olmasi durumunu veya listenin bos olma durumunu kontrol ediyor
    if(temp != NULL)
        head = temp->prev;

}

void DoubleLinkedList::swap(DoubleLinkedList* list,Node* node1,Node* node2){
	
	Node* temp1;
	Node* temp2;
	Node* temp;

 	if(indexOf(node1)==0)
	{
		temp=node1->next;       
		node1->next->prev=node2;
		node2->next->prev=node1;		
		node1->next=node2->next;
		node2->next=temp;   
		list->head=node1;
		head=node2;
	}
	else if(indexOf(node1)==size-1)
	{
		temp1=node1->prev;
		node1->prev->next=node2;
		node2->prev->next=node1;
		node1->prev=node2->prev;
		node2->prev=temp1;
	}
	else
	{ 
		temp1=node1->prev;
		temp2=node2->prev;
		
		temp1->next=node2;
		temp2->next=node1;
		
		temp=node1->next;
		node1->next->prev=node2;
		node2->next->prev=node1;
		
		node1->prev=temp2;
		node2->prev=temp1;
		
		node1->next=node2->next;
		node2->next=temp;
	
	}
	
}
ostream& operator<<(ostream& screen,DoubleLinkedList& right)
{
	for(Node *itr=right.head;itr!=NULL;itr=itr->next)
	{
		screen<<itr->data;
	}
	return screen;
}


void DoubleLinkedList::clear(){
	while(!isEmpty()){
		removeAt(0);
	}
}
DoubleLinkedList::~DoubleLinkedList()
{
	clear();
}
