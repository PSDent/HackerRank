#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);
int cnt[101];

// Complete the sockMerchant function below.
int sockMerchant(int n, vector<int> ar) {
	int ans = 0;
	for (int i = 0; i < ar.size(); ++i)
	{
		++cnt[ar[i]];
		if (cnt[ar[i]] % 2 == 0)
		{
			ans += cnt[ar[i]] / 2;
			cnt[ar[i]] -= cnt[ar[i]] / 2 * 2;
		}
	}

	return ans;
}