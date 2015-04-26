#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main () {
	int n;
	while (scanf("%i%*c", &n) == 1) {
		vector <string> words (n);
		string palabra;
		for (int i = 0; i < n; i++) {
			cin >> palabra;
			words[i] = palabra;
		}
		int q;
		scanf("%i%*c", &q);
		while (q--) {
			cin >> palabra;
			bool found = false;
			for (int i = 0; i < n; i++) {
				if (palabra == words[i]) {
					found = true;
					cout << palabra << " is correct" << endl;
				}
			}
			if (!found) {
				for (int k = 0; k < n; k++) {
					if (words[k].size() == palabra.size() + 1) {
						int idx_original = 0;
						int idx_palabra = 0;
						int cont = 0;
						bool error = false;
						for (idx_original; idx_original < words[k].size(); idx_original++, idx_palabra++) {
							if (words[k][idx_original] == palabra[idx_palabra]) cont++;
							else {
								if (error) break;
								else {
									error = true;
									idx_palabra--;
								}
							}
						}
						if (cont >= palabra.size()) {
							found = true;
							cout << palabra << " is a misspelling of " << words[k] << endl;
							break;
						}
					}
					else if (words[k].size() == palabra.size() - 1) {
						int idx_original = 0;
						int idx_palabra = 0;
						int cont = 0;
						bool error = false;
						for (idx_palabra; idx_palabra < palabra.size(); idx_palabra++, idx_original++) {
							if (words[k][idx_original] == palabra[idx_palabra]) cont++;
							else {
								if (error) break;
								else {
									error = true;
									idx_original--;
								}
							}
						}
						if (cont >= words[k].size()) {
							found = true;
							cout << palabra << " is a misspelling of " << words[k] << endl;
							break;
						}
					}
					else if (words[k].size() == palabra.size()) {
						int idx_original = 0;
						int idx_palabra = 0;
						int cont = 0;
						bool error = false;
						for (idx_palabra; idx_palabra < palabra.size() - 1; idx_palabra++, idx_original++) {
							//printf("%c - %c\n", words[k][idx_original], palabra[idx_palabra]);
							if (words[k][idx_original] == palabra[idx_palabra]) cont++;
							else {
								if (error) break;
								else {
									error = true;
									if (words[k][idx_original + 1] == palabra[idx_palabra] && words[k][idx_original] == palabra[idx_palabra + 1]) {
										cont++;
										idx_palabra++;
										idx_original++;
									}
									else break;
								}
							}
						}
						if (cont >= palabra.size() - 1) {
							found = true;
							cout << palabra << " is a misspelling of " << words[k] << endl;
							break;
						}

						error = false;
						for (idx_palabra; idx_palabra < palabra.size(); idx_palabra++, idx_original++) {
							if (words[k][idx_original] == palabra[idx_palabra]) cont++;
							else {
								if (error) break;
								else {
									error = true;
								}
							}
						}

						if (cont >= palabra.size() - 1) {
							found = true;
							cout << palabra << " is a misspelling of " << words[k] << endl;
							break;
						}
					}
					
				}
			}
			if (!found) {
				cout << palabra << " is unknown" << endl;
			}
		}
	}
	return 0;
}