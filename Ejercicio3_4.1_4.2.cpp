//Mauricio Colque Morales - CCOMP3-1 
// Ejercicio 3, 4.1 y 4.2
//Algebra abstracta

#include <iostream>
#include <cmath> //Para la funci�n de n�mero absoluto
#include <stdlib.h>
using namespace std;

string letras = "abcdefghijklmnopqrstuvwxyz";

//Para descifrar la clave de cifrado del texto
int descifrado_llave(char* letter, int intento) {
	string letras_comunes = "etaoin"; //Letras m�s altas de la frecuencia, en orden descendente
	int temp = 0; //Para empezar desde antes
	int llave = 0;
	for (int i = 0; i < letras.length(); i++) {
		temp++;
		if (letras[i] == *letter) break; 
	}

	switch (intento) {
	case 1: return abs(temp - 5);
	case 2: return abs(temp - 20);
	case 3: return abs(temp - 1);
	case 4: return abs(temp - 15);
	case 5: return abs(temp - 9);
	case 6: return abs(temp - 14);
	}
	 //Retorna la distancia entre la letra letra de frecuencia m�s alta y la m�s repetida en el texto cifrado.
	//Otras opciones en caso la frecuencia no haya coincidido.
}


// Esto es el descodificador por desplazamiento
void convertidor(string* stn, int salto) {

	int* indexes = new int[(*stn).length()];
	int total_letras = letras.length();

	//Guarda los �ndices de las letras
	for (int i = 0; i < (*stn).length(); i++) {
		for (int j = 0; j < letras.length(); j++) {
			if ((*stn)[i] == ' ') {
				indexes[i] = 100;  break;
			}
			else if (letras[j] == (*stn)[i]) {
				indexes[i] = j;  break;
			}
		}
	}

	//Convierte los �ndices con la llave adecuada
	for (int i = 0; i < (*stn).length(); i++) {
		if (indexes[i] == 100) { cout << " "; }
		else if (indexes[i] < salto) {
			cout << letras[indexes[i] + total_letras - salto];
		}
		else {
			cout << letras[indexes[i] - salto];
		}
	}

	delete[] indexes; //Libera la memoria del array de �ndices
}


//Cifrado por desplazamiento, Ejericio 3.

void descifrado_por_desplazamiento(string *sentence) {
	
	char common = '.'; //a ser reeemplazado por la letra m�s repetida
	int contador = 0; //cantidad de veces que se repite una letra
	int maximo = 0; //maxima cantidad de veces que se repitio una letra

	cout << "Texto original: \n" << *sentence << "\n\nTexto descifrado: \n";

	for (int i = 0; i < letras.length(); i++) {
		contador = 0;
		for (int j = 0; j < (*sentence).length(); j++) {
			if (letras[i] == (*sentence)[j]) {
				contador++;
			}
		}
		if (contador > maximo) {
			maximo = contador;
			common = letras[i];
		}
	}

	char most_common = common;
	int num_intentos = 0;
	int salto = 0; //La llave

	string resultado = " ";

	do {
		num_intentos++;
		salto = descifrado_llave(&most_common, num_intentos); //Halla la llave
		cout << "\n";
		convertidor(sentence, salto);
		cout << "\n�Esta oracion se entiende? (si/no): "; 
		cin >> resultado;
	} while (resultado == "no");

	cout << "\n\n-------------------------------------------\n\n";

}



void codificador(string* prueba) {

	int salto = 5; //La llave, que puede ser un n�mero aleatorio. Escog� el n�mero 5.
	
	int* indexes = new int[(*prueba).length()];
	int total_letras = letras.length();
	cout << "Texto original: " << *prueba;

	for (int i = 0; i < (*prueba).length(); i++) {
		for (int j = 0; j < (*prueba).length(); j++) {
			if ((*prueba)[i] == ' ') {
				indexes[i] = 100;  break;
			}
			else if (letras[j] == (*prueba)[i]) {
				indexes[i] = j;  break;
			}
		}
	}

	cout << "\n\nTexto cifrado: \n";

	//Parte de codificaci�n, adelanta 5 posiciones cada letra. Aplica m�dulo en caso se pase del total de letras.
	for (int i = 0; i < (*prueba).length(); i++) {
		if (indexes[i] == 100) cout << " ";
		else if (indexes[i] > 21) { //Funciona como la operaci�n m�dulo
			cout << letras[indexes[i] + salto - total_letras];
		}
		else {
			cout << letras[indexes[i] + salto ];
		}
	}
	cout << "\n\n";
}



int main() {
	//Ejercicio 3: Cifrado por desplazamiento
	//Este ejercicio usa la implementaci�n general de descodificador por desplazamiento
	cout << "____EJERCICIO 3_____________________\n";
	string oracion = "xultpaajcxitltlxaarpjhtiwtgxktghidhipxciwtvgtpilpitghlxiwiwtxgqadds";

	descifrado_por_desplazamiento(&oracion);
	

	//Ejercicio 4.1 - Codificador por desplazamiento
	cout << "\n___EJERCICIO 4.1 - CODIFICADOR POR DESPLAZAMIENTO_____________________\n";
	string texto = "a long time ago in a galaxy far away";

	codificador(&texto);

	//Ejercicio 4.2
	cout << "\n____EJERCICIO 4.2 - DECODIFICADOR POR DESPLAZMIENTO_____________________\n";
	descifrado_por_desplazamiento(&texto);


	return 0;
}


