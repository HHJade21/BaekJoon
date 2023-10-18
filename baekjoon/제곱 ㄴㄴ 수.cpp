#include<iostream>
#include<vector>
using namespace std;

bool prime[1001001] = { 0, }; //0이면 소수, 1이면 아님

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long min, max, numsize, tl, remain, count;
	int tm, jgsize;
	cin >> min >> max;


	for (int i = 2; i <= 500500; i++) {
		if (prime[i])//이미 소수가 아니면 그냥 넘어간다.
			continue;
		tm = i * 2;
		while (tm <= 1001000) {
			prime[tm] = true;
			tm += i;
		}//1001000까지 소수 거르고
	}

	vector<long long> jg;
	for (long long i = 2; i <= 1001000; i++) {
		if (!prime[i])
			jg.push_back(i*i);
	}

	numsize = max - min + 1;
	count = numsize;

	vector<bool> jgs(numsize, 0);

	tl = jg[0];
	tm = 0;

	while (tl <= max) {
		remain = (tl - (min % tl)) % tl;
		for (long long i = remain; i < numsize; i += tl) {
			if (!jgs[i])
				count--;
			jgs[i] = true;
		}
		tm++;
		tl = jg[tm];
	}

	cout << count;
}