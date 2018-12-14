execute:	LinkedStack.o	Node.o	Stack.o	Usuario.o	MainExamen2.o
	g++ Node.o	LinkedStack.o Stack.o	Usuario.o	MainExamen2.o	-o execute

LinkedStack.o: LinkedStack.h	LinkedStack.cpp
	g++ -c LinkedStack.cpp

Node.o:	Node.h	Node.cpp
	g++ -c Node.cpp

Stack.o:	Stack.h	Stack.cpp
	g++	-c Stack.cpp

Usuario.o:	Usuario.h Usuario.cpp
	g++ -c Usuario.cpp

MainExamen2.o:	MainExamen2.cpp
	g++ -c MainExamen2.cpp