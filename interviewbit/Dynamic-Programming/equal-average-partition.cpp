/*
	In progress
*/

using namespace std;

#include "bits/stdc++.h"

vector < vector < int > > getSol(vector < int > v) {
	vector < vector < int > > ans;
	int n = v.size();
	int sz = n/2 + 1;
	int sum = 0;
	for(int i = 0 ; i < n ; ++i)	sum += v[i];
	vector < vector < vector < int > > > dp;
	vector < vector < int > > temp;
	vector < int > foo;
	for(int i = 0 ; i <= sum ; ++i)	foo.push_back(false);
	for(int i = 0 ; i <= n ; ++i)	temp.push_back(foo);
	for(int i = 0 ; i <= sz ; ++i)	dp.push_back(temp);
	for(int i = 0 ; i < n ; ++i)	dp[0][i][0] = true;
	for(int i = 1 ; i <= sz ; ++i) {
		for(int j = 1 ; j < n ; j++) {
			for(int k = 0 ; k <= sum ; ++k) {
				if(v[i] <= k) {
					dp[i][j][k] = dp[i-1][j-1][k-v[i]];
				}
				dp[i][j][k] = dp[i][j][k] || dp[i][j-1][k];
				if(dp[i][j][k]) {
					if((double)k/i) - (double)sum/n) <= 0.0000001) {

					}
				}
			}
		}
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
	return 0;
}