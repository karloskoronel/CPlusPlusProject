#include<iostream>
#include<conio.h>
using namespace std;
/*
int
bool
double
*/

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
	fecha parqueoi;//fecha de inicio dia , mes , a�o hora de inicio y minuto de inicio
	fecha parqueof;//fecha de cierre dia,mes ,a�o ,hora de cierre y minuto de cierre
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

void insertarCliente(LCliente& dato) {//para pedir los datos del cliente en consola
	cout << "*DATOS DEL CLIENTE*" << endl;
	cout << "Nombres : "; fflush(stdin); gets_s(dato.nombres);
	cout << "DNI : "; fflush(stdin); gets_s(dato.dni);
	cout << "Fecha de nacimiento" << endl;
	cout << "Dia:"; cin >> dato.edad.d;
	cout << "Mes:"; cin >> dato.edad.m;
	cout << "Anio:"; cin >> dato.edad.a;
	cout << endl;
}
void insertarParqueador(LParqueador& dato) {//insertarParqueador(Unparqueador)
	cout << "*DATOS DEL PARQUEADOR*" << endl;
	cout << "Nombres : "; fflush(stdin); gets_s(dato.nombres);
	cout << "DNI : "; fflush(stdin); gets_s(dato.dni);
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
		cout << "Placa : "; fflush(stdin); gets_s(dato.placa);
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
	case 1:cout << "Camion con remolque" << endl;
	case 2:cout << "Camion sin remolque" << endl;
	case 3:cout << "Auto" << endl;
	case 4:cout << "Bicicleta" << endl;
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

//void main() {
//	LCliente datoCliente; 5
//	insertarCliente(datoCliente); copiar 5 y cambias por 8
//		datoCliente 8
//
//	insertarDI_ND(I, D, par1, par2, par3);
//
//
//
//	_getch();
//}