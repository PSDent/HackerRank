#include <bits/stdc++.h>

using namespace std;

// Complete the maxMin function below.
int maxMin(int k, vector<int> arr) {
    int ans = 1000000001;
    
    sort(arr.begin(), arr.end());


    for(int i = k; i <= arr.size(); ++i)
    {
        int minVal= 1000000001, maxVal=0;
        for(int j = i - k; j < i; ++j)
        {
            maxVal = max(maxVal, arr[j]);
            minVal = min(minVal, arr[j]);
        }
        ans = min(ans, maxVal - minVal);
    }

    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int k;
    cin >> k;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item;
        cin >> arr_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        arr[i] = arr_item;
    }

    int result = maxMin(k, arr);

    fout << result << "\n";

    fout.close();

    return 0;
}
