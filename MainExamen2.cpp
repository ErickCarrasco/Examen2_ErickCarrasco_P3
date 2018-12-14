#include <iostream>
#include "LinkedStack.h"
#include "Stack.h"
#include "Usuario.h"
#include "Node.h"

using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;



int main(){
	int value=1;
	while(value==1){
		cout<<"------            Bienvenido            ----------"<<endl;
		cout<<endl;
		cout<<"1--  Crear Usuario  --"<<endl;
		cout<<"2--  Log            --"<<endl;
		cout<<"3--  Exit		   --"<<endl;
		int seleccion;
		cout<<endl;
		cout<<"--> SELECCIONE UNA OPCION <--"<<endl;
		cout<<endl;
		cin>>seleccion;
		while(seleccion<0 || seleccion>3){
			cout<<"Error in reading such data..."<<endl;
			cout<<endl;
			cout<<endl;
			cout<<endl;
			cout<<"1--  Crear Usuario  --"<<endl;
			cout<<"2--  Log            --"<<endl;
			cout<<"3--  Exit		   --"<<endl;
			cin>>seleccion;
		}
		if (seleccion==1){
			cout<<"**** Bienvenido a la creacion de usuario ****"<<endl;
			string nombre;
			string contra;
			string genero;
			int edad;

			//Obtiene el nombre del usuario
			cout<<endl;
			cout<<endl;
			cout<<"Ingrese un nombre para su usuario (Se recomienda evitar usar espacio por cuestiones de lectura)"<<endl;
			getline(cin, nombre);

			//Obtiene el genero del usuario
			cout<<endl;
			cout<<endl;
			cout<<"Ingrese su genero: "<<endl;
			getline(cin, genero);

			//Obtiene la edad
			cout<<endl;
			cout<<endl;
			cout<<"Ingrese su edad: "<<endl;
			cin>>edad;
			while(edad<18){
				cout<<"No puede ser menor de edad"<<endl;
				cin>>edad;
			}
			cout<<endl;
			cout<<endl;

			if (edad>100){
				cout<<"! La edad es cuestionable"<<endl;
			}

			//Obtiene la password del usuario
			cout<<endl;
			cout<<endl;
			cout<<"Ingrese su password: "<<endl;
			getline(cin, contra);

			//Guardar los datos en los archivos
			ofstream UsuariosW("Usuarios.dat", std::ios::binary);
			Usuario* usuario1 = new Usuario(nombre, edad, genero, contra);
			usuario1->write(UsuariosW);
			UsuariosW.close();
		}
		if (seleccion==2){
			//Leer Archivo Binario
			Usuario* usuarioLectura= new Usuario();
			ifstream usuarioR("Usuarios.dat", std::ios::binary);
			usuarioLectura->read(usuarioR);
			usuarioR.close();

			cout<<"Data leido: "<<endl<<usuarioLectura<<endl;
		}
	}

	return 0;
}