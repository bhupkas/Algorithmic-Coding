/*

bhupkas

Problem Link : https://www.interviewbit.com/problems/distribute-candy/

Problem Statement : There are N children standing in a line. Each child is assigned a rating value.

 You are giving candies to these children subjected to the following requirements:
Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.

*/


using namespace std;

#include "bits/stdc++.h"

int getSol(vector < int > v) {
	int cnt = 0;
	int n = v.size();
	vector < int > l = vector < int > (n,1);
	vector < int > r = vector < int > (n,1);
	for(int i = 1 ; i < n ; ++i) {
		if(v[i] > v[i-1]) {
			l[i] = l[i-1] + 1;
		}
	}
	for(int i = n - 2 ; i >= 0 ; i--) {
		if(v[i] > v[i+1]) {
			r[i] = r[i+1] + 1;
		}
	}
	for(int i = 0 ; i < n ; ++i) {
		cnt += max(l[i],r[i]);
	}
	return cnt;
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