#include <bits/stdc++.h>

using namespace std;

// Complete the repeatedString function below.
long repeatedString(string s, long n) {
    long long ans = 0;
    for(int i = 0; i < s.size(); ++i)
    {
        int cycle;
        if(s[i]== 'a')
        {
            ans += n / s.size();
            if( (n % s.size()) != 0 && (n % s.size()) >= (i+1) )
                ans += 1;
        }
    }

    return ans;
}
