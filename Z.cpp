#include<iostream>

using namespace std;

long long zCount = -1;
int nowY, nowX;
bool completed = false;

int dy[4] = { 0, 1, 1 };
int dx[4] = { 1, 0, 1 };


void searchRoute(int y, int x, int size, int& r, int& c) {
	if (completed)
		return;
	int temp = size / 2;
	if (size > 2) {
		if (r >= y && r < y + temp && c >= x && c < x + temp) {
			searchRoute(y, x, temp, r, c);
			return;
		}
		else
			zCount += temp * temp;

		if (r >= y && r < y + temp && c >= x + temp && c < x + size) {
			searchRoute(y, x + temp, temp, r, c);
			return;
		}
		else
			zCount += temp * temp;
		if (r >= y+temp && r < y + size && c >= x && c < x + temp) {
			searchRoute(y + temp, x, temp, r, c);
			return;
		}
		else
			zCount += temp * temp;
		if (r >= y + temp && r < y + size && c >= x + temp && c < x + size) {
			searchRoute(y + temp, x + temp, temp, r, c);
		}
	}
	else {
		zCount++;
		nowY = y;
		nowX = x;
		if (nowY == r && nowX == c) {
			completed = true;
			return;
		}
		for (int i = 0; i < 3; i++) {
			nowY = y + dy[i];
			nowX = x + dx[i];
			zCount++;
			if (nowY == r && nowX == c) {
				completed = true;
				break;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, r, c, y = 0, x = 0, size = 1;
	cin >> n >> r >> c;
	

	for (int i = 1; i <= n; i++) {
		size *= 2;
	}
	
	if (r || c)
		searchRoute(y, x, size, r, c);
	else
		zCount = 0;

	cout << zCount;
}