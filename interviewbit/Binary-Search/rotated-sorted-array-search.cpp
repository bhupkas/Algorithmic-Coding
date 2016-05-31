/* bhupkas */

/**

Problem Link : https://www.interviewbit.com/problems/rotated-sorted-array-search/

Problem Statement : Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7  might become 4 5 6 7 0 1 2 ).

You are given a target value to search. If found in the array, return its index, otherwise return -1.

You may assume no duplicate exists in the array.

**/  

using namespace std;

#include "bits/stdc++.h"

int bsearch(vector < int > &v, int l, int r, int val) {
	if(l > r)	return -1;
	if(l==r) {
		if(v[l] == val) {
			return l;
		} else return -1;
	}
	int m = (l+r)/2;
	if(v[m] == val)	return m;
	if(v[l] <= v[m]) {
		if(val >= v[l] && val < v[m])	return bsearch(v,l,m-1,val);
		else return bsearch(v,m+1,r,val);
	} else {
		if(val > v[m] && val <= v[r])	return bsearch(v,m+1,r,val);
		else return bsearch(v,l,m-1,val);
	}
	return -1;
}

int main() {
	int n;
	cin >> n;
	vector < int > v(n);
	for(int i = 0 ; i < n ; ++i) {
		cin >> v[i];
	}
	int val;
	cin >> val;
	cout << bsearch(v,0,n-1,val) << endl;
	return 0;
}
