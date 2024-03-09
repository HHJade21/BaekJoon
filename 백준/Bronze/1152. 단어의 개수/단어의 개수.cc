#include<iostream>
#include<string>
using namespace std;
int main(void) {
	int n =0, w = 1;

	string s;
	getline(cin, s);
	n = s.size();
	for (int i = 0; i < n; i++) {
		if (s[i] == ' ')
			w++;
	}
	if (s[0] == ' ')
		w--;
	if (s[n - 1] == ' ')
		w--;

	cout << w;
}