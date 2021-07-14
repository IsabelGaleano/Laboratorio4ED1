

#include <iostream>
#include <stdlib.h>
#include "conio.h"
using namespace std;
long double factorial(int);

long double factorial(int n)
{
    long double fact;
    if (n == 0)
        return 1;
    else
        return n * factorial(n - 1);
}


void torresHanoi(int n, int o, int d, int aux);
void Mover_Torres(int N, int Origen, int Intermedio, int Destino);

int main() {
	cout << "*****FACTORIAL******" << endl;
	int num;
	cout << "Introduzca numero: ";
	cin >> num;
	cout << "factorial: " << factorial(num) << endl;
	system("pause");

	cout << "*****TORRES DE HANOI******" << endl;

	cout << "primera opcion" << endl;
	int n;
	cout << "Por favor ingresar la cantidad de anillos" << endl;
	cin >> n;

	torresHanoi(n, 1, 3, 2);

	cout << "segunda opcion" << endl;
	int Discos;
	cout << "\nEste programa resuelve el problema clasico de las Torres de Hanoi" << endl;
	cout << " mediante la recursion." << endl;
	cout << "\nPor favor introduzca el numero de discos que quiere mover " << endl;
	cout << " de la pila 1 a la pila 3" << endl;
	cin >> Discos;

	Mover_Torres(Discos, 1, 2, 3);
	cout << endl << endl;
	return 0;
}

void torresHanoi(int n, int o, int d, int aux) {
	if (n > 0) {
		torresHanoi(n - 1, o, aux, d);
		cout << "Se mueve el anillo desde la torre " << o << " hasta torre " << d << endl;
		torresHanoi(n - 1, aux, d, o);
	}
}

void Mover_Torres(int N, int Origen, int Intermedio, int Destino) {

	if (N > 1) {
		Mover_Torres(N - 1, Origen, Destino, Intermedio);
		cout << "\nMueve el disco " << N << " de " << Origen << " a " << Destino << endl;
		Mover_Torres(N - 1, Intermedio, Origen, Destino);
	}

	if (1 == N) // El caso limite mas sencillo se resuelve directamente
		cout << "\nMueve el disco 1 de " << Origen << " a " << Destino << endl;
}