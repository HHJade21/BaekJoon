#include<iostream>
using namespace std;

int int_cmp(int A, int B) {
	if (A % 10 > B % 10)
		return A;
	else if (B % 10 > A % 10)
		return B;
	else {
		if (A % 100 > B % 100)
			return A;
		else if (B % 100 > A % 100)
			return B;
		else {
			if (A % 100 > B % 100)
				return A;
			else if (B % 100 > A % 100)
				return B;
		}
	}
}

int int_rev(int x) {
	int newx = 0;
	newx = (x % 10) * 100 + ((x % 100) / 10) * 10 + x / 100;
	return newx;
}

int main(void) {
	int A, B, C;
	cin >> A >> B;
	C = int_rev(int_cmp(A, B));
	cout << C;
}