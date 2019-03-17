#include <bits/stdc++.h>

using namespace std;

// Complete the countingValleys function below.
int countingValleys(int n, string s) {
	int nowHeight = 0, cnt = 0;

	char prev;
	for (int i = 0; i < s.size(); ++i)
	{
		if (s[i] == 'D') --nowHeight;
		else ++nowHeight;

		if (s[i] == 'U' && nowHeight == 0) ++cnt;
	}

	return cnt;
}