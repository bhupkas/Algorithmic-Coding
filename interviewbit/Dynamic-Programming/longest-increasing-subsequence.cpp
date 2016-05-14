/*

bhupkas

Problem Link : https://www.interviewbit.com/problems/longest-increasing-subsequence/

Problem Statement : Find the longest increasing subsequence of a given sequence / array.

In other words, find a subsequence of array in which the subsequence’s elements are in strictly increasing order, and in which the subsequence is as long as possible. 
This subsequence is not necessarily contiguous, or unique.
In this case, we only care about the length of the longest increasing subsequence.

*/

using namespace std;

#include "bits/stdc++.h"

int subSeq(vector < int > v) {
	vector < int > dp;
	for(int i = 0 ; i < v.size() ; ++i) {
		dp.push_back(1);
	}
	for(int i = 1 ; i < v.size() ; ++i) {
		for(int j = 0 ; j < i ; ++j) {
			if(v[i] > v[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}
	int ans = 0;
	for(int i = 0 ; i < v.size() ; ++i) {
		ans = max(ans, dp[i]);
	}
	return ans;
}

int main() {
	int n;
	vector < int > v;
	cin >> n;
	for(int i = 0 ; i < n ; ++i) {
		int t;
		cin >> t;
		v.push_back(t);
	}
	cout << subSeq(v) << endl;
	return 0;
}