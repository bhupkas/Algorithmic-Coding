using namespace std;
/* bhupkas

Problem Link :: https://www.interviewbit.com/problems/coin-sum-infinite/

Problem Statement : You are given a set of coins S. In how many ways can you make sum N assuming you have infinite amount of each coin in the set.

Note : Coins in set S will be unique. Expected space complexity of this problem is O(N).

*/

#include "bits/stdc++.h"

int MOD = 1000007;

int coinchange2(vector < int > &v, int n) {
	vector < int > dp;
	for(int i = 0 ; i <= n ; ++i) {
		dp.push_back(0);
	}
	dp[0] = 1;
	for(int j = 0 ; j < v.size() ; ++j) {
		for(int i = v[j] ; i <= n ; ++i) {
			dp[i] = (dp[i] + dp[i-v[j]]) % MOD;
		}
	}
	return dp[n];
}

int main() {
	int n, s;
	cin >> s;
	vector < int > v;
	for(int i = 0 ; i < s ; ++i) {
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
	cin >> n;
	cout << coinchange2(v,n) << endl;
	return 0;
}