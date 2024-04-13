#include<iostream>
#include<cmath>
using namespace std;

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

int calcDist(int x1, int x2, int y1, int y2) {
	int dist = pow(x1 - x2, 2) + pow(y1 - y2, 2);

	return dist;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int x1, x2, r1, r2, y1, y2, dist, t, temp;

	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

		if (r2 > r1) { //r1에 더 큰 원이 오도록(내접 판정을 위해)
			swap(r2, r1);
			swap(x2, x1);
			swap(y2, y1);
		}

		dist = calcDist(x1, x2, y1, y2); // 거리의 제곱 계산

		//케이스1. 두 원이 일치하는 경우
		if (x1 == x2 && y1 == y2 && r1 == r2) {
			cout << -1 << "\n";
			continue;
		}

		//케이스2. 두 원이 외접하는 경우
		else if (sqrt(dist) == r1 + r2) {
			cout << 1 << "\n";
			continue;
		}

		//케이스3. 두 원이 내접하는 경우
		else if (r1 == sqrt(dist) + r2) {
			cout << 1 << "\n";
			continue;
		}

		//케이스 4. 한 원이 다른 원에 포함되어 있고 만나지 않는 경우
		else if (r1 > sqrt(dist) + r2) {
			cout << 0 << "\n";
			continue;
		}

		//케이스 5. 그냥 떨어져 있는 경우
		else if (sqrt(dist) > r1 + r2) {
			cout << 0 << "\n";
			continue;
		}

		//나머지 모든 경우
		else {
			cout << 2 << "\n";
		}
	}
}