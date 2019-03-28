#include <bits/stdc++.h>

using namespace std;
vector<string> split_string(string);
long MergeSort(vector<int> *v, int s, int e);

long countInversions(vector<int> arr) {

  long ans = MergeSort(&arr, 0, arr.size() - 1);

  return ans;
}

int tempV[100001];

long Merge(vector<int> * v, int s, int mid, int e) {
    long cnt = 0;

    int i, j, k;
    i = s;
    j = mid + 1; 
    k = s;

    int alpha = 0;
    while(i <= mid && j <= e)
    {
        if((*v)[i] <= (*v)[j])
        {
            tempV[k] = (*v)[i];
            ++i;
        }
        else if((*v)[i] > (*v)[j])
        {
            tempV[k] = (*v)[j];
            cnt += j - i - alpha;
            ++alpha;
            ++j; 
        }

        ++k;
    } 

    if(i > mid)
    {
        for(int m = j; m <= e; ++m)
        {
            tempV[k] = (*v)[m];
            ++k;
        }
    }
    else
    {
        for(int m = i; m <= mid; ++m)
        {
            tempV[k] = (*v)[m];
            ++k;
        }
    }

    for(int m = s; m <= e; ++m)
        (*v)[m] = tempV[m];

    return cnt;
}

long MergeSort(vector<int> *v, int s, int e) 
{
    long mid, cnt = 0;

    if(s >= e) return 0;

    mid = (s + e) / 2;
    cnt += MergeSort(v, s, mid);
    cnt += MergeSort(v, mid + 1, e);
    cnt += Merge(v, s, mid, e);

    return cnt;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string arr_temp_temp;
        getline(cin, arr_temp_temp);

        vector<string> arr_temp = split_string(arr_temp_temp);

        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            int arr_item = stoi(arr_temp[i]);

            arr[i] = arr_item;
        }

        long result = countInversions(arr);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
