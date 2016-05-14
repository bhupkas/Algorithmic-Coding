/*

bhupkas

Problem Link : https://www.interviewbit.com/problems/jump-game-array/

Problem Statement : Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

*/

using namespace std;

#include "bits/stdc++.h"

int isPossible(vector < int > v) {
	int mx = 0;
	int curr = 0;
	for(int i = 0 ; i < v.size() ; ++i) {
		if(mx < i)	return 0;
		mx = max(mx, i + v[i]);
	}
	return 1;
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
	cout << isPossible(v);
	return 0;
}