/*
	Nombre: Alex Renato Peña Herrera
	Matrícula: A01286189
	Carrera: Ingeniería en Tecnologías Computacionales (ITC)
	Fecha: 2 de junio de 2024
*/
#include "Polimorfismo.h"

using namespace std;

// Constructor default - vacío
Polimorfismo::Polimorfismo() {
	// Inicializar arreglo de punteros con punteros nulos
	for (int index = 0; index < MAX_VIDEOS; index++) {
		arrPtrVideos[index] = nullptr;
	}

	// Inicializar cantidad de videos
	cantidad = 0;
}

// Métodos modificadores
void Polimorfismo::setPtrVideo(int index, Video *video) {
	// Validar index entre 0 y cantidad
	if (index < cantidad && index >= 0) {
		// Modificar el apuntador
		arrPtrVideos[index] = video;
	}
}

// Cambia el valor del atributo cantidad
// Cantidad debe ser entre 0 y MAX_VIDEOS, de lo contrario no se modifica
void Polimorfismo::setCantidad(int _cantidad) {
	// Validar el valor de _cantidad
	if (_cantidad >= 0 && _cantidad <= MAX_VIDEOS) {
		cantidad = _cantidad;
	}
}

// Métodos de acceso
Video *Polimorfismo::getPtrVideo(int index) {
	// Validar que exista el index
	if (index < cantidad && index >= 0) {
		return arrPtrVideos[index];
	}
	return nullptr;
}

int Polimorfismo::getCantidad() {
	return cantidad;
}

// Otros métodos
void Polimorfismo::leerArchivo(string _nombre) {
	Serie *arrPtrSeries[50];
	Pelicula *arrPtrPeliculas[50];
	Episodio episodio;
	fstream entrada;
	// Datos de cada columna por fila
	string row[7];
	// Line almacena línea; word almacena la palabra de line
	string line, word;
	// Inicializar cantidades en cero
	int cantidadPeliculas = 0;
	int cantidadSeries = 0;
	int iR = 0, index;
	double promedio;

	// Abrir archivo
	entrada.open(_nombre, ios::in);

	// Iterar por cada línea en entrada y almacenarla en line
	while (getline(entrada, line)) {
		// Separar por palabras
		stringstream s(line);
		// Iniciar iR en cero por cada línea
		iR = 0;

		// Extrer caracter por caracter hasta llegar a ','
		while (getline(s, word, ',')) {
			// Añadir word al arreglo row e incrementar iR para la próxima palabra
			row[iR++] = word;
		}

		// Determinar si la linea es P-Pelicula, S-Serie, E-Episodio
        if (row[0] == "P"){
			// Crear apuntador a pelicula creada con los parámetros de row usando new
			arrPtrPeliculas[cantidadPeliculas] = new Pelicula(row[1], row[2], stoi(row[3]), row[4], stod(row[5]), stoi(row[6]));
            // cout << "Pelicula" << arrPtrPeliculas[cantidadPeliculas] -> str() << endl;
			// Incrementar la cantidad de películas
            cantidadPeliculas++;
        } else if (row[0] == "S"){
            arrPtrSeries[cantidadSeries] = new Serie(row[1], row[2], stoi(row[3]), row[4], stod(row[5]));
            // cout << "Serie" << arrPtrSeries[cantidadSeries] -> str() << endl;
			cantidadSeries++;
		} else if (row[0] == "E"){
			// Calcular a que Serie le pertenece el episodio?
			index = stoi(row[1]) - 500;
			// Se agrega el episodio usando el metodo agregaEpisodio
			// Se crea el apuntador y se convierte a objeto usando el operador de indireccion
			arrPtrSeries[index] -> agregaEpisodio(*(new Episodio(row[2], stoi(row[3]), stoi(row[4]))));
			// cout << "Episodio" << arrPtrSeries[index] -> str() << endl;
		}
    }

    // fuera del ciclo
    // ya se termino de leer todo el archivo ahora se guardan los 
    // todos los apuntadores de Pelicula y Serie en el arrPtrVideo
    // copiar todos los apuntadores del arreglo de Series al arreglo de apuntadores de Video calculando su calificacionPromedio
    // ya que tiene todos los episodios

    for (int index = 0; index < cantidadSeries; index++){
        promedio = arrPtrSeries[index] -> calculaPromedio(); // calcula la calificacion de la Serie
        arrPtrSeries[index] -> setCalificacion(promedio); // cambia la calificacion de la Serie
        arrPtrSeries[index] -> calculaDuracion(); // calcula la duración de la serie
        arrPtrVideos[cantidad++] = arrPtrSeries[index];
    }

	// copiar todos los apuntadores del arreglo de Peliculas al arreglo de apuntadores de Video
	for (int index = 0; index < cantidadPeliculas; index++){
		arrPtrVideos[cantidad++] = arrPtrPeliculas[index];
	}

    /* Desplegar todo el contenido del arreglo de apuntadores de la clase Video (Base)
     - se da el POLIMORFISMO - SUPER SUPER SUPER !!,
     se ejecuta el metodo str() que corresponde al tipo del apuntador almacenado,
     no el correspondiente al tipo del arreglo
    */
	/* for (int index = 0; index < cantidad; index++){
		cout << index << " " << arrPtrVideos[index] -> str() << endl;
	} */

	entrada.close(); // cerrar el archivo
}

