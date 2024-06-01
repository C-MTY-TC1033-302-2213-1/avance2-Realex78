/*
	Nombre: Alex Renato Peña Herrera
	Matrícula: A01286189
	Carrera: Ingeniería en Tecnologías Computacionales (ITC)
	Fecha: 2 de junio de 2024
	Reflexión: apliqué el uso de métodos modificadores y de acceso para llegar al encapsulamiento
*/
#ifndef Episodio_h
#define Episodio_h

#include <string>
using namespace std;

class Episodio {
	private:
		string titulo;
		int temporada;
		int calificacion;

	public:
		// Constructores
		Episodio();
		Episodio(string _titulo, int _temporada, int _calificacion);

		// Métodos modificadores
		void setTitulo(string _titulo);
		void setTemporada(int _temporada);
		void setCalificacion(int _calificacion);

		// Métodos de acceso
		string getTitulo();
		int getTemporada();
		int getCalificacion();

		// Otros métodos
		string str();
};

#endif