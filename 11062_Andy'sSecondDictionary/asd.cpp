#include <iostream>
#include <cstdio>
#include <set>
#include <iterator>
#include <algorithm>

using namespace std;

int main () {
	string s;
	set <string> dictionary;
	string word = "";
	while (getline(cin, s)) {
		for (int i = 0; i < s.length(); i++) {
			if (isalpha(s.at(i))) {
				word.push_back(tolower(s.at(i)));
			}else {
				if (s.at(i) == '-' && i == s.length() - 1) continue;
				else if (s.at(i) == '-') word.push_back(s.at(i));
				else {
					if (word != "") dictionary.insert(word);
					word = "";
				}
			}
		}
		if (s.length() > 0 && s.at(s.length() - 1) != '-'){
			if (word != "") dictionary.insert(word);
			word = "";
		}
	}
	if (word != "") {
		word.push_back('-');
		dictionary.insert(word);
		word = "";
	}
	for (set <string>::iterator it = dictionary.begin(); it != dictionary.end(); it++) {
		cout << *it << endl;
	}
	return 0;
}