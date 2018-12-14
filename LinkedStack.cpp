#include "LinkedStack.h"

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

LinkedStack::LinkedStack(){
	inicio=0;//Asignar null
}

bool LinkedStack::push(Usuario* obj){
	size++;
	//crear el nodo contenedor
	Node* newNode= new Node(obj);
	//enlazar con el siguiente nodo
	newNode->setNext(inicio);
	//enlazar el inicio al nuevo nodo
	inicio=newNode;
	//Retornar
	return true;

}

Usuario* LinkedStack::top(){
	if(inicio==0){//si el Inicio es nulo
		return 0;//retorna null
	}else{
		return inicio->getData();
	}

}

Usuario* LinkedStack::pop(){
	if(inicio==0){
		return 0;
	}else{
		//Copia del inicio
		Node* tmp=inicio;
		//enlazar inicio
		inicio=inicio->getNext();
		//Obtener el objeto a retornar
		Usuario* retValue=tmp->getData();
		//preparar para liberar el nodo que no se necesita mas
		tmp->setData(0);//Asigna null
		tmp->setNext(0);//Asigna null
		//Liberar la memoria del nodo
		delete tmp;
		//retornar
		return retValue;
		size--;
	}
}

void LinkedStack::print(){
	Node* tmp=inicio;
	cout<<"Stack: "<<endl;
	while(tmp!=0){
		//cout<<"<"<<tmp->getData()->toStringNode()<<">";
		//Moverse hacia adelante
		tmp=tmp->getNext();
	}
	cout<<endl;
}

LinkedStack::~LinkedStack(){
	delete inicio;
}

int LinkedStack::getSize(){
	return size;
}