// Despliega todas las series y películas, al final muestra la cantidad de series y películas
void Polimorfismo::reporteInventario() {
	// Declaración de contadores
	int cantidadPeliculas = 0;
	int cantidadSeries = 0;

	// Recorrer todo el arreglo usando un for
	for (int index = 0; index < cantidad; index++) {
		cout << arrPtrVideos[index] -> str() << endl;

		// Indirección (*ptr) genera el objeto
		if (typeid(*arrPtrVideos[index]) == typeid(Pelicula)) {
			cantidadPeliculas++;
		} else if (typeid(*arrPtrVideos[index]) == typeid(Serie)) {
			cantidadSeries++;
		}
	}

	cout << "Peliculas = " << to_string(cantidadPeliculas) << endl;
	cout << "Series = " << to_string(cantidadSeries) << endl;
}

// Despliega todas las series y películas con la calificación indicada, al final muestra la cantidad que cumplieron
void Polimorfismo::reporteCalificacion(double _calificacion) {
	// Contador total
	int total = 0;

	for (int index = 0; index < cantidad; index++) {
		// Verificar que tenga la calificación deseada
		// Al ser apuntador se usa ->
		if (arrPtrVideos[index] -> getCalificacion() == _calificacion) {
			cout << arrPtrVideos[index] -> str() << endl;
			total++;
		}
	}

	// Desplegar el total fuera del for
	cout << "Total = " << to_string(total) << endl; 
}

// Despliega todas las series y películas con el género indicado, al final muestra la cantidad que cumplieron
void Polimorfismo::reporteGenero(string _genero) {
	// Contador total
	int total = 0;

	for (int index = 0; index < cantidad; index++) {
		// Verificar que tenga el género deseado
		// Al ser apuntador se usa ->
		if (arrPtrVideos[index] -> getGenero() == _genero) {
			cout << arrPtrVideos[index] -> str() << endl;
			total++;
		}
	}

	// Desplegar el total fuera del for
	cout << "Total = " << to_string(total) << endl; 
}

// Despliega todas las películas, al final muestra la cantidad de películas
void Polimorfismo::reportePeliculas() {
	// Declaración de contador
	int cantidadPeliculas = 0;

	// Recorrer todo el arreglo usando un for
	for (int index = 0; index < cantidad; index++) {
		// Indirección (*ptr) genera el objeto
		if (typeid(*arrPtrVideos[index]) == typeid(Pelicula)) {
			cout << arrPtrVideos[index] -> str() << endl;
			cantidadPeliculas++;
		}
	}

	if (cantidadPeliculas > 0) {
		cout << "Total Peliculas = " << to_string(cantidadPeliculas) << endl;
	} else {
		cout << "No peliculas" << endl;
	}
}

// Despliega todas las series, al final muestra la cantidad de películas
void Polimorfismo::reporteSeries() {
	// Declaración de contador
	int cantidadSeries = 0;

	// Recorrer todo el arreglo usando un for
	for (int index = 0; index < cantidad; index++) {
		// Indirección (*ptr) genera el objeto
		if (typeid(*arrPtrVideos[index]) == typeid(Serie)) {
			cout << arrPtrVideos[index] -> str() << endl;
			cantidadSeries++;
		}
	}

	if (cantidadSeries > 0) {
		cout << "Total Series = " << to_string(cantidadSeries) << endl;
	} else {
		cout << "No series" << endl;
	}
}