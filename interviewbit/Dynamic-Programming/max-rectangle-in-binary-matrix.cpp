/*

bhupkas

Problem Link : https://www.interviewbit.com/problems/max-rectangle-in-binary-matrix/

Problem Statement : Given a 2D binary matrix filled with 0’s and 1’s, find the largest rectangle containing all ones and return its area.

Bonus if you can solve it in O(n^2) or less.

*/

using namespace std;

#include "bits/stdc++.h"

vector <int> getList(vector < int > v) {
	stack < int > s;
	vector < int > ans;
	int n = v.size();
	for(int i = 0 ; i < n ; ++i) {
		ans.push_back(0);
	}
	s.push(0);
	for(int i = 1 ; i < n ; ++i) {
		if(!s.empty() && v[i] >= v[s.top()]) {
			s.push(i);
		} else {
			while(!s.empty() && v[i] < v[s.top()]) {
				ans[s.top()] = i - s.top() - 1;
				s.pop();
			}
			s.push(i);
		}
	}
	while(!s.empty()) {
		ans[s.top()] = n - s.top() - 1;
		s.pop();
	}
	return ans;
}

int getHist(vector < int > v) {
	vector < int > left, right, vec;
	int n = v.size();
	for(int i = 0 ; i < n ; ++i) {
		left.push_back(0);
		right.push_back(0);
		vec.push_back(v[i]);
	}
	right = getList(v);
	reverse(vec.begin(), vec.end());
	left = getList(vec);
	reverse(left.begin(),left.end());
	int ans = 0;
	for(int i = 0 ; i < n ; ++i) {
		ans = max(ans, (left[i] + right[i] + 1) * v[i]);
	}
	return ans;
}

int getSol(vector < vector < int > > v) {
	vector < int > cumm1,cumm2;
	int n = v.size();
	int m = v[0].size();
	for(int i = 0 ; i < m ; ++i) {
		cumm1.push_back(v[0][i]);
		cumm2.push_back(0);
	}
	int ans = 0;
	for(int i = 0 ; i < n ; ++i) {
		ans = max(ans, getHist(cumm1));
		if(i < n - 1) {
			for(int j = 0 ; j < m ; ++j) {
			if(v[i + 1][j] == 0)	cumm2[j] = 0;
			else cumm2[j] = cumm1[j] + 1;
		}
		for(int j = 0 ; j < m ; ++j)	cumm1[j] = cumm2[j];	
		}
	}
	return ans;
}

int main() {
	int n,m;
	cin >> n >> m;
	vector < vector < int > > v;
	for(int i = 0 ; i < n ; ++i) {
		vector < int > t;
		int temp;
		for(int j = 0 ; j < m ; ++j) {
			cin >> temp;
			t.push_back(temp);
		}
		v.push_back(t);
	}
	cout << getSol(v) << endl;
	return 0;
}