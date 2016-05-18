/* 

bhupkas 

Problem Link : https://www.interviewbit.com/problems/highest-product/

Problem Statement : Given an array of integers, return the highest product possible by multiplying 3 numbers from the array

*/

using namespace std;

#include "bits/stdc++.h"

int getSol(vector < int > v) {
	int mn,mx,ans;
	int n = v.size();
	sort(v.begin(), v.end());
	ans = max(v[0] * v[1] * v[n-1], v[n-1] * v[n-2] * v[n-3]);
	return ans;
}

int main() {
	int n;
	cin >> n;
	vector < int > v;
	int t;
	for(int i = 0 ; i < n ; ++i) {
		cin >> t;
		v.push_back(t);
	}
	cout << getSol(v) << endl;
	return 0;
}