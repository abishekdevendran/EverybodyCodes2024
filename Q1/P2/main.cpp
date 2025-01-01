#include <bits/stdc++.h>

using namespace std;

int assign(char c) {
	if (c == 'A') return 0;
	if (c == 'B') return 1;
	if (c == 'C') return 3;
	if (c == 'D') return 5;
	return -1;
}

int main() {
	string input;
	ifstream inputFile("./input.txt");
	if (inputFile) {
		getline(inputFile, input);
		inputFile.close();
	} else {
		cerr << "Unable to open file" << endl;
		return 1;
	}
	int ans = 0, a = 0, b = 0;
	for (int i = 0; i < input.length(); i++) {
		if (i % 2 == 0) {
			a = assign(input[i]);
			continue;
		}
		b = assign(input[i]);
		if (a == -1 || b == -1) {
			ans += max(a + b + 1, 0);
		} else {
			ans += a + b + 2;
		}
	}
	cout << ans << endl;
	return 0;
}