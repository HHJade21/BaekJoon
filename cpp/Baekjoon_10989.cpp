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

	for (int j = 1; j < 10001; j++) {//�迭���Ұ� 0���� ũ�� ���ҽ��Ѱ��� 0�� �ɶ����� ���
		if (arr[j] > 0) {
			while (arr[j] > 0) {
				cout << j << "\n";
				arr[j] -= 1;
			}
		}
	}
}