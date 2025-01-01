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

	getline(cin, line);
	// for each line
	while (getline(cin, line)) {
		// cout << line << endl;
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
		}
		// sort intervals
		sort(intervals.begin(), intervals.end());
		// print intervals
		// for (auto interval : intervals) {
		// 	cout << interval.first << "-" << interval.second << endl;
		// }
		// cout << endl;
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
		// print intervals
		// for (auto interval : merged) {
		// 	cout << interval.first << "-" << interval.second << endl;
		// }
		// count number of characters in intervals
		int count = 0;
		for (auto interval : merged) {
			count += interval.second - interval.first + 1;
		}
        // cout<<"Count: "<<count<<endl;
		ans += count;
	}
	cout << "Total: " << ans << endl;
}