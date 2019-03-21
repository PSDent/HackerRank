#include <bits/stdc++.h>

using namespace std;

// Complete the sherlockAndAnagrams function below.
int sherlockAndAnagrams(string s) {
    unordered_map<string, int> hash;
    int ans = 0, size = s.size();

     for (int i = 1; i < size; ++i) {
      for (int j = 0; (j + i) <= size; ++j) {
            string key = s.substr(j, i);
            sort(key.begin(), key.end());
            ++hash[key];
        }
    }

    unordered_map<string, int>::iterator iter;
    for(iter = hash.begin(); iter != hash.end(); ++iter)
    {
        int n = iter->second;
        ans += n * (n - 1) / 2; 
    }

    return ans;
}
