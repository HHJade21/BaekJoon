#include<iostream>
#include<map>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	map<int, string> pokemon1;
	map<string, int> pokemon2;
	int pCount, qCount, temp = 0;
	string tempS;
	cin >> pCount >> qCount;

	for (int i = 0; i < pCount; i++) {
		cin >> tempS;
		pokemon1.insert({ i + 1, tempS });
		pokemon2.insert({ tempS, i + 1 });
	}

	for (int i = 0; i < qCount; i++) {
		cin >> tempS;
		if (tempS[0] >= '0' && tempS[0] <= '9') { //번호가 입력되었다면 int로 변환 후 1번 맵의 key로 검색
			temp = 0;
			for (int j = 0; j < tempS.size(); j++) { //정수변환
				temp = temp * 10 + (int)(tempS[j] - '0');
			}
			cout << pokemon1.find(temp)->second << "\n";

		}
		else {//이름이 입력되었다면 2번 맵의 key로 검색
			cout << pokemon2.find(tempS)->second << "\n";
		}
	}
}