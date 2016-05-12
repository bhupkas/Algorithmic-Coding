/* bhupkas

Problem link :: https://www.interviewbit.com/problems/ways-to-decode/ 

Problem Statement :: A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

*/

using namespace std;

#include "bits/stdc++.h"

int numDecodings(string s) {
	int n = s.size();
	vector < int > dp;
	for(int i = 0 ; i <= n ; ++i) {
		dp.push_back(0);
	}
	dp[0] = 1;
	if(s[0] == '0')		return 0;
	dp[1] = 1;
	for(int i = 2 ; i <= s.size() ; ++i) {
		int num = 0;
                num = (s[i-2] - '0') * 10 + (s[i - 1] - '0');
		if((s[i - 1] > '9' || s[i - 1] < '1') && num > 26) return 0;
                if(num <= 26 && s[i-2] != '0')   dp[i] += dp[i-2];
		if(s[i-1] <= '9' && s[i - 1] >= '1') dp[i] += dp[i-1];
	}
	return dp[n];
}

int main() {
	string s;
	cin >> s;
	cout << numDecodings(s) << endl;
	return 0;
}
