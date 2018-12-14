#include "Usuario.h"

#include <string>
#include <iostream>

using namespace std;

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