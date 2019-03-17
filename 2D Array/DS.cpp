#include <bits/stdc++.h>

using namespace std;

// Complete the hourglassSum function below.
int hourglassSum(vector<vector<int>> arr) {
    int ans = -70;

    for(int i = 0; i < arr.size() - 2; ++i)
    {
        for(int j = 0; j < arr[i].size() - 2; ++j)
        {
            int temp = 0;
            temp += arr[i][j] + arr[i][j+1] + arr[i][j+2];
            temp += arr[i+1][j+1];
            temp += arr[i+2][j] + arr[i+2][j+1] + arr[i+2][j+2];

            ans = std::max(ans, temp);
        }
    }
    return ans;
}