#include<iostream>
#include<list>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	list<int> a;
	list<int>::iterator it;
	list<int>::iterator old;
	int n, k, m, temp, dir;
	bool right = true;

	cin >> n >> k >> m;
	dir = m;
	//순열 입력
	for (int i = 1; i <= n; i++) {
		a.push_back(i);
	}
	it = a.begin();
	old = it;

	//test code
	cout << "원본 : ";
	for (int val : a) {
		cout << val << " ";
	}
	cout << "\n";


	//정방향일때 right == true이므로 m번 for문 돌려 오른쪽 요세푸스 출력. right == false이면 왼쪽 요세푸스 출력

	while (!a.empty()) {
		//순열의 다음 원소 특정
		if (right) {
			for (int i = 1; i < k; i++) {
				if (it == --a.end()) 
					it = a.begin();
				else
					it++;
			}
		}
		else {
			for (int i = 1; i < k; i++) {
				if (it == a.begin())
					it = --a.end();
				else
					it--;
			}
		}
		//출력
		cout << *it << "\n";

		//방향 재설정
		dir--;
		if (dir == 0) {
			if (right)
				right = false;
			else
				right = true;
			dir = m;
		}

		//출력한 원소 삭제
		old = it;
		if(right) {
			if (it == --a.end())
				it = a.begin();
			else
				it++;
		}
		else {
			if (it == a.begin())
				it = --a.end();
			else
				it--;
		}
		a.erase(old);

	}

}