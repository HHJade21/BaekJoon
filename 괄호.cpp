#include<iostream>
using namespace std;
int main() {
	string s;
	int T, isVPS = 0;
	cin >> T;
	for (int t = 0; t < T; t++) {
		isVPS = 0;
		cin >> s;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '(')
				isVPS++;
			else if (s[i] == ')') {
				isVPS--;
				if (isVPS < 0)
					isVPS -= s.size();
			}
		}
		if (isVPS == 0)
			cout << "YES" << "\n";
		else
			cout << "NO" << "\n";
	}
}