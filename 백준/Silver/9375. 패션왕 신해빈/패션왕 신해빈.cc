#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	map<string, int> clothes;

	string temp, tempKey;
	int t, n, result = 1;
	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> n;
		result = 1;
		for (int j = 0; j < n; j++) {
			cin >> temp >> tempKey;
			clothes[tempKey]++;
		}
		for (auto iter = clothes.begin(); iter != clothes.end(); iter++) {
			result *= (iter->second) + 1;
		}
		cout << result - 1 << "\n";

		clothes.clear();
	}
}