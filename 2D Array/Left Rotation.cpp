#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the rotLeft function below.
vector<int> rotLeft(vector<int> a, int d) {
    int front = d % a.size();
    vector<int> ans;
    for(int i = front; i < a.size(); ++i)
        ans.push_back(a[i]);
    for(int i = 0; i < front; ++i)
        ans.push_back(a[i]);

    return ans;
}
