#include <bits/stdc++.h>
using namespace std;

void solve();

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "r", stdin);

	solve();
	cout << "\n";

	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs"
		 << endl;
	return 0;
}

int assign(char c) {
	if (c == 'A') return 0;
	if (c == 'B') return 1;
	if (c == 'C') return 3;
	if (c == 'D') return 5;
	return -1;
}

void solve() {
	string ipt;
	cin >> ipt;
	int a = -1, b = -1, c = -1, xCount = 0, ans = 0;
	for (int i = 0; i < ipt.length(); i++) {
		if (i % 3 == 0) {
			xCount = 0;
			a = assign(ipt[i]);
			if (a == -1) {
				xCount++;
				a = 0;
			}
		} else if (i % 3 == 1) {
			b = assign(ipt[i]);
			if (b == -1) {
				xCount++;
				b = 0;
			}
		} else {
			c = assign(ipt[i]);
			if (c == -1) {
				xCount++;
				c = 0;
			}
			if (xCount >= 2) {
				xCount = 0;
			} else if (xCount == 1) {
				xCount = 2;
			} else {
				xCount = 6;
			}
			cout << a + b + c + xCount << endl;
			ans += a + b + c + xCount;
		}
	}
	cout << ans;
}