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
	//���� �Է�
	for (int i = 1; i <= n; i++) {
		a.push_back(i);
	}
	it = a.begin();
	old = it;

	//test code
	cout << "���� : ";
	for (int val : a) {
		cout << val << " ";
	}
	cout << "\n";


	//�������϶� right == true�̹Ƿ� m�� for�� ���� ������ �似Ǫ�� ���. right == false�̸� ���� �似Ǫ�� ���

	while (!a.empty()) {
		//������ ���� ���� Ư��
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
		//���
		cout << *it << "\n";

		//���� �缳��
		dir--;
		if (dir == 0) {
			if (right)
				right = false;
			else
				right = true;
			dir = m;
		}

		//����� ���� ����
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