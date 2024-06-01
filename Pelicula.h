/*
	Nombre: Alex Renato Peña Herrera
	Matrícula: A01286189
	Carrera: Ingeniería en Tecnologías Computacionales (ITC)
	Fecha: 2 de junio de 2024
	Reflexión: aprendí a heredar de otros constructores para aplicar el concepto de herencia
*/
#ifndef Pelicula_h
#define Pelicula_h

#include "Video.h"

class Pelicula : public Video {
	private:
		int oscares;

	public:
		// Constructores
		Pelicula();
		Pelicula(string _iD, string _titulo, int _duracion, string _genero, double _calificacion, int _oscares);

		// Métodos modificadores
		void setOscares(int _oscares);

		// Métodos de acceso
		int getOscares();

		// Otros métodos
		string str();
};

#endif