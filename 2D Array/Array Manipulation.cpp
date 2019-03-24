 #include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

long long status[10000003];
// Complete the arrayManipulation function below.
long arrayManipulation(int n, vector<vector<int>> queries) {
  long long val = 0, maxVal = 0;

    for(int i = 0; i < queries.size(); ++i)
    {
        status[queries[i][0]] += queries[i][2]; 
        status[queries[i][1] + 1] -= queries[i][2];
    }

    for(int i = 1; i <= n; ++i)
    {
        if(status[i]) val += status[i];
        maxVal = std::max(maxVal, val);
    }

    return maxVal;
}
