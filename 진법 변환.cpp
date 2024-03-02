#include<iostream>
using namespace std;


int main() {
	string n;
	int b, jari = 1, result = 0;

	cin >> n >> b;


	for (int i = n.length() - 1; i >= 0; i--) {
		if (n[i] >= 'A') {
			result += (int)((n[i] - 'A') + 10) * jari;
		}
		else {
			result += (int)((n[i] - '0')) * jari;
		}
		jari *= b;
	}

	cout << result;
}