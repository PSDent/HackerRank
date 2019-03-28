#include <bits/stdc++.h>

using namespace std;
// Complete the isValid function below.
string isValid(string s) {
    vector<int> cnt(26);

    for(int i = 0; i < s.size(); ++i)
        ++cnt[s[i] - 'a'];

    sort(cnt.begin(), cnt.end());

    for(int i = 0; i < 26; ++i)
        cout << cnt[i] << ' ';

    int prev = -1;
    for(int i = 0; i < cnt.size(); ++i) 
    {
        if(cnt[i] == 0) continue;
        if(prev == -1) 
        {
            prev = cnt[i];
            if(cnt[i] == 1 && cnt[i+1] == cnt[25]) return "YES";
        }
        else if(prev == cnt[i]) continue;
        else
        {
            if(cnt[i] - prev == 1 && i == 25) continue;
            else return "NO";
        }
    }

    return "YES";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = isValid(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
