using namespace std;

#include "bits/stdc++.h"

int getSol(vector < int > v) {
	int n = v.size();
	vector < vector < int > > dp;
	vector < int > t;
	for(int i = 0 ; i < n ; ++i)	t.push_back(0);
	for(int i = 0 ; i < n ; ++i)	dp.push_back(t);
	for(int diff = 0 ; diff < n ; diff++) {
		for(int i = 0, j = diff ; j < n ; ++i,++j) {
			int a,b,c;
			a  = b = c = 0;
			if(i + 2 <= j) {
				a = dp[i+2][j];
			}
			if(i + 1 <= j - 1) {
				b = dp[i+1][j-1];
			}
			if(i <= j - 2) {
				c = dp[i][j-2];
			}
			dp[i][j] = max(v[i] + min(a,b) , v[j] + min(b,c));
		}
	}
	return dp[0][n-1];
}

int main() {
	int n;
	cin >> n;
	vector < int > v;
	for(int i = 0 ; i < n ; ++i) {
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
	cout << getSol(v);
	return 0;
}