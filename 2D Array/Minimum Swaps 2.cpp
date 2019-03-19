#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the minimumSwaps function below.
int minimumSwaps(vector<int> arr) {
    int cnt = 0;
    for(int i = 0; i < arr. size();)
    {
        if(arr[i] != i+1)
        {
            swap(arr[i], arr[arr[i] - 1]);
            ++cnt;
        }
        else ++i;
    }

    return cnt;
}
