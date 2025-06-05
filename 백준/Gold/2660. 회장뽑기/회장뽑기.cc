#include<iostream>
#include<vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int n, a, b, temp, minNum = 10000, mincount = 0, maxNum;

	cin >> n;

	vector<vector<int>> graph(n, vector<int>(n, 10000));
	vector<int>friendspoint(n);
	vector<int> candidates;

	cin >> a >> b;

	while (a != -1 && b != -1) {
		graph[a - 1][b - 1] = 1;
		graph[b - 1][a - 1] = 1;
		cin >> a >> b;
	}

	for (int i = 0; i < n; i++)
		graph[i][i] = 0;

	for (int k = 0; k < n; k++) {

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		temp = 0;
		for (int j = 0; j < n; j++) {
			if (graph[i][j] < n && graph[i][j] > temp)
				temp = graph[i][j];
		}

		friendspoint[i] = temp;
		if (temp < minNum)
			minNum = temp;
	}

	cout << minNum;

	for (int i = 0; i < n; i++) {
		if (friendspoint[i] == minNum) {
			mincount++;
			candidates.push_back(i + 1);
		}
	}
	cout << " " << mincount << "\n";

	for (int i = 0; i < candidates.size(); i++) {
		cout << candidates[i] << " ";
	}
}