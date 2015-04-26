#include <iostream>
#include <vector>
#include <stack>
using namespace std;


int main () {
	int n;
	while (cin >> n != 0) {
		if (n == 0) break;
		vector <int> orden(n);
		int flag = 1;
		while (flag) {
			for (int i = 0; i < n; i++) {
				cin >> orden[i];
				if (orden[0] == 0) {
					flag = 0;
					break;
				}
			}
			if (flag) {
				stack <int> coaches;
				for (int i = n; i > 0; i--) {
					coaches.push(i);
				}
				stack <int> estacion;
				int j = 0;

				while (!coaches.empty()) {
					estacion.push(coaches.top());
					coaches.pop();
					while (!estacion.empty() && estacion.top() == orden[j]) {
						estacion.pop();
						j++;
					}
				}

				if (estacion.empty()) cout << "Yes\n";
				else cout << "No\n";
			}
		}	
		cout << "\n";	
	}
	return 0;
}