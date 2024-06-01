/*
	Nombre: Alex Renato Peña Herrera
	Matrícula: A01286189
	Carrera: Ingeniería en Tecnologías Computacionales (ITC)
	Fecha: 2 de junio de 2024
	Reflexión: aprendí a utilizar funciones virtuales, claves para el polimorfismo
*/
#ifndef Video_h
#define Video_h

#include <string>
using namespace std;

class Video {
	protected:
		string iD;
		string titulo;
		int duracion;
		string genero;
		double calificacion;

	public:
		// Constructores
		Video();
		Video(string _iD, string _titulo, int _duracion, string _genero, double _calificacion);

		// Métodos modificadores
		void setId(string _iD);
		void setTitulo(string _titulo);
		void setDuracion(int _duracion);
		void setGenero(string _genero);
		void setCalificacion(double _calificacion);

		// Métodos de acceso
		string getId();
		string getTitulo();
		int getDuracion();
		string getGenero();
		double getCalificacion();

		// Otros métodos
		virtual string str();
};

#endif