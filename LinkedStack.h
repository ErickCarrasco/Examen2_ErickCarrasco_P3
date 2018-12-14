#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H

#include "Stack.h"

#include "Node.h"

class LinkedStack:public Stack{
	private:
		Node* inicio;
	public:
		LinkedStack();
		virtual bool push(Usuario*);
		virtual Usuario* pop();
		virtual Usuario* top();
		virtual void print();
		virtual int getSize();
		~LinkedStack();
	
};

#endif