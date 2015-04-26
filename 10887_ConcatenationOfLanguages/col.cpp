#include <iostream>
#include <cstdio>
#include <set>
#include <string>
#include <iterator>

using namespace std;

int main () {
	int t;
	scanf("%i%*c", &t);
	for (int i = 1; i <= t; i++) {
		set <string> a;
		set <string> b;
		int num_a, num_b;
		scanf("%i %i%*c", &num_a, &num_b);
		string s;
		while (num_a--) {
			getline(cin, s);
			a.insert(s);
		}
		while (num_b--) {
			getline(cin, s);
			b.insert(s);
		}
		set <string> c;
		for (set <string>::iterator it_a = a.begin(); it_a != a.end(); it_a++) {
			for (set <string>::iterator it_b = b.begin(); it_b != b.end(); it_b++) {
				c.insert(*it_a + *it_b);
			}
		}
		printf("Case %i: %i\n", i, c.size());
	}
	return 0;
}