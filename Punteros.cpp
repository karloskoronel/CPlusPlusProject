#include<iostream>
#include<conio.h>
#include <ctime>
#include<stdio.h>
#include<dos.h>
using namespace std;

int entero;
int* apuntador;

int main() {

	/*entero;

	while (entero > 10) {
		cin >> entero;
		cout << endl << "entero es : " << entero << endl;
	}

	do {
		cin >> entero;
		cout << endl << "entero es : " << entero << endl;
	} while (entero > 10);


	cout << "salimos del while" << endl;
*/

	/*struct date d;
	getdate(&d);
*/


	/*time_t t = time(0);

	tm* now = localtime(&t);

	cout << now->tm_year << endl;
	cout << now->tm_mon << endl;
	cout << now->tm_mday << endl;
*/


	struct tm newtime;
	time_t now = time(0);
	localtime_s(&newtime, &now);
	int Month = 1 + newtime.tm_mon;
	cout << newtime.tm_year << endl;
	cout << newtime.tm_mon << endl;
	cout << newtime.tm_mday << endl;

	_getch();

	

}