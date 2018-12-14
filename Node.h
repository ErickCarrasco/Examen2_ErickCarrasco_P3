#ifndef NODE_H
#define NODE_H

//template <class T>
#include "Usuario.h"

class Node{
	private:
		Usuario* data;
		Node* next;
		Node* before;
	public:
		Node();
		Node(Usuario*);
		Usuario* getData();
		void setData(Usuario*);
		void setNext(Node*);
		Node* getNext();
		~Node();
	
};
#endif