#include <string>
#include <string.h>
#include <iostream>
#include <fstream>//filestream contiene las funciones necesarias para manejar el flujo de archivos
#include <windows.h>
#include <cstdlib>

using namespace std;
using namespace System;

int mult_sumas(int multiplicando, int multiplicador) {
	if (multiplicador == 1) {
		return multiplicando;
	}
	else if (multiplicador > 0) {
		return multiplicando + mult_sumas(multiplicando, multiplicador - 1);
	}
	else {
		return -multiplicando + mult_sumas(multiplicando, multiplicador + 1);
	}
	return 0;
}

void CreatingFile() {
	ifstream archivo; //ifstream lectura de archivos
	string texto;

	archivo.open("archivoEJ02.txt", ios::in);//abriendo el archivo en modo lectura //si queremos abrir un archivo que se encuentre en otra carpeta debemos colocar la dirección en el que se encuentre guardado.
	if (archivo.fail()) {
		cout << "No se pudo abrir el archivo";
		exit(1);
	}

	while (!archivo.eof()) {//mientras NO sea el final del archivo
		getline(archivo, texto);//copiaremos lo que hay dentro del archivo.txt y lo guardaremos en var "texto"
		cout << "Palabras en el .txt: " << endl;
		cout << texto << endl;
	}
	archivo.close(); //cerramos el archivo
}

void ReadingFile() {
	fstream archivo;
	archivo.open("archivoEJ02.txt", ios::in);
	string linea;
	char delimitador = ',';

	/****************EVALUANDO LA PALABRA*******************/

	while (archivo.good())  //
	{
		getline(archivo, linea, delimitador); // 2

	}
	archivo.close();
}
//ejercicio 3************************************************************
int AnyToAny(int number, int base, int basef) {
	int multiplicado = 1, resultado, residuo;
	while (number > 0) {
		resultado = resultado + number % 10 * multiplicado;
		multiplicado = multiplicado * base;
		number = number / 10;
		return resultado;
	}
	if (resultado > 0) {
		resultado = number % basef;
		residuo = number / basef;
		return resultado + residuo;
	}
}

/**************VARIABLES****************/

int op = 0;
string linea;
int numConvertir;

/***************************************/
int main() {
	cout << "Ingrese la opcion en el menu" << endl;
	cout << "1. Ejercicio No.01" << endl;
	cout << "2. Ejercicio No.02" << endl;
	cout << "3. Ejercicio No.03" << endl;
	cin >> op;

	switch (op) {
	case 1:
		int a, b;
		cout << "Ingrese el multiplicando: ";
		cin >> a;
		cout << "Ingrese el multiplicador: ";
		cin >> b;
		cout << a << " * " << b << " = " << mult_sumas(a, b) << endl;
		break;
	case 2:
		CreatingFile();
		ReadingFile();
		break;
	case 3:
		int number, base, basef, i = 0;
		cout << "Ingrese el numero: ";
		cin >> number;
		cout << "Ingrese su base: ";
		cin >> base;
		cout << "Ingrese su base final: " << endl;
		cin >> basef;
		//cout << "El numero en decimal de " << number << " es " << AnyToDecimalNoHex(number, base, basef) << endl;
		cout << "El numero " << number << " en base " << basef << " es " << AnyToAny(number, base, basef) << endl;




		break;
	}//llave switch
}//llave main

