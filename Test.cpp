#include<iostream>
#include<conio.h>
using namespace std;


/*
	CREAMOS LAS ESTRUCTURAS
*/

struct PersonaDoble {
	string fechanac;
	PersonaDoble *der;
	PersonaDoble *izq;
};

struct VehiculoDoble {
	int tipoVehiculo;
	string serie;
	VehiculoDoble *der;
	VehiculoDoble *izq;
};

struct ParqueoSimple {
	string serie;
	string fecha;
	int horas;
	ParqueoSimple *next;
};



