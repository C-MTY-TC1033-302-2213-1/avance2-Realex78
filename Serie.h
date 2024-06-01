/*
	Nombre: Alex Renato Peña Herrera
	Matrícula: A01286189
	Carrera: Ingeniería en Tecnologías Computacionales (ITC)
	Fecha: 2 de junio de 2024
	Reflexión: utilizé composición al hacer que un atributo sea otra clase
*/
#ifndef Serie_h
#define Serie_h

// Para herencia
#include "Video.h"
// Para composición
#include "Episodio.h"

class Serie : public Video {
	private:
		Episodio episodios[5];
		int cantidad;

	public:
		// Constructores
		Serie();
		Serie(string _iD, string _titulo, int _duracion, string _genero, double _calificacion);

		// Métodos modificadores
		void setEpisodio(int posicion, Episodio episodio);
		void setCantidad(int _cantidad);
		
		// Métodos de acceso
		Episodio getEpisodio(int posicion);
		int getCantidad();

		// Otros métodos
		double calculaPromedio();
		string str();
		void agregaEpisodio(Episodio episodio);
		void calculaDuracion();
};

#endif