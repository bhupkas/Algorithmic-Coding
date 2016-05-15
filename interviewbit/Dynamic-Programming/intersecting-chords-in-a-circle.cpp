/* 

bhupkas 

Problem Link : https://www.interviewbit.com/problems/intersecting-chords-in-a-circle/

Problem Statement : Given a number N, return number of ways you can draw N chords in a circle with 2*N points such that no 2 chords intersect.
Two ways are different if there exists a chord which is present in one way and not in other

*/


using namespace std;

#include "bits/stdc++.h"

int getSol(int n) {
	long long int mod = 1e9 + 7;
	vector < long long int > dp;
	for(int i = 0 ; i <= n ; ++i) dp.push_back(0);
	dp[0] = 1;
	dp[1] = 1;
	for(int i = 2 ; i <= n ; ++i) {
		for(int j = 0 ; j < i ; ++j) {
			dp[i] += (dp[j] * dp[i - j - 1]) % mod;
			dp[i] %= mod;
		}
	}
	return dp[n] % mod;
}

int main() {
	int n;
	cin >> n;
	cout << getSol(n) << endl;
	return 0;
}