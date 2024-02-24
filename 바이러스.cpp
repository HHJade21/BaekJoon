#include<iostream>
using namespace std;

void infection(bool graph[100][100], bool virus[100], int a, int n) {
	for (int i = 0; i < n; i++) {
		if (graph[a][i] && !virus[i]) {
			virus[i] = 1;
			infection(graph, virus, i, n);	
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	bool graph[100][100] = { 0, };
	bool virus[100] = { 0, };
	int n, edge, a, b, count = 0;
	cin >> n >> edge;

	for (int i = 0; i < edge; i++) {
		cin >> a >> b;
		graph[a - 1][b - 1] = 1;
		graph[b - 1][a - 1] = 1;
	}
	virus[0] = 1;
	infection(graph, virus, 0, n);


	for (int i = 1; i < n; i++) {
		if (virus[i])
			count++;
	}

	cout << count;
}