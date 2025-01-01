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

    while (getline(ss, word, ',')) {
        words.push_back(word);
    }

    getline(cin, line);
    getline(cin, line);
    int ans=0;
    for (const string& w : words) {
        // find count of w in line
        int count = 0, pos=0;
        while (line.find(w, pos) != string::npos) {
            pos = line.find(w, pos) + w.length();
            count++;
        }
        // cout<<count<<endl;
        ans+=count;
    }
    cout << ans;
}