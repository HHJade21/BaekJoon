#include<iostream>
using namespace std;
#define STACK_SIZE 500000
int hstack[STACK_SIZE]; //왼큰수 판별용 스택. 타워 높이 저장
int nstack[STACK_SIZE]; //타워 번호 저장
int top = -1;

void push(int a, int b) {
	hstack[++top] = a;
	nstack[top] = b;
}

void pop() {
	top--;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int N, maxNum;

	cin >> N;
	int* tower = new int[N]; // 각 탑의 높이를 받는 배열
	int* receiver = new int[N]; //해당 타워의 신호를 수신한 탑의 번호를 저장하는 배열. 마지막에 얘를 출력함.
	for (int i = 0; i < N; i++) {
		cin >> tower[i];
	}

	receiver[0] = 0; // 첫 타워는 신호가 날라가니 0
	maxNum = tower[0]; // 현재까지 등장한 타워의 최대값은 0번 타워의 높이
	push(tower[0], 1);

	if (N > 1) {
		for (int i = 1; i < N; i++) {
			if (tower[i] > maxNum) {
				receiver[i] = 0;
				maxNum = tower[i];
				push(tower[i], i + 1);
			}
			else {
				if (tower[i-1] > tower[i]) {
					receiver[i] = i; //i-1번 인덱스, 즉 i번째 타워에서 얘를 수신하니까.
					push(tower[i], i + 1);
				}
				else if (tower[i - 1] == tower[i]) {
					receiver[i] = receiver[i - 1];
				}
				else if (tower[i - 1] < tower[i]) {
					while (tower[i] >= hstack[top]) {
						pop();
					}
					receiver[i] = nstack[top];
					push(tower[i], i + 1);
				}
			}
		}
	}
	for (int i = 0; i < N; i++) {
		cout << receiver[i] << " ";
	}

	delete[] tower;
	delete[] receiver;
}