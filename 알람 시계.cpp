#include<iostream>
using namespace std;

int main(void) {
	int H, M, newH, newM;
	cin >> H >> M;
	newM = (M + 15) % 60;
	if (M >= 45)
		newH = H;
	else if (M < 45)
		newH = (H + 23) % 24;
	cout << newH << " " << newM;
}