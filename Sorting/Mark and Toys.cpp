#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the maximumToys function below.
int maximumToys(vector<int> prices, int k) {
    sort(prices.begin(), prices.end());
    int cnt = 0;

    for(int i = 0; i < prices.size(); ++i)
    {
        k -= prices[i];
        if(k < 0) 
            return cnt;

        ++cnt;
    }

    return cnt;
}
