#include<iostream>
#include<conio.h>
#include <ctime>
#include<dos.h>
#include<stdio.h>
using namespace std;


struct fecha {
	int d, m, a;
};

struct LCliente {
	
	char nombres[200], dni[200];
	fecha edad;//para saber su fecha de nacimiento 
};

struct LVehiculo {
	//TIPO 1)Camion con remolque  2)Camino sin remolque   3)Auto     4)Bicicleta
	//PARQUEO  tipo=1->ZonaA  2->ZonaB  3->ZonaC 4->ZonaD
	//UBICACION 1  2  3  4 .....usando cada contador de cada tipo de vehiculo
	int tipo, ubicacion;
	char placa[200], serie[200], zonaparqueo[200];
};

struct LParqueador {
	char nombres[200], dni[200];
	fecha edad;
};

struct LRegistro_parqueo {
	fecha parqueoi;//fecha de inicio dia , mes , año hora de inicio y minuto de inicio
	fecha parqueof;//fecha de cierre dia,mes ,año ,hora de cierre y minuto de cierre
	int hora_i, min_i, hora_f, min_f;//hora y min de inicio     hora y min de cierre
	LCliente elcliente;
	LVehiculo elvehiculo;
	LParqueador elparqueador;
	double monto;
};


struct nodo {
	LRegistro_parqueo registro;
	nodo *puntero;
};

struct nodoD {
	LCliente cliente;
	LParqueador parqueador;
	LVehiculo vehiculo;
	nodoD* izq, * der;
};



nodo* Ini; nodo* Fin;//nodos de la lista simple

nodoD* I; nodoD* D;//nodos de la lista doble

int contA = 0, contB = 0, contC = 0, contD = 0;

void insertarID_ND(nodoD*& Ix, nodoD*& Dx, LCliente cliente, LParqueador parqueador, LVehiculo vehiculo) {
	nodoD* aux = new nodoD;
	aux->cliente = cliente;
	aux->parqueador = parqueador;
	aux->vehiculo = vehiculo;
	aux->izq = aux->der = NULL;

	if (Ix == NULL && Dx == NULL)Ix = Dx = aux;

	else {
		aux->izq = Dx;
		Dx->der = aux;
		Dx = aux;
	}
}

void insertarDI_ND(nodoD*& I, nodoD*& D, LCliente cliente, LParqueador parqueador, LVehiculo vehiculo) {
	nodoD* aux = new nodoD;
	aux->cliente = cliente;
	aux->parqueador = parqueador;
	aux->vehiculo = vehiculo;
	aux->izq = aux->der = NULL;
	if (I == NULL && D == NULL)I = D = aux;
	else {
		I->izq = aux;
		aux->der = I;
		I = aux;
	}
}

// insertar en una lista simple de parqueo
void insertar_N(nodo*& ini, LRegistro_parqueo registro) {
	nodo* aux = new nodo;
	aux->registro = registro;
	aux->puntero = NULL;
	if (ini == NULL) ini = aux;
	else {
		aux->puntero = ini;
		ini = aux;
	}
}

// buscar por placa o serie de vehiculo
nodo* buscarRegistroParqueo(nodo*& punteroBusqueda, char placa[], char serie[]) {
	if (punteroBusqueda != NULL)
	 {
		bool siguienteEncontrado = false;
		while (punteroBusqueda != NULL && !siguienteEncontrado) {
			char placaVehiculo[200], serieVehiculo[200];
			strcpy_s(placaVehiculo, punteroBusqueda->registro.elvehiculo.placa);
			strcpy_s(serieVehiculo, punteroBusqueda->registro.elvehiculo.serie);
			if (!(strcmp(placa,"No tiene")==0 && strcmp(serie,"No tiene")==0)) {
				
				if (strcmp(placaVehiculo, placa) == 0 || strcmp(serieVehiculo, serie) == 0) {
					siguienteEncontrado = true;
				}
				else {
					punteroBusqueda = punteroBusqueda->puntero;
				}
			}
			else {
				if (strcmp(placaVehiculo, "No tiene") == 0 && strcmp(serieVehiculo, "No tiene") == 0) {
					siguienteEncontrado = true;
				}
				else {
					punteroBusqueda = punteroBusqueda->puntero;
				}
			}
		}
	}
	return punteroBusqueda;
}




