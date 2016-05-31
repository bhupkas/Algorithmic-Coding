/* bhupkas */

/* Problem Link : https://www.interviewbit.com/problems/palindrome-partitioning-ii/

Problem Statement : Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

*/

using namespace std;

#include "bits/stdc++.h"

#define INF 1e9

char recur(string &s, vector <string > & dp, int l, int r) {
	if(l > r)	return 'G';
	if(dp[l][r] != 'U')	return dp[l][r];
	if(l == r) {
		return dp[l][r] = 'T';
	} else if(r == l + 1) {
		if(s[l] == s[r]) return dp[l][r] = 'T';
	}else {
		if(s[l] == s[r]) {
			char re = recur(s,dp,l+1,r-1);
			if(re == 'T')	return dp[l][r] = 'T';
			else return dp[l][r] = 'F';
		}
	}
	return dp[l][r] = 'F';
}

vector < string > init(string s) {
	int n = s.size();
	vector <string > dp;
	string foo;
	for(int i = 0 ; i <= n ; ++i)	foo.push_back('U');
	for(int i = 0 ; i <= n ; ++i)	dp.push_back(foo);
	for(int i = 0 ; i < n ; ++i) {
		for(int j = i ; j < n ; ++j) {
			dp[i][j] = recur(s,dp,i,j);
		}
	}
	return dp;
}

int minBreak(string &s, vector <string> &dp, vector < vector < int > > &ans, int l, int r) {
	if(l > r)	return 0;
	if(ans[l][r] != INF)	return ans[l][r];
	if(dp[l][r] == 'T')	return ans[l][r] = 0;
	int res = INF;
	for(int i = l ; i < r ; ++i) {
		int val1 = minBreak(s,dp,ans,l,i);
		int val2 = minBreak(s,dp,ans,i+1,r);
		res = min(res, val1 + val2 + 1);
	}
	return ans[l][r] = res;
}

int getMin(string s) {
	vector < string > palin = init(s);
	vector < vector < int > > ans;
	int n = s.size();
	vector < int > temp;
	for(int i = 0 ; i < n ; ++i)	temp.push_back(INF);
	for(int i = 0 ; i < n ; ++i)	ans.push_back(temp);
	int re =  minBreak(s,palin,ans,0,n-1);
	return re;
}

int main() {
	string s;
	cin >> s;
	cout << getMin(s) << endl;
	return 0;
}
