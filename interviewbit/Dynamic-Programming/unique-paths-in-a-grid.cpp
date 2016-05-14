/*

bhupkas

Problem Link : https://www.interviewbit.com/problems/unique-paths-in-a-grid/

Problem Statement : Given a grid of size m * n, lets assume you are starting at (1,1) and your goal is to reach (m,n). At any instance, if you are on (x,y), you can either go to (x, y + 1) or (x + 1, y).

Now consider if some obstacles are added to the grids. How many unique paths would there be?
An obstacle and empty space is marked as 1 and 0 respectively in the grid.

*/

using namespace std;

#include "bits/stdc++.h"

int getSol(vector < vector < int > > v) {
	vector < vector < int > > dp;
	int n = v.size();
	int m = v[0].size();
	vector < int > temp;
	for(int i = 0 ; i < m ; ++i) {
		temp.push_back(0);
	}	
	for(int i = 0 ; i < n ; ++i) {
		dp.push_back(temp);
	}
	if(v[0][0] == 1) {
		return 0;
	} else {
		dp[0][0] = 1;
	}
	for(int i = 0 ; i < n ; ++i) {
		for(int j = 0 ; j < m ; ++j) {
			if(v[i][j] != 1) {
				int a,b;
				a = b = 0;
				if(i >= 1)	a = dp[i-1][j];
				if(j >= 1)	b = dp[i][j-1];	
				if(i + j != 0) dp[i][j] = a + b;
			}
		}
	}
	return dp[n-1][m-1];
}

int main() {
	int n,m;
	vector < vector < int > > v;
	cin >> n >> m;
	for(int i = 0 ; i < n ; ++i) {
		vector < int > t;
		for(int j = 0 ; j < m ; ++j) {
			int temp;
			cin >> temp;
			t.push_back(temp);
		}
		v.push_back(t);
	}
	cout << getSol(v) << endl;
	return 0;
}