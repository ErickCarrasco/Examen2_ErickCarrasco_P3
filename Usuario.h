#ifndef USUARIO_H
#define USUARIO_H

#include <vector>

using std::vector;

#include <string>
using std::string;

#include <fstream>
using std::ifstream;
using std::ofstream;

using std::ostream;

class Usuario{
	private:
		string nombre;
		int edad;
		string genero;
		string password;
		vector <string> interes;
		vector<Usuario*>contactos;
	public:
		Usuario();
		Usuario(string, int, string, string);
		string getNombre();
		void setNombre(string);
		int getEdad();
		void setEdad(int);
		string getGenero();
		void setGenero(string);
		vector <string> getInteres();
		void setListaInteres(vector<string>);
		void addInteres(string);
		vector <Usuario*> getContactos();
		void setListaContactos(vector<Usuario*>);
		void addContacto(Usuario*);
		string getPassword();
		void setPassword(string);
		string toString();

		void write(ofstream&);
		void read(ifstream&);
		friend ostream& operator<<(ostream&, Usuario*);

		~Usuario();
	
};
#endif