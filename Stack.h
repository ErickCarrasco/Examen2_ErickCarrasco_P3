#ifndef STACK_H
#define STACK_H

#include "Usuario.h"

class Stack{

	public:
		//Stack();
		virtual bool push(Usuario*)=0;
		virtual Usuario* pop()=0;
		virtual Usuario* top()=0;
		virtual void print()=0;
		virtual ~Stack();
	
};
#endif

