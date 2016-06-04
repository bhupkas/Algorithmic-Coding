using namespace std;

#include "bits/stdc++.h"

vector < int > getSol(vector <int> v) {
	int n = v.size();
	if(n == 2)	return v;
	int val = 0;
	for(int i = 0 ; i < v.size() ; ++i)	{
		val = val ^ v[i];
	}
	int set_bit = (val & ~(val-1));
	vector <int> res;
	int x,y;
	x = y = 0;
	for(int i = 0 ; i < n ; ++i)	{
		if(set_bit & v[i])	x ^= v[i];	 
		else y ^= v[i];
	}
	res.push_back(x);
	res.push_back(y);
	return res;
}

int main() {
	int n;
	cin >> n;
	vector <int> v(n);
	for(int i = 0 ; i < n ; ++i) {
		cin >> v[i];
	}
	vector < int > ans = getSol(v);
	for(int i = 0 ; i < ans.size() ; ++i)	{
		cout << ans[i] << " ";
	}
	cout << endl;
	return 0;
}