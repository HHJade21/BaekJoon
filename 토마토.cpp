#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int dayCount = 0, notRiped = 0, n = 1000, m = 1000;;
	cin >> m >> n;

	vector<vector<int>> tomatoBox(n, vector<int>(m));
	queue<pair<int, int>> bfsQ;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> tomatoBox[i][j];
			if (!tomatoBox[i][j])
				notRiped++;
			else if (tomatoBox[i][j] == 1) {
				bfsQ.push({ i, j });
			}
		}
	}

	int dy[4] = {0, 0, -1, 1};
	int dx[4] = { -1,1,0,0 };

	while (!bfsQ.empty() && notRiped > 0) {
		int temp = bfsQ.size();

		for (int i = 0; i < temp; i++) {
			for (int j = 0; j < 4; j++) {
				int ny = bfsQ.front().first + dy[j];
				int nx = bfsQ.front().second + dx[j];

				if (ny < 0 || ny >= n || nx < 0 || nx >= m)
					continue;

				if (!tomatoBox[ny][nx]) {
					tomatoBox[ny][nx] = 1;
					bfsQ.push({ny, nx});
					notRiped--;
				}

			}
			bfsQ.pop();
		}
		dayCount++;
	}

	if (notRiped > 0)
		cout << -1;

	else
		cout << dayCount;

}