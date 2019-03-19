#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

int cnt[100001];
// Complete the minimumBribes function below.
void minimumBribes(vector<int> q) {
    memset(cnt, 0, sizeof(cnt));

    
    int bribedCnt = 0;
    for(int i = 0; i < q.size();)
    {
        bool a = false;

         if(cnt[q[i]] > 2 || (i > 0 && cnt[q[i - 1]] > 2) || ( (i + 1) < q.size() && cnt[q[i + 1]] > 2))
            break;

        if (cnt[q[i]] < 2 && i > 0 && cnt[q[i - 1]] < 2 && q[i] < q[i - 1]) {
          ++cnt[q[i]];
          int temp = q[i - 1];
          q[i - 1] = q[i];
          q[i] = temp;
          ++bribedCnt;
          --i;
        }
        else if(cnt[q[i]] < 2 && (i + 1) < q.size() && cnt[q[i + 1]] < 2 && q[i] > q[i + 1])
        {
            ++cnt[q[i]];
            int temp = q[i + 1];
            q[i + 1] = q[i];
            q[i] = temp;    
            ++bribedCnt;
            if(i > 0)
                --i;
        }
        else ++i;
    }

    bool clear = true;
    for(int i = 0; i < q.size(); ++i)
        if(q[i] != (i + 1)) { clear = false; break; }

    if(clear)
    std::cout << bribedCnt << '\n';
    else
    std::cout << "Too chaotic" << '\n';
}
