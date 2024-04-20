#include<iostream>
using namespace std;
int main() {
	int a[26] = { 0, };
	int max=0, x = 0;
	string s;

	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] > 64 && s[i] < 91)
			a[(int)s[i] - 65]++;
		else
			a[(int)s[i] - 97]++;
	}

	for (int j = 1; j < 26; j++) {
		if (a[max] < a[j]) {
			max = j;
		}
	}

	for (int k = 0; k < 26; k++) {
		if ((k != max) && (a[max] == a[k]))
			x = 1;
	}

	if (x == 1)
		cout << "?";
	else
		cout << (char)(max + 65);
}