void insertarCliente(LCliente& dato) {//para pedir los datos del cliente en consola
	cout << "*DATOS DEL CLIENTE*" << endl;
	cout << "Nombres : "; while (fgetc(stdin) != '\n'); gets_s(dato.nombres);
	cout << "DNI : "; ; gets_s(dato.dni);
	cout << "Fecha de nacimiento" << endl;
	cout << "Dia:"; cin >> dato.edad.d;
	cout << "Mes:"; cin >> dato.edad.m;
	cout << "Anio:"; cin >> dato.edad.a;
	cout << endl;
}

void insertarParqueador(LParqueador& dato) {//insertarParqueador(Unparqueador)
	cout << "*DATOS DEL PARQUEADOR*" << endl;
	cout << "Nombres : "; while (fgetc(stdin) != '\n'); gets_s(dato.nombres);
	cout << "DNI : ";  gets_s(dato.dni);
	cout << "Fecha de nacimiento" << endl;
	cout << "Dia:"; cin >> dato.edad.d;
	cout << "Mes:"; cin >> dato.edad.m;
	cout << "Anio:"; cin >> dato.edad.a;
	cout << endl;
}

void insertarVehiculo(LVehiculo& dato) {
	cout << "*DATOS DEL VEHICULO*" << endl;
	cout << "TIPO DE VEHICULO" << endl;
	cout << "1)Camion con remolque    2)Camion sin remolque    3)Auto    4)Bicicleta" << endl;

	do {
		cout << "Ingrese el numero:"; cin >> dato.tipo;
	} while (!(0 < dato.tipo && dato.tipo <= 4));

	if (dato.tipo != 4) {
		cout << "Placa : "; while (fgetc(stdin) != '\n'); gets_s(dato.placa);
		cout << "Serie : "; fflush(stdin); gets_s(dato.serie);
		cout << "Zona de parqueo : ";
		switch (dato.tipo) {
		case 1:
			fflush(stdin);
			strcpy_s(dato.zonaparqueo, "Zona A");
			cout << dato.zonaparqueo << endl;
			contA++;
			cout << "Ubicacion : espacio " << contA << endl;
			dato.ubicacion = contA;
			break;
		case 2:
			fflush(stdin);
			strcpy_s(dato.zonaparqueo, "Zona B");
			cout << dato.zonaparqueo << endl;
			contB++;
			cout << "Ubicacion : espacio " << contB << endl;
			dato.ubicacion = contB;
			break;
		case 3:
			fflush(stdin);
			strcpy_s(dato.zonaparqueo, "Zona C");
			cout << dato.zonaparqueo << endl;
			contC++;
			cout << "Ubicacion : espacio " << contC << endl;
			dato.ubicacion = contC;
			break;
		}
	}
	else {
		cout << "Placa : ";
		fflush(stdin); strcpy_s(dato.placa, "No tiene");
		cout << dato.placa << endl;
		cout << "Serie : ";
		fflush(stdin); strcpy_s(dato.serie, "No tiene");
		cout << dato.serie << endl;
		cout << "Zona de parqueo : ";
		fflush(stdin); strcpy_s(dato.zonaparqueo, "Zona D");
		cout << dato.zonaparqueo << endl;
		contD++;
		cout << "Ubicacion : espacio " << contD << endl;
		dato.ubicacion = contD;
	}
}

void insertarRegistro(LRegistro_parqueo& registro, LCliente cliente, LParqueador parqueador, LVehiculo vehiculo) {
	registro.elcliente = cliente;//LCliente charles    insertarRegistro(dummar,charles,.....) 
	registro.elparqueador = parqueador;
	registro.elvehiculo = vehiculo;
	cout << "*DATOS DEL REGISTRO DE PARQUEO*" << endl;
	cout << "Cliente : " << registro.elcliente.nombres << endl;
	cout << "Parqueador : " << registro.elparqueador.nombres << endl;
	cout << "Vehiculo : ";
	switch (registro.elvehiculo.tipo)
	{
	case 1:cout << "Camion con remolque" << endl; break;
	case 2:cout << "Camion sin remolque" << endl; break;
	case 3:cout << "Auto" << endl; break;
	case 4:cout << "Bicicleta" << endl; break;
	}
	cout << "FECHA DE REGISTRO" << endl;
	cout << "INICIO DE REGISTRO" << endl;
	cout << "Dia : "; cin >> registro.parqueoi.d;
	cout << "Mes : "; cin >> registro.parqueoi.m;
	cout << "Anio : "; cin >> registro.parqueoi.a;
	cout << "Hora : "; cin >> registro.hora_i;
	cout << "Minutos : "; cin >> registro.min_i;

	cout << "FIN DE REGISTRO" << endl;
	cout << "Dia : "; cin >> registro.parqueof.d;
	cout << "Mes : "; cin >> registro.parqueof.m;
	cout << "Anio : "; cin >> registro.parqueof.a;
	cout << "Hora : "; cin >> registro.hora_f;
	cout << "Minutos : "; cin >> registro.min_f;
}



