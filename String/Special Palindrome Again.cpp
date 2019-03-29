#include <bits/stdc++.h>

using namespace std;

// Complete the substrCount function below.
long substrCount(int n, string s) {
    long ans = 0;

    char prev = s[0];
    long cnt = 0;
    for(int i = 0; i < s.size(); ++i)
    {
        if(s[i] == prev) 
        {
            ++cnt;
        }
        else 
        {
            ans += cnt * (cnt + 1) / 2;
            prev = s[i]; 
            cnt = 1;
        }
        if (i + 1 == s.size()) {
          ans += cnt * (cnt + 1) / 2;
        }
    }

    for(int i = 1; i < s.size(); ++i)
    { 
        int sameCnt = 0;
        char ch = s[i - 1];
        if (i - 1 >= 0 && i + 1 < s.size() && s[i] == s[i-1] && s[i] == s[i+1])
            continue;

        for(int j = 1; (i - j) >= 0 && (i + j) < s.size(); ++j)
        {
            int l = i - j, r = i + j;
            if(ch != s[l] || s[l] != s[r])
                break;
            ++sameCnt;
        }
        ans += sameCnt;
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    long result = substrCount(n, s);

    fout << result << "\n";

    fout.close();

    return 0;
}
