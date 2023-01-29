#ifndef DOUBLELINKEDLIST_HPP
#define DOUBLELINKEDLIST_HPP

#include "Node.hpp"
#include <ostream>
using namespace std;

class DoubleLinkedList{
	private:
		Node *head;
		int size;
		Node* FindPreviousByPosition(int);
	public:
		DoubleLinkedList();
		int count()const;
		bool isEmpty()const;
		void insert(int,int&);
		void add(int&);
		int indexOf(Node*);
		Node* returnNode(int);
		void swap(DoubleLinkedList*,Node*,Node*);
		void removeAt(int);
		void clear();
		friend ostream& operator<<(ostream&,DoubleLinkedList&);
		void reverse();
		~DoubleLinkedList();
};


#endif