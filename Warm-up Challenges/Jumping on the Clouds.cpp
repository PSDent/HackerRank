#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the jumpingOnClouds function below.
int jumpingOnClouds(vector<int> c) {
    int now = 0, cnt = 0;

    while(now < c.size() - 1)
    {
        if(c[now + 2] == 0) now += 2;
        else now += 1;
        ++cnt;
    }
    return cnt;
}
