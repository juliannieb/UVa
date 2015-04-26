#include <iostream>
#include <cstdio>
#include <map>
#include <string>

using namespace std;

string alfabeto = "abcdefghijklmnopqrstuvwxyz";
map <string, int> valores;

void llena_valores () {
	string s;
	int v1 = 1;
	int v2 = 27;
	int v3 = 352;
	int v4 = 2952;
	int v5 = 17902;
	for (int i = 0; i < 26; i++) {
		s = "";
		s.push_back(alfabeto.at(i));
		valores[s] = v1;
		v1 ++;
		for (int j = i + 1; j < 26; j++) {
			s = "";
			s.push_back(alfabeto.at(i));
			s.push_back(alfabeto.at(j));
			valores[s] = v2;
			v2++;
			for (int k = j + 1; k < 26; k++) {
				s = "";
				s.push_back(alfabeto.at(i));
				s.push_back(alfabeto.at(j));
				s.push_back(alfabeto.at(k));
				valores[s] = v3;
				v3++;
				for (int m = k + 1; m < 26; m++) {
					s = "";
					s.push_back(alfabeto.at(i));
					s.push_back(alfabeto.at(j));
					s.push_back(alfabeto.at(k));
					s.push_back(alfabeto.at(m));
					valores[s] = v4;
					v4++;
					for (int n = m + 1; n < 26; n++) {
						s = "";
						s.push_back(alfabeto.at(i));
						s.push_back(alfabeto.at(j));
						s.push_back(alfabeto.at(k));
						s.push_back(alfabeto.at(m));
						s.push_back(alfabeto.at(n));
						valores[s] = v5;
						v5++;
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