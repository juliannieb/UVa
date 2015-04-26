#include <iostream>
#include <stdio.h>
#include <map>
#include <string>

using namespace std;

int main () {
	int p, g;
	while (scanf("%i%*c%i%*c", &p, &g) == 2) {
		map <string, int> parties;
		string party;
		int value;
		while (p--) {
			cin >> party;
		    int x, i, f;
			scanf("%d.%d", &i, &f);
			value = i * 10 + f;
		    parties[party] = value;
		}

		for (int i = 1; i <= g; i++) {
			int total = 0.0;
			int n;
			party = ":)";
			while (party.compare(">") != 0 && party.compare("<") != 0 && party.compare(">=") != 0 && party.compare("<=") != 0 && party.compare("=") != 0) {
				cin >> party;
				if (party.compare("+") != 0) total += parties[party];
			}
			cin >> n;
			n *= 10;
			if (party.compare(">") == 0) {
				if (total > n) printf("Guess #%i was correct.\n", i);
				else printf("Guess #%i was incorrect.\n", i);
			} else if (party.compare("<") == 0) {
				if (total < n) printf("Guess #%i was correct.\n", i);
				else printf("Guess #%i was incorrect.\n", i);
			} else if (party.compare("<=") == 0) {
				if (total <= n) printf("Guess #%i was correct.\n", i);
				else printf("Guess #%i was incorrect.\n", i);
			} else if (party.compare(">=") == 0) {
				if (total >= n) printf("Guess #%i was correct.\n", i);
				else printf("Guess #%i was incorrect.\n", i);
			} else if (party.compare("=") == 0) {
				if (total == n) printf("Guess #%i was correct.\n", i);
				else printf("Guess #%i was incorrect.\n", i);
			}
			
		}
	}
	return 0;
}