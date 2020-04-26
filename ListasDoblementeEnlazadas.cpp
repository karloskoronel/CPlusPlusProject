#include<iostream>
#include<conio.h>
using namespace std;
struct nodoD {
	int dato;
	nodoD* izq, * der;
};

void insertarID(nodoD*& I, nodoD*& D, int dato) {
	nodoD* aux = new nodoD;
	aux->dato = dato;
	aux->der = aux->izq = NULL;
	if (I == NULL && D == NULL)I = D = aux;
	else {
		D->der = aux;
		aux->izq = D;
		D = aux;
	}
}

//void insertarDI(nodoD*& I, nodoD*& D, int dato) {
//	nodoD* aux = new nodoD;
//	aux->dato = dato;
//	aux->der = aux->izq = NULL;
//	if (I == NULL && D == NULL)I = D = aux;
//	else {
//		I->izq = aux;
//		aux->der = I;
//		I = aux;
//	}
//}
void imprimirID(nodoD* I) {
	cout << "Nulo -> ";
	for (nodoD* i = I; i != NULL; i = i->der) {
		cout << i->dato << " -> ";
	}
	cout << "NULO\n";
}
void imprimirDI(nodoD* D) {
	cout << "Nulo -> ";
	for (nodoD* i = D; i != NULL; i = i->izq) {
		cout << i->dato << " -> ";
	}
	cout << "NULO\n";
}
bool buscarID(nodoD* I, int dato) {
	bool est = false;
	for (nodoD* i = I; i != NULL; i = i->der) {
		if (i->dato == dato)est = true;
	}
	return est;
}
void eliminarID(nodoD*& I, nodoD*& D, int dato) {
	if (buscarID(I, dato)) {
		nodoD* E;
		for (E = I; E->dato != dato; E = E->der);
		if (E == I) {
			if (E == D) {//opcion 4 -- indica 1 solo Nodo
				I = D = NULL;
			}
			else {//opcion 3 E==I
				I = I->der;
				I->izq = NULL;
				E->der = E->izq = NULL;
			}
		}
		else {
			if (E == D) {//opcion 2 E==D
				D = D->izq;
				D->der = NULL;
				E->der = E->izq = NULL;
			}
			else {//opcion 1 E!=I && E!=D
				E->izq->der = E->der;
				E->der->izq = E->izq;
				E->der = E->izq = NULL;
			}
		}
	}
	else cout << "No existe\n";
}

//void main() {
//	nodoD* Izq = new nodoD; nodoD* Der = new nodoD;
//	Izq = Der = NULL;
//	insertarID(Izq, Der, 5);
//	insertarID(Izq, Der, 15);
//	insertarID(Izq, Der, 25);
//	imprimirID(Izq);
//	imprimirDI(Der);
//	eliminarID(Izq, Der, 15);
//	cout << "\nEliminacion" << endl;
//	imprimirID(Izq);
//	imprimirDI(Der);
//	_getch();
//}
