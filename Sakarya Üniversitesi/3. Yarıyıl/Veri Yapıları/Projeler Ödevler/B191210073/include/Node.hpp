#ifndef NODE_HPP
#define NODE_HPP

class Node{
	public:
		int data;
		Node* next;
		Node* prev;
		Node(int&,Node*,Node*);
};


#endif