#include<iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, temp;
	cin >> N;
	int arr[10001] = { 0, };

	for (int i = 0; i < N; i++) {
		cin >> temp;
		arr[temp] += 1;
	}

	for (int j = 1; j < 10001; j++) {//배열원소가 0보다 크면 감소시켜가며 0이 될때까지 출력
		if (arr[j] > 0) {
			while (arr[j] > 0) {
				cout << j << "\n";
				arr[j] -= 1;
			}
		}
	}
}