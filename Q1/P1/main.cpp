#include <bits/stdc++.h>

using namespace std;

int main()
{
    string input;
    ifstream ipt("./input.txt");
    if (ipt)
    {
        getline(ipt, input);
        ipt.close();
    }
    else
    {
        cerr << "Unable to open file" << endl;
        return 1;
    }
    int ans = 0;
    for (char c : input)
    {
        if (c == 'B')
        {
            ans++;
        }
        else if (c == 'C')
        {
            ans += 3;
        }
    }
    cout << ans << endl;
    return 0;
}