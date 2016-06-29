using namespace std;

#include "bits/stdc++.h"

char recur(const string &s, const string &p, vector < vector < char > > & dp, int i, int j) {
    if(dp[i][j] != 'U') return dp[i][j];
    if(i == s.size() && j == p.size())  return dp[i][j] = 'T';
    if(i == s.size()) {
    	if(p[j] == '*') {
    		return recur(s,p,dp,i,j+1);
    	} else return dp[i][j] = 'F';
    }   
    if(j == p.size())   return dp[i][j] = 'F';
    if(s[i] == p[j])    return recur(s,p,dp,i+1,j+1);
    if(p[j] == '?')     return recur(s,p,dp,i+1,j+1);
    if(p[j] == '*') {
        char ch1 = recur(s,p,dp,i+1,j);
        char ch2 = recur(s,p,dp,i,j+1); 
        if(ch1 == 'T' || ch2 == 'T')     return dp[i][j] = 'T';
    }
    return dp[i][j] = 'F';
}

int main() {
	string s,p;
	cin >> s >> p;
	int n = s.size();
    int m = p.size();
    cout << n << " " << m << endl;
    vector < vector < char > > dp;
    vector < char > v;
    for(int i = 0 ; i <= m ; ++i) v.push_back('U');
    for(int i = 0 ; i <= n ; ++i)    dp.push_back(v);
    cout <<  (int)(recur(s,p,dp,0,0) == 'T') << endl;
	return 0;
}