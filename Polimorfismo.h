/*
	Nombre: Alex Renato Peña Herrera
	Matrícula: A01286189
	Carrera: Ingeniería en Tecnologías Computacionales (ITC)
	Fecha: 2 de junio de 2024
	Reflexión: utilizé apuntadores para hacer polimorfismo de clases
*/
#ifndef Polimorfismo_h
#define Polimorfismo_h

#include <typeinfo>
#include <iostream>
#include <sstream>
#include <fstream>
#include "Pelicula.h"
#include "Serie.h"
#include "Episodio.h"
#include <stdio.h>

const int MAX_VIDEOS = 100;

class Polimorfismo {
	private:
		Video *arrPtrVideos[MAX_VIDEOS];
		int cantidad;

	public:
		// Constructor
		Polimorfismo();

		// Métodos modificadores
		void setPtrVideo(int index, Video *video);
		void setCantidad(int _cantidad);

		// Métodos de acceso
		Video *getPtrVideo(int index);
		int getCantidad();

		// Otros métodos
		void leerArchivo(string _nombre);
		void reporteInventario();
		void reporteCalificacion(double _calificacion);
		void reporteGenero(string _genero);
		void reportePeliculas();
		void reporteSeries();
};

#endif