#include<iostream>
#include<set>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t, n, temp;
	char command;
	cin >> t;
	multiset<int> mset;
	multiset<int>::iterator it = mset.begin();

	for (int i = 0; i < t; i++) {
		cin >> n;
		mset.clear();
		for (int j = 0; j < n; j++) {
			cin >> command >> temp;
			if (command == 'I') 
				mset.insert(temp);
			else if (!mset.empty()) {
				if (temp == 1) {
					it = mset.end();
					it--;
					mset.erase(it);
				}
				else 
					mset.erase(mset.begin());
			}
		}
		if (mset.empty())
			cout << "EMPTY\n";
		else {
			it = mset.end();
			it--;
			cout << *it << " " << *mset.begin() << "\n";
		}
	}
}