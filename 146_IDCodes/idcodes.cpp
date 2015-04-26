#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>

using namespace std;

int main () {
	string s;
	while (1) {
		getline(cin, s);
		if (s.compare("#") == 0) break;
		if (next_permutation(s.begin(), s.end())) {
			cout << s << endl;
		}else cout << "No Successor" << endl;
	}
	return 0;
}