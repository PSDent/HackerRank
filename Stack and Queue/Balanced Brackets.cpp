#include <bits/stdc++.h>

using namespace std;

// Complete the isBalanced function below.
string isBalanced(string s) {
    stack<char> st;
    unordered_map<char, char> m;

    m['('] = ')';
    m['{'] = '}';
    m['['] = ']';

    //st.push(s[0]);

    for(int i = 0; i < s.size(); ++i)
    {
        if(s[i] == ')' || s[i] == '}' || s[i] == ']')
        {
            if(!st.empty() && m[st.top()] == s[i])
                st.pop();
            else
                return "NO";
        }
        else
        {
            st.push(s[i]);
        }
    }

    if(st.empty()) return "YES";
    else return "NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string s;
        getline(cin, s);

        string result = isBalanced(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
