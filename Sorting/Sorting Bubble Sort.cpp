#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the countSwaps function below.
void countSwaps(vector<int> a) {
    int cnt = 0;

    for(int i = 1; i < a.size(); ++i)
    {
        for(int j = 0; j < a.size() - i; ++j)
        {
            if(a[j] > a[j+1])
            {
                int temp = a[j+1];
                a[j+1] = a[j];
                a[j] = temp;
                ++cnt;
            }
        }
    }

    cout << "Array is sorted in " << cnt << " swaps." << '\n';
    cout << "First Element: " << a[0] << '\n';
    cout << "Last Element: " << a[a.size() - 1];
}