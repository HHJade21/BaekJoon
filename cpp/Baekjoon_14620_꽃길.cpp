#include<iostream>

using namespace std;

int map[10][10];
int cost[10][10] = { 0, };

int dy[5] = { 0, -1, 1, 0, 0 };
int dx[5] = { 0, 0, 0, -1, 1 };

int minCost = 100000;

bool crush(int a, int b, int p, int q, int m, int n) { //충돌하면 true, 안충돌하면 false 반환
	bool exist[10][10] = { 0, };
	bool fail = false;

	if ((a == p && b == q) || (a == m && b == n) || (p == m && q == n))
		fail = true;

	for (int i = 0; i < 5; i++) {
		if (fail)
			break;
		exist[a + dy[i]][b + dx[i]] = true;
	}

	for (int i = 0; i < 5; i++) {
		if (fail)
			break;
		if (exist[p + dy[i]][q + dx[i]]) {
			fail = true;
			break;
		}

		exist[p + dy[i]][q + dx[i]] = true;
	}

	for (int i = 0; i < 5; i++) {
		if (fail)
			break;
		if (exist[m + dy[i]][n + dx[i]]) {
			fail = true;
			break;
		}
		exist[m + dy[i]][n + dx[i]] = true;

	}

	return fail;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, tempCost = 0;
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 1; i < N - 1; i++) {
		for (int j = 1; j < N - 1; j++) {
			for (int k = 0; k < 5; k++)
				cost[i][j] += map[i + dy[k]][j + dx[k]];
		}
	}

	for (int i = 1; i < N - 1; i++) {
		for (int j = 1; j < N - 1; j++) {
			for (int k = 1; k < N - 1; k++) {
				for (int l = 1; l < N - 1; l++) {
					for (int m = 1; m < N - 1; m++) {
						for (int n = 1; n < N - 1; n++) {
							if (crush(i, j, k, l, m, n))
								continue;
							tempCost = cost[i][j] + cost[k][l] + cost[m][n];
							if (tempCost < minCost)
								minCost = tempCost;
						}
					}
				}
			}
		}
	}

	cout << minCost;
}