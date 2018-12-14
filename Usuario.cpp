#include "Usuario.h"

#include <string>
#include <iostream>

using std::endl;
using std::string;

Usuario::Usuario(){
}

Usuario::~Usuario(){

}

Usuario::Usuario(string nombre, int edad, string genero, string password){
	this->nombre=nombre;
	this->edad=edad;
	this->genero=genero;
	this->password=password;
}

string Usuario::getNombre(){
	return nombre;
}

void Usuario::setNombre(string nombre){
	this->nombre=nombre;
}

int Usuario::getEdad(){
	return edad;
}

void Usuario::setEdad(int edad){
	this->edad=edad;
}

string Usuario::getGenero(){
	return genero;
}

void Usuario::setGenero(string genero){
	this->genero=genero;
}

vector <string> Usuario::getInteres(){
	return interes;
}

void Usuario::setListaInteres(vector <string> interes){
	this->interes=interes;
}

void Usuario::addInteres(string objeto){
	interes.push_back(objeto);
}

vector <Usuario*> Usuario::getContactos(){
	return contactos;
}

void Usuario::setListaContactos(vector <Usuario*> contactos){
	this->contactos=contactos;
}

void Usuario::addContacto(Usuario* e){
	contactos.push_back(e);
}

string Usuario::getPassword(){
	return password;
}

void Usuario::setPassword(string password){
	this->password=password;
}

string Usuario::toString(){
	return "Nombre: "+ this->nombre + "\n" +  "\n" + "Genero: "+this->genero;
}

//METODOS PARA ARCHIVOS BINARIOS

ostream& operator<<(ostream& out, Usuario* user){
	out<<user->nombre<<","<<user->genero<<","<<user->edad<<","<<user->password<<endl;
	return out;
}


//Write
void Usuario::write(ofstream& out){
	int size = nombre.size();
	//Nombre
	out.write(reinterpret_cast<char*>(&size), sizeof(int));
	out.write(nombre.data(), size);

	//genero
	size=genero.size();
	out.write(reinterpret_cast<char*>(&size),sizeof(int));
	out.write(genero.data(), size);

	//Password
	size=password.size();
	out.write(reinterpret_cast<char*>(&size), sizeof(int));
	out.write(password.data(),size);

	out.write(reinterpret_cast<char*>(&edad), sizeof(int));

}

//READ
void Usuario::read(ifstream& in){
	int size;
	in.read(reinterpret_cast<char*>(&size), sizeof(int));
	//Buffer de nombre
	char nameBuffer[size+1];
	in.read(nameBuffer, size);
	nameBuffer[size]=0;
	nombre=nameBuffer;

	//Genero
	in.read(reinterpret_cast<char*>(&size), sizeof(int));
	//cout<<size

	char genBuffer[size+1];
	in.read(genBuffer, size);
	genBuffer[size]=0;
	genero=genBuffer;

	//Clave
	in.read(reinterpret_cast<char*>(&size),sizeof(int));
	char passBuffer[size+1];
	in.read(passBuffer, size);
	passBuffer[size]=0;
	password=passBuffer;

	//Edad
	
	in.read(reinterpret_cast<char*>(&edad), sizeof(int));
}
