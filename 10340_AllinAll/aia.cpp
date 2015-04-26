#include <stdio.h>
#include <iostream>

using namespace std;


int main () {
	string s;
	string t;
	while (cin >> s >> t) {
		int cont = 0;
		for (int i = 0; i < t.length(); i++) {
			if (t.at(i) == s.at(cont)) cont++;
			if (cont == s.length()) break;
		}
		if (cont == s.length()) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}