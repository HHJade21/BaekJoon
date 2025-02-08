#include<iostream>
#include<vector>
using namespace std;

int main(void) {
	int A = 0, B = 0, i = 0;
	vector<int> v;
	while(1) {
		cin >> A >> B;
		if ((A == 0) && (B == 0))
			break;
		else {
			v.push_back(A+B);
			i++;
		}
	}
	
	for (int j = 0; j < i; j++) {
		cout << v[j] << "\n";
	}
	
}