//Ejercicio 2 - Desencriptación por sustitución
//Mauricio Colque Morales - CCOMP3-1
//Algebra abstracta

#include<iostream>
#include<string.h>
#include<iomanip> //Para que se pueda usar 'fixed' y 'setprecision()' que permiten usar cierta cantidad de decimales.
using namespace std;

string letras = "abcdefghijklmnopqrstuvwxyz";

void tabla_frecuencias(int* begin, int *end, int indice_letra_comun) {
	cout << "Tabla de frecuencias" << "\n";
	cout << "_______________________\n";
	float top_frequency =  *(begin + indice_letra_comun);
	float temporal_result = 0; //En float para que el resultado salga en decimal
	int i = -1;
	for (int *p = begin; end + 1 - p ; p++) {
		i++;
		if (*p == 0) continue;
		temporal_result = *p / top_frequency;
		cout << "| " << letras[i] << ":\t " << fixed << setprecision(3) << temporal_result << "|\n";
	}
}


void descifrado_por_sustitucion() {
	//Ejercicio 2
	string sentence1 = "lrvmnir bpr sumvbwvr jx bpr lmiwv yjeryrkbi jx qmbm wi bpr xjvni mkd ymibrut jx \n";
	string sentence2 = "irhx wi bpr riirkvr jx ymbinlmtmipw utn qmumbr dj w ipmhh but bj rhnvwdmbr bpr \n";
	string sentence3 = "yjeryrkbi jx bpr qmbm mvvjudwko bj yt wkbrusurbmbwjk lmird jk xjubt trmui jx ibndt \n";
	string sentence4 = "wb wi kjb mk rmit bmiq bj rashmwk rmvp yjeryrkb mkd wbi iwokwxwvmkvr mkd ijyr ynib \n";
	string sentence5 = "urymwk nkrashmwkrd bj ower m vjyshrbr rashmkmbwjk jkr cjnhd pmer bj lr fnmhwxwrd \n";
	string sentence6 = "mkd wkiswurd bj invp mk rabrkb bpmb pr vjnhd urmvp bpr ibmbr jx rkhwopbrkrd ywkd \n";
	string sentence7 = "vmsmlhr jx urvjokwgwko ijnkdhrii ijnkd mkd ipmsrhrii ipmsr w dj kjb drry ytirhx \n";
	string sentence8 = "bpr xwkmh mnbpjuwbt lnb yt rasruwrkvr cwbp qmbm pmi hrxb kj djnlb bpmb bpr xjhhjcwko \n";
	string sentence9 = "wi bpr sujsru msshwvmbwjk mkd wkbrusurbmbwjk w jxxru yt bprjuwri wk bpr pjsr bpmb \n";
	string sentence10 = "bpr riirkvr jx jqwkmcmk qmumbr cwhh urymwk wkbmvb";

	string sentences[10] = { sentence1, sentence2, sentence3, sentence4, sentence5, sentence6, sentence7, sentence8, sentence9,
							sentence10 };

	//Juntarlo todo en una sola string
	for (int i = 1; i < 10; i++) {
		sentence1 += sentences[i];
	}

	cout << "\n";

	int indice_letra_comun = 0; //Hallar el indice de la letra más repetida
	int contador = 0; //Para ver las repeticiones de cada letra
	int maximo = 0; //Guarda la cantidad más repetida

	int frecuencias[26];

	for (int i = 0; i < letras.length();i++) {
		contador = 0;
		for (int j = 0; j < sentence1.length(); j++) {
			if (letras[i] == sentence1[j]) {
				contador++;
			}
		}

		if (contador > maximo) {
			maximo = contador;
			indice_letra_comun = i;
		}
		frecuencias[i] = contador;
	}

	//Parte de las frecuencias
	tabla_frecuencias(&frecuencias[0], &frecuencias[25], indice_letra_comun);
	
	//Reemplazando en intentando. Empecé con la letra 'e' y con las letras 'th'.
	for (int i = 0; i < sentence1.length(); i++) {
		if (sentence1[i] == 'r') cout << "e";
		else if (sentence1[i] == 'b') cout << "t";
		else if (sentence1[i] == 'p') cout << "h";
		else if (sentence1[i] == 'm') cout << "a";

		else if (sentence1[i] == 'k') cout << "n";
		else if (sentence1[i] == 'j') cout << "o";

		//Llegado a este punto ya fue más sencillo descifrar el resto.
		else if (sentence1[i] == 'x') cout << "f";
		else if (sentence1[i] == 'i') cout << "s";
		else if (sentence1[i] == 'a') cout << "x";
		else if (sentence1[i] == 'v') cout << "c";
		else if (sentence1[i] == 'l') cout << "b";
		else if (sentence1[i] == 't') cout << "y";
		else if (sentence1[i] == 'w') cout << "i";
		//Aquí ya tuve la idea de cómo iba el texto
		else if (sentence1[i] == 'q') cout << "k";
		else if (sentence1[i] == 's') cout << "p";
		else if (sentence1[i] == 'h') cout << "l";
		else if (sentence1[i] == 'n') cout << "u";
		else if (sentence1[i] == 'u') cout << "r";
		else if (sentence1[i] == 'y') cout << "m";
		else if (sentence1[i] == 'e') cout << "v";
		else if (sentence1[i] == 'o') cout << "g";
		else if (sentence1[i] == 'c') cout << "w";
		else if (sentence1[i] == 'f') cout << "q";

		else {
			cout << sentence1[i];
		}
	}
}

int main() {
	
	cout << "EJERCICIO 2: DESCIFRADO POR SUSTITUCION___________________\n\n";
	descifrado_por_sustitucion();
	
	cout << "\n";

	return 0;
}
