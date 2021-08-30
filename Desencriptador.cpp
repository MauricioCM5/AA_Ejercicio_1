#include <iostream>
using namespace std;

int main() {

	int num;

	num = 5;

	int* ptr_num = &num;

	string letras = "abcdefghijklmnopqrstuvwxyz";

	string sentence1 = "lrvmnir bpr sumvbwvr jx bpr lmiwv yjeryrkbi jx qmbm wi bpr";
	string sentence2 = "xjvni mkd ymibrut jx irhx wi bpr riirkvr jx ymbinlmtmipw utn";
	string sentence3 = "qmumbr dj w ipmhh but bj rhnvwdmbr bpr yjeryrkbi jx bpr qmbm";
	string sentence4 = "mvvjudwko bj yt wkbrusurbmbwjk lmird jk xjubt trmui jx ibndt";
	string sentence5 = "wb wi kjb mk rmit bmiq bj rashmwk rmvp yjeryrkb mkd wbi";
	string sentence6 = "iwokwxwvmkvr mkd ijyr ynib urymwk nkrashmwkrd bj ower m";
	string sentence7 = "vjyshrbr rashmkmbwjk jkr cjnhd pmer bj lr fnmhwxwrd mkd";
	string sentence8 = "wkiswurd bj invp mk rabrkb bpmb pr vjnhd urmvp bpr ibmbr jx";
	string sentence9 = "rkhwopbrkrd ywkd vmsmlhr jx urvjokwgwko ijnkdhrii ijnkd mkd";
	string sentence10 = "ipmsrhrii ipmsr w dj kjb drry ytirhx bpr xwkmh mnbpjuwbt lnb";
	string sentence11 = "yt rasruwrkvr cwbp qmbm pmi hrxb kj djnlb bpmb bpr xjhhjcwko";
	string sentence12 = "wi bpr sujsru msshwvmbwjk mkd wkbrusurbmbwjk w jxxru yt";
	string sentence13 = "bprjuwri wk bpr pjsr bpmb bpr riirkvr jx jqwkmcmk qmumbr cwhh";


	string sentences[13] = { sentence1, sentence2, sentence3, sentence4, sentence5, 
							sentence6, sentence7, sentence8, sentence9,
							sentence10, sentence11, sentence12, sentence13 };

	char common = '.';
	int contador = 0;
	int maximo = 0;

	for (int i = 0; i < letras.length(); i++) {
		contador = 0;
		for (int j = 0; j < 13; j++) {
			for (int k = 0; k < sentences[j].length(); k++) {
				if (letras[i] == sentences[j][k]) {
				contador++;
			}

		}
	
		if (contador > maximo) {
			maximo = contador;
			common = letras[i];
		}

		if (contador != 0) cout << "La letra - " << letras[i] << "- : " << contador << "\n";

	}

	cout << "Letras mas repetida: " << common << ", num veces: " << maximo << "\n";


	return 0;
}

/*lrvmnir bpr sumvbwvr jx bpr lmiwv yjeryrkbi jx qmbm wi bpr
xjvni mkd ymibrut jx irhx wi bpr riirkvr jx ymbinlmtmipw utn
qmumbr dj w ipmhh but bj rhnvwdmbr bpr yjeryrkbi jx bpr qmbm
mvvjudwko bj yt wkbrusurbmbwjk lmird jk xjubt trmui jx ibndt
wb wi kjb mk rmit bmiq bj rashmwk rmvp yjeryrkb mkd wbi
iwokwxwvmkvr mkd ijyr ynib urymwk nkrashmwkrd bj ower m
vjyshrbr rashmkmbwjk jkr cjnhd pmer bj lr fnmhwxwrd mkd
wkiswurd bj invp mk rabrkb bpmb pr vjnhd urmvp bpr ibmbr jx
rkhwopbrkrd ywkd vmsmlhr jx urvjokwgwko ijnkdhrii ijnkd mkd
ipmsrhrii ipmsr w dj kjb drry ytirhx bpr xwkmh mnbpjuwbt lnb
yt rasruwrkvr cwbp qmbm pmi hrxb kj djnlb bpmb bpr xjhhjcwko
wi bpr sujsru msshwvmbwjk mkd wkbrusurbmbwjk w jxxru yt
bprjuwri wk bpr pjsr bpmb bpr riirkvr jx jqwkmcmk qmumbr cwhh*/