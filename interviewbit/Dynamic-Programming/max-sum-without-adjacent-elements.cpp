/*

bhupkas

Problem Link : https://www.interviewbit.com/problems/max-sum-without-adjacent-elements/

Problem Statement : Given a 2 * N Grid of numbers, choose numbers such that the sum of the numbers
is maximum and no two chosen numbers are adjacent horizontally, vertically or diagonally, and return it.

*/

using namespace std;

#include "bits/stdc++.h"

int maxSum(vector < vector < int > > v) {
	vector < int > dp, dp1;
	for(int i = 0 ; i < v[0].size() ; ++i) {
			dp.push_back(0);
			dp1.push_back(0);
		}
	dp[0] = max(v[0][0], v[1][0]);
	if(v[0].size() > 1) {
		dp[1] = max(v[0][1], v[1][1]);
	}
	for(int i = 2 ; i < v[0].size() ; ++i) {
		dp[i] = max(v[0][i], v[1][i]) + dp[i-2];
	}
	dp1[0] = dp[0];
	if(v[0].size() > 1) {
		dp1[1] = max(dp[0], max(v[0][1], v[1][1]));
	}
	for(int i = 2 ; i < v[0].size() ; ++i) {
		dp1[i] = max(dp1[i-1], dp1[i-2] + max(v[0][i], v[1][i]));
	}
	int ans = dp1[0];
	for(int i = 0 ; i < v[0].size() ; ++i) {
		ans = max(ans, dp1[i]);
	}
	return ans;
}

int main() {
	int n;
	vector < vector < int > > v;
	cin >> n;
	for(int i = 0 ; i < 2 ; ++i) {
		vector < int > t;
		for(int j = 0 ; j < n ; ++j) {
			int temp;
			cin >> temp;
			t.push_back(temp);
		}
		v.push_back(t);
	}
	cout << maxSum(v) << endl;
	return 0; 
}