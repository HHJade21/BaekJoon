#include<iostream>
using namespace std;


int main()
{
	float M = 0;
	float sum = 0;
	int N = 0;
	float newave = 0;
	float* p = NULL;

	cin >> N;
	p = new float[N];


	for (int i = 0; i < N; i++) {
		cin >> p[i];
	}


	for (int i = 0; i < N; i++) {
		if (p[i] > M)
			M = p[i];
	}


	for (int i = 0; i < N; i++) {
		p[i] = (p[i] / M * 100);
		sum += p[i];
	}

	newave = sum / N;
	
	cout << newave;

	delete[] p;
}