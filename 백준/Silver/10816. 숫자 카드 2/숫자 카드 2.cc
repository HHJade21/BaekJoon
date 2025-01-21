#include<iostream>
using namespace std;
int main() {
	int N, M, temp;
	int a[20000001] = { 0, };
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		a[temp + 10000000]++;
	}

	cin >> M;
	int* arr = new int[M];
	for (int i = 0; i < M; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < M; i++) {
		cout << a[arr[i] + 10000000] << " ";
	}



	delete[] arr;
}