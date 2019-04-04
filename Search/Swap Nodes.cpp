#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the swapNodes function below.
 */
void InOrder(vector<vector<int>> &tree, vector<vector<int>> &ans, int index, int step);

void Swap(vector<vector<int>> &tree, int index, int k, int level) 
{
    cout << 'a';
    if(level % k == 0)
    {
        int temp = tree[index][0];
        tree[index][0] = tree[index][1];
        tree[index][1] = temp;
    }

    if(tree[index][0] != -1) Swap(tree, tree[index][0]-1, k, level + 1);
    if(tree[index][1] != -1) Swap(tree, tree[index][1]-1, k, level + 1);
}

void InOrder(vector<vector<int>> &tree, vector<int> &ans, int index) 
{
    if(tree[index][0] != -1)
        InOrder(tree, ans, tree[index][0] - 1);
    ans.push_back(index + 1);
    if(tree[index][1] != -1)
        InOrder(tree, ans, tree[index][1] - 1);
}

vector<vector<int>> swapNodes(vector<vector<int>> indexes, vector<int> queries) {
    vector<vector<int>> ans(queries.size());

    for(int i = 0; i < queries.size(); ++i)
    {
        int k = queries[i];

        Swap(indexes, 0,  k, 1);
        InOrder(indexes, ans[i], 0);
    }

    for(int i = 0; i < ans.size(); ++i)
    {
        for(int j = 0; j < ans[i].size(); ++j)
        {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }

    return ans;
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> indexes(n);
    for (int indexes_row_itr = 0; indexes_row_itr < n; indexes_row_itr++) {
        indexes[indexes_row_itr].resize(2);

        for (int indexes_column_itr = 0; indexes_column_itr < 2; indexes_column_itr++) {
            cin >> indexes[indexes_row_itr][indexes_column_itr];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int queries_count;
    cin >> queries_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> queries(queries_count);

    for (int queries_itr = 0; queries_itr < queries_count; queries_itr++) {
        int queries_item;
        cin >> queries_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        queries[queries_itr] = queries_item;
    }

    vector<vector<int>> result = swapNodes(indexes, queries);

    for (int result_row_itr = 0; result_row_itr < result.size(); result_row_itr++) {
        for (int result_column_itr = 0; result_column_itr < result[result_row_itr].size(); result_column_itr++) {
            fout << result[result_row_itr][result_column_itr];

            if (result_column_itr != result[result_row_itr].size() - 1) {
                fout << " ";
            }
        }

        if (result_row_itr != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}
