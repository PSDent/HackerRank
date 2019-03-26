#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);
    int cnt[201];

// Complete the activityNotifications function below.
int activityNotifications(vector<int> expenditure, int d) {
    int ans = 0;
    for (int j = 0; j < d; ++j)
      ++cnt[expenditure[j]];

    for(int i = d; i < expenditure.size(); ++i)
    {
      int s = i - d, e = i;
      int fM = -1, secM = -1;
      int mid = d / 2, secMid = d / 2 - 1;

    if(i > d)
    {
        --cnt[expenditure[s - 1]];
        ++cnt[expenditure[e - 1]];
    }

    int val = 0, index = 0, prevVal = 0, prevIndex = 0;
    for(int j = 0; j < 201; ++j)
    {
        val += cnt[j];
        index = j;

         if(fM == -1 && val > mid) fM = index;
         if(secM == -1 && val > secMid) secM = index;
    }

     cout << fM << ' ' << secM << '\n';

     float median;
     if(d % 2 == 1)
         median = fM * 2.0f;
     else
         median = (fM + secM);

     if(expenditure[i] >= median)
        ++ans;
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nd_temp;
    getline(cin, nd_temp);

    vector<string> nd = split_string(nd_temp);

    int n = stoi(nd[0]);

    int d = stoi(nd[1]);

    string expenditure_temp_temp;
    getline(cin, expenditure_temp_temp);

    vector<string> expenditure_temp = split_string(expenditure_temp_temp);

    vector<int> expenditure(n);

    for (int i = 0; i < n; i++) {
        int expenditure_item = stoi(expenditure_temp[i]);

        expenditure[i] = expenditure_item;
    }

    int result = activityNotifications(expenditure, d);

    fout << result << "\n";

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
