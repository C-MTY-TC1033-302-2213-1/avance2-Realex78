/*
	Nombre: Alex Renato Peña Herrera
	Matrícula: A01286189
	Carrera: Ingeniería en Tecnologías Computacionales (ITC)
	Fecha: 2 de junio de 2024
*/
#include "Pelicula.h"

// Constructores
Pelicula::Pelicula() : Video() {
	oscares = 100;
}

Pelicula::Pelicula(string _iD, string _titulo, int _duracion, string _genero, double _calificacion, int _oscares) : Video(_iD, _titulo, _duracion, _genero, _calificacion) {
	oscares = _oscares;
}

// Métodos modificadores
void Pelicula::setOscares(int _oscares) {
	oscares = _oscares;
}

// Métodos de acceso
int Pelicula::getOscares() {
	return oscares;
}

// Otros métodos
string Pelicula::str() {
	// Tenemos acceso directo a los atributos de la clase padre porque son Protected
	return iD + ' ' + titulo + ' ' + to_string(duracion) + ' ' + genero + ' ' + to_string(calificacion) + ' ' + to_string(oscares);
}
