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

void solve() {
	string line;
	getline(cin, line);

	string rightPart = line.substr(line.find(':') + 1);
	stringstream ss(rightPart);
	string word;
	vector<string> words;

	int ans = 0;

	while (getline(ss, word, ',')) {
		words.push_back(word);
	}

	// skip empty line
	getline(cin, line);

	// construct a 2D vector to store string grid
	vector<vector<char>> grid;
	while (getline(cin, line)) {
		vector<char> row;
		for (char c : line) {
			row.push_back(c);
		}
		grid.push_back(row);
	}

	// for each line
	for (auto row : grid) {
		// construct a string from row
		line = "";
		for (char c : row) {
			line += c;
		}
		cout << line << endl;
		vector<pair<int, int>> intervals;
		// for each word
		for (auto word : words) {
			// cout << word << endl;
			// find all occurences of word in line
			int pos = 0;
			while (pos < line.size()) {
				pos = line.find(word, pos);
				if (pos < 0) break;
				// insert interval
				intervals.push_back({pos, pos + word.size() - 1});
				pos++;
			}
			// construct cyclic string
			string cyclic = line + line;
			// check if cyclic string is present in line
			pos = line.length() - word.length();
			pos = cyclic.find(word, pos);
			if (pos != -1 && pos < line.length()) {
				cout << "Cyclic string found at " << pos << endl;
				intervals.push_back({pos, pos + word.size() - 1});
			}
			// reverse word
			reverse(word.begin(), word.end());
			pos = 0;
			while (pos < line.size()) {
				pos = line.find(word, pos);
				if (pos < 0) break;
				// insert interval
				intervals.push_back({pos, pos + word.size() - 1});
				pos++;
			}
			// check if cyclic string is present in line
			pos = line.length() - word.length();
			pos = cyclic.find(word, pos);
			if (pos != -1 && pos < line.length()) {
				cout << "Cyclic string found at " << pos << endl;
				intervals.push_back({pos, pos + word.size() - 1});
			}
		}
		// sort intervals
		sort(intervals.begin(), intervals.end());
		// merge intervals
		vector<pair<int, int>> merged;
		for (auto interval : intervals) {
			if (merged.empty()) {
				merged.push_back(interval);
			} else {
				if (interval.first <= merged.back().second) {
					merged.back().second =
						max(merged.back().second, interval.second);
				} else {
					merged.push_back(interval);
				}
			}
		}
		// count number of characters in intervals
		int count = 0;
		for (auto interval : merged) {
			count += interval.second - interval.first + 1;
		}
		cout << "Count: " << count << endl;
		ans += count;
	}

	// transpose rectangular grid
	vector<vector<char>> transposed;
	for (int i = 0; i < grid[0].size(); i++) {
		vector<char> row;
		for (int j = 0; j < grid.size(); j++) {
			row.push_back(grid[j][i]);
		}
		transposed.push_back(row);
	}
	cout << "Total: " << ans << endl;
}