/* ------------ FUNCIONES PARA EL SEGUNDO PROBLEMA - calcular recaudado por fechas ----------------- */

// funcion auxiliar que convierte una fecha a un numero aaaammdd
int fechaANumero(fecha f) {
	int numero = f.a * 10000 + (100 + f.m) * 100 + (100 + f.d) - 10100;
	return numero;
}

int restarFechas(fecha fechaMayor, fecha fechaMenor) {
	//  suponemos que todos los años tienen 360 dias
	// suponemos que todos los meses tienen 30 dias
	int dias = (fechaMayor.a - fechaMenor.a) * 360;
	dias = dias + (fechaMayor.m - fechaMenor.m) * 30;
	dias = dias + (fechaMayor.d - fechaMenor.d);

	return dias;
}

double precioTipoVehiculo(int tipo) {
	// Precio por hora en cada Zona(en soles) :
		// zonaA: 10 --- zonaB: 8 --- zonaC: 5 --- zonaD: 3
	double precio = 0.0;
	switch (tipo) {
	case 1: precio = 10.0; break;
	case 2: precio = 8.0; break;
	case 3:precio = 5.0; break;
	case 4:precio = 3.0; break;
	}
	return precio;
}

void consultaRecaudadoTotalVehiculos(fecha fini, fecha ffin) {
	double monto = 0;
	int inicioBusqueda = fechaANumero(fini);
	int finBusqueda = fechaANumero(ffin);

	nodo* recorreLista = Ini;
	while (recorreLista != NULL) {

		int fechaIni = fechaANumero(recorreLista->registro.parqueoi);
		int fechaFin = fechaANumero(recorreLista->registro.parqueof);
		double parcial = 0;
		double horas = 0.0;
		if ((inicioBusqueda <= fechaIni && fechaIni <= finBusqueda) || (inicioBusqueda <= fechaFin && fechaFin <= finBusqueda))
		{

			if (fechaIni < inicioBusqueda && fechaFin <= finBusqueda) {
				int dias = restarFechas(recorreLista->registro.parqueof, fini) - 1;
				horas = dias * 24 + recorreLista->registro.hora_f + (recorreLista->registro.min_f / 60);

			}

			if (inicioBusqueda <= fechaIni && finBusqueda < fechaFin) {
				int dias = restarFechas(ffin, recorreLista->registro.parqueoi) - 1;
				horas = dias * 24 + (24 - recorreLista->registro.hora_i + (recorreLista->registro.min_i / 60));
			}


			if (inicioBusqueda <= fechaIni && fechaFin <= finBusqueda) {
				int dias = restarFechas(recorreLista->registro.parqueof, recorreLista->registro.parqueoi) - 1;
				horas = dias * 24 + (24 - recorreLista->registro.hora_i + (recorreLista->registro.min_i / 60)) + (recorreLista->registro.hora_f + (recorreLista->registro.min_f / 60));
			}

			parcial = horas * precioTipoVehiculo(recorreLista->registro.elvehiculo.tipo);

			monto = monto + parcial;
		}

		cout << "Tipo vehiculo : " << recorreLista->registro.elvehiculo.tipo << " \t Zona: " << recorreLista->registro.elvehiculo.zonaparqueo << endl;
		cout << "Horas : " << horas << " \t Precio Hora: " << precioTipoVehiculo(recorreLista->registro.elvehiculo.tipo) << endl;
		cout << "Monto Parqueo : " << parcial << endl;

		recorreLista = recorreLista->puntero;
	}

	cout << endl << "Monto Total : " << monto << endl;

}


/* ------------ FUNCIONES PARA EL TERCER PROBLEMA - separar personas a una lista simple en orden descendente ----------------- */

struct NPersona {
	char nombres[200], dni[200];
	fecha fnac; int edad;
	NPersona* next;
};

 // cabecera del nodo personas de la lista simple
NPersona* P;


