using namespace std;

#include "bits/stdc++.h"

#define INF 1e9

int getMax(vector < int > v) {
	int n = v.size();
	if(n == 0)	return 0;
	vector < pair < int , int > > dp(n);
	for(int i = 0 ; i < n ; ++i) dp[i].first = dp[i].second = -1*INF;
	dp[0].first = 0;
	dp[0].second = -v[0];
	for(int i = 1 ; i < n ; ++i) {
		dp[i].first = max(dp[i-1].second + v[i] , dp[i-1].first);
		dp[i].second = max(dp[i-1].first - v[i] , dp[i-1].second);
	}
	return max(0,dp[n-1].first);
}

int main() {
	int n;
	cin >> n;
	vector < int > v(n);
	for(int i = 0 ; i < n ; ++i) cin >> v[i];
	cout << getMax(v) << endl;
	return 0;
}
