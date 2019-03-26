#include <bits/stdc++.h>

using namespace std;

int cnt1[26], cnt2[26];

// Complete the makeAnagram function below.
int makeAnagram(string a, string b) {
    for(int i = 0; i < a.size(); ++i)
        ++cnt1[a[i] - 'a'];
    for (int i = 0; i < b.size(); ++i)
      ++cnt2[b[i] - 'a'];
      
    int ans = 0;
    for(int i = 0; i < 26; ++i)
        ans += abs(cnt1[i] - cnt2[i]);
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string a;
    getline(cin, a);

    string b;
    getline(cin, b);

    int res = makeAnagram(a, b);

    fout << res << "\n";

    fout.close();

    return 0;
}
