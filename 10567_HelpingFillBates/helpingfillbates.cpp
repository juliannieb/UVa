#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>

using namespace std;

char s[1000005];
vector < vector <int> > letras (256, vector <int> ());

int main () {
	gets(s);
	int len = strlen(s);
	for (int i = 0; i < len; i++) {
		letras[s[i]].push_back(i);
	}
	int q;
	scanf("%i%*c", &q);
	while (q--) {
		gets(s);
		len = strlen(s);
		int cont = 0;
		int lim_inf;
		bool matched = true;
		for (int i = 0; i < len; i++) {
			vector<int>::iterator low;
			low = lower_bound (letras[s[i]].begin(), letras[s[i]].end(), cont);
			if (low != letras[s[i]].end()) {
				if (!i) lim_inf = *low;
				cont = *low;
				cont++;
			}
			else {
				matched = false;
				break;
			}
		}
		if (matched) printf("Matched %i %i\n", lim_inf, cont - 1);
		else printf("Not matched\n");
	}
	return 0;
}