#include <iostream>
#include <cstdio>
#include <map>
#include <string>

using namespace std;

string alfabeto = "abcdefghijklmnopqrstuvwxyz";
map <string, int> valores;

void llena_valores () {
	string s;
	int valor = 1;
	for (int i = 0; i < 26; i++) {
		s = "";
		s.push_back(alfabeto.at(i));
		valores[s] = valor;
		valor ++;
	}
	for (int i = 0; i < 26; i++) {
		for (int j = i + 1; j < 26; j++) {
			s = "";
			s.push_back(alfabeto.at(i));
			s.push_back(alfabeto.at(j));
			valores[s] = valor;
			valor++;
		}
	}
	for (int i = 0; i < 26; i++) {
		for (int j = i + 1; j < 26; j++) {
			for (int k = j + 1; k < 26; k++) {
				s = "";
				s.push_back(alfabeto.at(i));
				s.push_back(alfabeto.at(j));
				s.push_back(alfabeto.at(k));
				valores[s] = valor;
				valor++;
			}
		}
	}
	for (int i = 0; i < 26; i++) {
		for (int j = i + 1; j < 26; j++) {
			for (int k = j + 1; k < 26; k++) {
				for (int m = k + 1; m < 26; m++) {
					s = "";
					s.push_back(alfabeto.at(i));
					s.push_back(alfabeto.at(j));
					s.push_back(alfabeto.at(k));
					s.push_back(alfabeto.at(m));
					valores[s] = valor;
					valor++;
				}
			}
		}
	}
	for (int i = 0; i < 26; i++) {
		for (int j = i + 1; j < 26; j++) {
			for (int k = j + 1; k < 26; k++) {
				for (int m = k + 1; m < 26; m++) {
					for (int n = m + 1; n < 26; n++) {
						s = "";
						s.push_back(alfabeto.at(i));
						s.push_back(alfabeto.at(j));
						s.push_back(alfabeto.at(k));
						s.push_back(alfabeto.at(m));
						s.push_back(alfabeto.at(n));
						valores[s] = valor;
						valor++;
					}	
				}
			}
		}
	}

}

int main () {
	llena_valores();
	string input;
	while (cin >> input) {
		printf("%i\n", valores[input]);
	}
	return 0;
}