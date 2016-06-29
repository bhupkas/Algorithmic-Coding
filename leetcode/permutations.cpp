using namespace std;

#include "bits/stdc++.h"

vector < vector < int > > ans;

void dfs(int i, vector < int > & v) {
	if(i == v.size()) {
		ans.push_back(v);
		return;
	}
	for(int j = i ; j < v.size() ; ++j) {
		swap(v[i],v[j]);
		dfs(i+1,v);
		swap(v[i],v[j]);
	}
}

vector < vector < int > > func(vector < int > v) {
	dfs(0,v);
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
	func(v);
	cout << ans.size() << endl;
	for(int i = 0 ; i < ans.size() ; ++i) {
		for(int j = 0 ; j < ans[i].size() ; ++j) {
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}