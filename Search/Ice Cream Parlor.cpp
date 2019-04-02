#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);
using data = pair<int, int>;

bool cmp(data& l, data& r)
{
    return l.first <= r.first;
}

// Complete the whatFlavors function below.
void whatFlavors(vector<int> cost, int money) {

    vector<data> v;
    for(int i = 0; i < cost.size(); ++i)
        v.push_back(make_pair(cost[i], i+1));
    sort(v.begin(), v.end());

    for(int i = 0; i < cost.size(); ++i)
    {
        int want = money - v[i].first;
        int left = i + 1, right = cost.size() - 1;

        int mid;
        while(left <= right)
        {
            mid = (left + right) / 2;

            if(v[mid].first == want)
            {
                cout << min(v[i].second, v[mid].second) << ' ' << max(v[i].second,  v[mid].second) << '\n';
                return;
            } 
            else if (v[mid].first > want) 
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

    }

}

int main()
{
    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int money;
        cin >> money;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string cost_temp_temp;
        getline(cin, cost_temp_temp);

        vector<string> cost_temp = split_string(cost_temp_temp);

        vector<int> cost(n);

        for (int i = 0; i < n; i++) {
            int cost_item = stoi(cost_temp[i]);

            cost[i] = cost_item;
        }

        whatFlavors(cost, money);
    }

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
