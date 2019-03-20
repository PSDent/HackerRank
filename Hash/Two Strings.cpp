#include <bits/stdc++.h>

using namespace std;

// Complete the twoStrings function below.
string twoStrings(string s1, string s2) {
    int strCnt1[26], strCnt2[26];

    memset(strCnt1, 0, sizeof(strCnt1));
    memset(strCnt2, 0, sizeof(strCnt2));

    for(int i = 0; i < s1.size(); ++i)
        ++strCnt1[s1[i] - 'a'];
    for(int i = 0; i < s2.size(); ++i)
        ++strCnt2[s2[i] - 'a'];
    for(int i = 0; i < 26; ++i)
    {
        if(strCnt1[i] > 0 && strCnt2[i] > 0)
            return "YES";
    }

    return "NO";
}
