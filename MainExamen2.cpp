//Continuacion Segunda Fase
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

#include <sstream>
using std::stringstream;



int main(){
	int value=1;
	Stack* stack = new LinkedStack();
	int numero;
	while(value==1){
		cout<<endl;
		cout<<endl;
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
			cout<<"3--  Exit	       --"<<endl;
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
			getline(cin, nombre);

			//Obtiene el genero del usuario
			cout<<endl;
			cout<<endl;
			cout<<"Ingrese su genero: "<<endl;
			getline(cin, genero);
			//getline(cin, genero);

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
			getline(cin, contra);

			//Guardar los datos en los archivos
			/*
			ofstream UsuariosW("Usuarios.dat", std::ios::binary);
			Usuario* usuario1 = new Usuario(nombre, edad, genero, contra);
			usuario1->write(UsuariosW);
			UsuariosW.close();
			*/
			
			stack->push(new Usuario(nombre, edad, genero, contra));
			cout<<endl;
			cout<<endl;

			numero= stack->getSize();
			cout<<numero;
			
			/*

			Usuario* temp = stack->pop();
			while(temp!=NULL){
				cout<<temp->toString();
				delete temp;
				temp=stack->pop();
			}
			*/
			cout<<endl;

		}
		if (seleccion==2){
			/*
			ofstream UsuariosW("Usuarios.dat", std::ios::binary);
			for (int i = 0; i < numero; ++i){
				Usuario* temp = stack->pop();
				while(temp!=NULL){
					cout<<temp->toString();
					temp->write(UsuariosW);
					delete temp;
					temp=stack->pop();
				}
			}
			*/

			//Se ingresan los datos acumulados en el linked stack al archivo
			//Luego se procedera a hacer log in
			int sizeStack=stack->getSize();
			ofstream outPutFile;
			outPutFile.open("Test.txt", std::ios::app);
			//NUMERO ES LA VARIABLE DEL SIZE DEL STACK
			if(sizeStack!=0){
				for (int i = 0; i < numero; ++i){
					Usuario* temp = stack->pop();
					while(temp!=NULL){
						//cout<<temp->toString();
						//temp->write(UsuariosW);
						outPutFile<<temp;
						delete temp;
						temp=stack->pop();
					}
				}
			}
			//

			//LECTURA PARA LOG IN
			cout<<endl;
			cout<<endl;
			cout<<"|    ---- LOG IN -----    |"<<endl;
			string user;
			string contrauser;
			cout<<endl;
			cout<<"--->INGRESE UN NOMBRE DE USUARIO<---"<<endl;
			getline(cin, user);
			getline(cin, user);
			cout<<endl;
			cout<<"--->INGRESE LA CLAVE DE SU USER<---"<<endl;
			getline(cin, contrauser);

			//Lectura desde el archivo
			bool validadorNombre=false;
			bool validadorPass=false;
			ifstream inputFile;
			inputFile.open("Test.txt");
			if(!inputFile.is_open()){
				cout<<"Ocurrio un error con la base de datos"<<endl;
			}else{
				while(!inputFile.eof()){
					string buffer;
					getline(inputFile, buffer);
					//cout<<buffer<<endl;

					int contador_comas=0;
					
					stringstream comparador_user;
					stringstream comparador_clave;
					bool validadorP1=true;
					
					for (int i = 0; i < buffer.size(); i++){

						if (buffer[i]!=',' && validadorP1==true){
							contador_comas++;

						}
						if (buffer[i]==','){
							validadorP1=false;
						}
						
					}
					for (int j = 0; j < contador_comas; ++j){
						comparador_user<<buffer[j];
					}

					
					bool validadorP2=true;
					int contador_comas2=0;
					int numer_comas=0;
					for (int i = 0; i < buffer.size(); ++i){
						if (numer_comas==3){
							validadorP2=false;
						}
						if (validadorP2==true && numer_comas<3){
							contador_comas2++;
						}
						if (buffer[i]==','){
							numer_comas++;
						}
						
					}
					for (int j = contador_comas2; j < buffer.size(); ++j){
						//cout<<buffer[j];
						comparador_clave<<buffer[j];
					}
					

					string comparador_user_s=comparador_user.str();
					string comparador_clave_s=comparador_clave.str();

					//cout<<comparador_clave_s<<endl;
					//cout<<comparador_user_s<<endl;
					if (comparador_user_s==user){
						validadorNombre=true;
					}
					if (comparador_clave_s==contrauser){
						validadorPass=true;
					}
				}
				if (validadorNombre==true && validadorPass==true){
					cout<<"** Ha iniciado sesion **"<<endl;
					cout<<endl;
					cout<<"************************"<<endl;
					int menu_tinder;
					cout<<endl;
					int whileMenu=1;


					vector <Usuario*> usuarios_lista;
					//Enviar datos a un vector
					ifstream inputFile;
					inputFile.open("Test.txt");
					if(!inputFile.is_open()){
						cout<<"Ocurrio un error con la base de datos"<<endl;
					}else{
						while(!inputFile.eof()){
							string buffer;
							getline(inputFile, buffer);
							stringstream nombre_user;
							stringstream clave_user;
							stringstream edad;
							stringstream genero;

							int contador_comas_vector1=0;
							bool validadorVector1=true;
							for (int i = 0; i < buffer.size(); i++){

								if (buffer[i]!=',' && validadorVector1==true){
									contador_comas_vector1++;

								}
								if (buffer[i]==','){
									validadorVector1=false;
								}
						
							}
							for (int j = 0; j < contador_comas_vector1; ++j){
								nombre_user<<buffer[j];
							}

							int contador_comas_vector2=0;
							bool validadorVector2=true;
							int numer_comas_vector2=0;
							for (int i = 0; i < buffer.size(); ++i){
								if (numer_comas_vector2==2){
									validadorP2=false;
								}
								if (validadorP2==true && numer_comas<2){
									contador_comas_vector2++;
								}
								if (buffer[i]==','){
									numer_comas_vector2++;
								}
						
							}

							for (int i = contador_comas_vector1+1; i < contador_comas_vector2; ++i)
							{
								
							}


						}
					}

					while(whileMenu==1){
						cout<<"|| BIENVENIDO AL PINDER ||"<<endl;
						cout<<endl;
						cout<<"1// 	Usuarios"<<endl;
						cout<<"2// 	Agregar a lista de contactos"<<endl;
						cout<<"3//	Lista de contactos"<<endl;
						cout<<"4// 	Salir"<<endl;
						cout<<endl;
						cout<<"--- Haga una seleccion ---"<<endl;
						cin>>menu_tinder;
						while(menu_tinder<0 || menu_tinder>4){
							cout<<endl;
							cout<<"1// 	Usuarios"<<endl;
							cout<<"2// 	Agregar a lista de contactos"<<endl;
							cout<<"3//	Lista de contactos"<<endl;
							cout<<"4// 	Salir"<<endl;
							cout<<endl;
							cout<<"--- Haga una seleccion ---"<<endl;

						}

						if (menu_tinder==1){
							
						}

						if (menu_tinder==2){
							
						}

						if (menu_tinder==3){
							cout<<"SITE 403 NOT FOUND"<<endl;
						}


						if (menu_tinder==4){
							cout<<endl;
							cout<<endl;
							cout<<endl;
							cout<<"Cerrando Sesion..."<<endl;
							whileMenu=-1000;
						}
					}

				}
			}


			cout<<"--------------------------------------------------"<<endl;
			cout<<endl;
			cout<<"La sesion ha terminado"<<endl;
			cout<<endl;
			cout<<endl;
			cout<<endl;
			cout<<endl;

		}

		if (seleccion==3){
			cout<<endl;
			cout<<endl;
			cout<<"--------- EXITING ---------"<<endl;
			value=-1000;
			cout<<endl;
			cout<<endl;

		}

	}
	delete stack;
	return 0;
}