// funciones para crear una nueva lista con todas las personas
// que estan registradas en la lista doble.
int edadActual(fecha fnac) {
	// esta funcion calcula la edad hasta el dia de hoy.
	// Obtener la fecha del sistema.
	struct tm newtime;
	time_t now = time(0);
	localtime_s(&newtime, &now);

	fecha fact;
	fact.a = 1900 + newtime.tm_year;
	fact.m = newtime.tm_mon + 1;
	fact.d = newtime.tm_mday;

	int edad = fact.a - fnac.a;
	int enElAnioAct = fact.m * 100 + fact.d;
	int enElAnioNac = fnac.m * 100 + fnac.d;
	if (enElAnioAct < enElAnioNac) edad -= 1;
	return edad;
}

bool existeDNI(NPersona* p,char dni[]) {
	bool existe = false;
	NPersona* r = p;
	if (r == NULL) {
		existe = false;
	}
	else {
		while (r != NULL) {
			if (strcmp(r->dni, dni) == 0) {
				existe = true;
				break;
			}
			r = r->next;
		}
	}

	return existe;
}

void insertar_P(NPersona*& P, char nombres[], char dnis[], fecha fn) {
	//cout << "insertando dni: "<<dnis << endl;
	NPersona* aux = new NPersona;
	strcpy_s(aux->nombres, nombres);
	strcpy_s(aux->dni, dnis);
	aux->fnac = fn;
	//cout << "calculando edad... " << endl;
	aux->edad = edadActual(fn);
	aux->next = NULL;
	if (P == NULL) {
		//cout << "insertando primer nodo... " << endl;
		P = aux;
	}
	else {
		if (!existeDNI(P, dnis)) {
			//cout << "se inserta nodo siguiente... " << endl;
			// se inserta el nuevo valor al inicio de la lista.
			aux->next = P;
			P = aux;
		}
	}
}


// funciones para calcular el promedio de edad y la edad que mas se repite
// *no funciona si hay dos edades que mas se repiten.
double edadPromedio(NPersona* p) {
	NPersona* aux = p;
	double sumaEdad = 0;
	int count = 0;
	if (aux != NULL) {
		while (aux != NULL) {
			sumaEdad += aux->edad;
			count++;
			aux = aux->next;
		}
	}
	if (count > 0) return sumaEdad / count;
	return sumaEdad;
}

int frecuenciaEdad(NPersona* p, int edad) {
	NPersona* aux = p;
	int count = 0;
	if (aux != NULL) {
		while (aux != NULL) {
			if (aux->edad == edad)
				count++;
			aux = aux->next;
		}
	}
	return count;
}

int mayorFrecuencia(NPersona* p) {
	NPersona* aux = p;
	int edad = 0;
	int frecuencia = 0;
	if (aux != NULL) {
		while (aux != NULL) {
			if (frecuenciaEdad(p, aux->edad) > frecuencia)
				edad = aux->edad;
			aux = aux->next;
		}
	}
	return edad;
}




// funciones para crear la nueva lista ordenada de personas
void insertar_P3(NPersona*& L, char nombres[], char dnis[], fecha fn) {
	NPersona* aux = new NPersona;
	strcpy_s(aux->nombres, nombres);
	strcpy_s(aux->dni, dnis);
	aux->fnac = fn;
	aux->edad = edadActual(fn);
	aux->next = NULL;
	
	if (L == NULL) {
		L = aux;
	}
	else {
		// se crean dos punteros para que hagan el recorrido
		NPersona* Nactual = L;
		NPersona* Nsiguiente = Nactual->next;
		bool insertado = false;
		while (Nsiguiente != NULL && !insertado) {
			// se verifica si el orden para ingresar el nuevo elemento
			if ( Nsiguiente->edad < aux->edad && aux->edad <= Nactual->edad) {
				Nactual->next = aux;
				aux->next = Nsiguiente;
				insertado = true;
			}
			else {
				Nactual = Nactual->next;
				Nsiguiente = Nsiguiente->next;
			}
		}
		if (!insertado) {
			//Nactual debe apuntar al ultimo nodo disponible.
			//el valor que debemos insertar puede ser mayor o menor que la edad de Nactual
			// si es mayor no va a entrar aqui porque ya deberia haberse insertado antes (insertado = true)
			// a no ser que sea el segundo nodo a ingresarse y se colocara al inicio de la lista
			// si es menor entonces se debe insertar en Nactual->next
			if (aux->edad > Nactual->edad) {
				aux->next = L;
				L = aux;
			}
			else {
				Nactual->next = aux;
			}
		}
	}
}

