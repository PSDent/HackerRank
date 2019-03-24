#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

// Complete the freqQuery function below.
vector<int> freqQuery(vector<vector<int>> queries) {
    unordered_map<int, int> cntM, freqM;
    vector<int> ans;

    for(int i = 0; i < queries.size(); ++i)
    {
        int q = queries[i][0];
        int val = queries[i][1];

        if(q == 1)
        {
            if(cntM.find(val) != cntM.end() && cntM[val] > 0)
                --freqM[cntM[val]];
            ++cntM[val];
            ++freqM[cntM[val]];
        }
        else if(q == 2)
        {
            if(cntM.find(val) != cntM.end() && cntM[val] > 0)
            { 
                --freqM[cntM[val]];
                --cntM[val];
                ++freqM[cntM[val]];
            }
        }
        else
        {
            if(freqM.find(val) != freqM.end() && freqM[val] > 0)
                ans.push_back(1);
            else
                ans.push_back(0);
        }
    }
    return ans;
}
