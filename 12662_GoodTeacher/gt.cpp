#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

int main () {
	int n;
	scanf("%i%*c", &n);
	vector <string> names (n);
	for (int i = 0; i < n; i++) {
		cin >> names[i];
	}
	int q;
	scanf("%i%*c", &q);
	while (q--) {
		int p;
		scanf("%i%*c", &p);
		p -= 1;
		if (names[p] != "?") cout << names[p] << endl;
		else {
			int left = 0;
			string name_left = "";
			for (int i = p - 1; i >= 0; i--) {
				left ++;
				if (names[i] != "?") {
					name_left = names[i];
					break;
				}
			}
			int right = 0;
			string name_right = "";
			for (int i = p + 1; i < n; i++) {
				right ++;
				if (names[i] != "?") {
					name_right = names[i];
					break;
				}
			}
			if (left == right && (name_left != "" && name_right != "")) {
				cout << "middle of " << name_left << " and " << name_right << endl;
			}
			else if ((left < right && name_left != "") || name_right == "") {
				while (left--) {
					printf("right of ");
				}
				cout << name_left << endl;
			}
			else if ((left > right && name_right != "")|| name_left == "") {
				while (right--) {
					printf("left of ");
				}
				cout << name_right << endl;
			}
		}
	}
	return 0;
}