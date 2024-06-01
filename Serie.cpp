/*
	Nombre: Alex Renato Peña Herrera
	Matrícula: A01286189
	Carrera: Ingeniería en Tecnologías Computacionales (ITC)
	Fecha: 2 de junio de 2024
*/
#include "Serie.h"

// Constructores
Serie::Serie() {
	// Sólo vamos a inicializar cantidad
	cantidad = 0;
}

Serie::Serie(string _iD, string _titulo, int _duracion, string _genero, double _calificacion) : Video(_iD, _titulo, _duracion, _genero, _calificacion) {
	// Iniciar cantidad en cero (se añadirán los episodios mediante el método agregaEpisodio)
	cantidad = 0;
}

// Métodos modificadores
void Serie::setEpisodio(int posicion, Episodio episodio) {
	// Primero validar que exista ese episodio
	if (posicion < cantidad && posicion >= 0) {
		episodios[posicion] = episodio;
	}
}

// Cambiar el valor del atributo cantidad con el nuevo valor recibido _cantidad
void Serie::setCantidad(int _cantidad) {
	cantidad = _cantidad;
}

// Métodos de acceso
Episodio Serie::getEpisodio(int posicion) {
	// Crea un objeto del tipo Episodio y lo inicializa con el construcotr default
	Episodio epi;
	// Validar que exista el episodio solicitado (posición)
	if (posicion < cantidad && posicion >= 0) {
		return episodios[posicion];
	}

	// Si no existe se retorna un default
	return epi;
}

int Serie::getCantidad() {
	return cantidad;
}

// Otros métodos
double Serie::calculaPromedio() {
	double suma = 0;
	for (int index = 0; index < cantidad; index++) {
		suma += episodios[index].getCalificacion();
	}

	// Validar que tenga episodios
	if (cantidad > 0) {
		return suma / cantidad;
	} else {
		return 0.0;
	}
}

string Serie::str() {
	string str = Video::str() + ' ' + to_string(cantidad) + '\n';
	for (int i = 0; i < cantidad; i++) {
		str += episodios[i].str() + '\n';
	}
	return str;
}

// Agrega un episodio sólo si existe espacio
void Serie::agregaEpisodio(Episodio episodio) {
	if (cantidad < 5) {
		episodios[cantidad++] = episodio;
	}
}

void Serie::calculaDuracion() {
	int suma = 0;
	for (int index = 0; index < cantidad; index++) {
		suma += episodios[index].getTemporada();
	}
	duracion = suma;
}