NPersona* crearListaPersonaOrdenada(NPersona* P) {
	
	NPersona* L = NULL;
	NPersona* aux = P;
	double edadProm = edadPromedio(aux);
	int mayFrec = mayorFrecuencia(aux);
	while (aux != NULL) {
		if (aux->edad < edadProm && aux->edad != mayFrec) {
			insertar_P3(L, aux->nombres, aux->dni, aux->fnac);
		}

		aux = aux->next;
	}

	return L;
}


void crearListaPersonas(nodoD*& I, nodoD*& D) {
	//cout << "entramos a crearListaPersonas" << endl;
	P = NULL;
	nodoD* aux = I;
	int contador = 0;
	while (aux != NULL) {
		char nombre[200], dni[200]; fecha fn;
		
		// datos de cliente
		strcpy_s(nombre, aux->cliente.nombres);
		strcpy_s(dni, aux->cliente.dni);
		fn = aux->cliente.edad;
		insertar_P(P, nombre, dni, fn);

		// datos de parqueador
		strcpy_s(nombre, aux->parqueador.nombres);
		strcpy_s(dni, aux->parqueador.dni);
		fn = aux->parqueador.edad;
		insertar_P(P, nombre, dni, fn);

		aux = aux->der;
		/*contador++;
		cout << contador << endl;*/
	}
	//cout << "terminamos de crearListaPersonas" << endl;
}

void imprimirListaPersonas(NPersona* L) {
	NPersona* aux = L;
	cout << "*LISTA DE PERSONAS*" << endl;
	cout << "*-----------------*" << endl;
	while (aux != NULL) {
		cout << "*DNI: *" <<aux->dni<< endl;
		cout << "*NOMBRES: *" << aux->nombres << endl;
		cout << "*NACIMIENTO: *" << aux->fnac.d <<"-"<< aux->fnac.m << "-" << aux->fnac.a << endl;
		cout << "*EDAD: *" << aux->edad << endl;
		cout << endl;

		aux = aux->next;
	}
}


// ejecucion del problema 1
void registrarParqueo() {
	LCliente cliente;
	insertarCliente(cliente);
	LParqueador parqueador;
	insertarParqueador(parqueador);
	LVehiculo vehiculo;
	insertarVehiculo(vehiculo);

	insertarDI_ND(I, D, cliente, parqueador, vehiculo);

	LRegistro_parqueo parqueo;
	insertarRegistro(parqueo, cliente, parqueador, vehiculo);
	insertar_N(Ini, parqueo);
}

// ejecucion del problema 2
void calcularRecepcionado() {
	fecha fi, ff;
	cout << "*DATOS DE CONSULTA*" << endl;
	cout << "*-----------------*" << endl;
	cout << "Fecha de inicio de reporte" << endl;
	cout << "Dia:"; cin >> fi.d;
	cout << "Mes:"; cin >> fi.m;
	cout << "Anio:"; cin >> fi.a;
	cout << endl;
	cout << "Fecha de fin de reporte" << endl;
	cout << "Dia:"; cin >> ff.d;
	cout << "Mes:"; cin >> ff.m;
	cout << "Anio:"; cin >> ff.a;
	cout << endl;

	consultaRecaudadoTotalVehiculos(fi, ff);
}

// ejecucion del problema 3
void separarListas() {
	crearListaPersonas(I, D);
	P = crearListaPersonaOrdenada(P);
	imprimirListaPersonas(P);
}

void gestionar() {
	int opcion = 0;
	do {
		
		cout << endl;
		cout << "* OPERACIONES DE PARQUEO *" << endl;
		cout << "--------------------------" << endl;
		cout << "[1] : INGRESAR PARQUEO" << endl;
		cout << "[2] : CALCULAR RECEPCIONADO" << endl;
		cout << "[3] : SEPARAR LISTAS" << endl;
		cout << "[0] : SALIR" << endl;
		do {
			cout << "INGRESAR SELECCION : "; cin >> opcion;
		} while (!(0 <= opcion && opcion <= 3));

		switch (opcion) {
		case 1:	registrarParqueo(); break;
		case 2:	calcularRecepcionado(); break;
		case 3:	separarListas(); break;
		}
	} while (!(opcion == 0));

}

void main() {
	
	gestionar();
	_getch();

}
