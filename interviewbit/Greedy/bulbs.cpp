using namespace std;

#include "bits/stdc++.h"

int getSol(vector < int > v) {
	int n = v.size();
	int ans = 0;
	int cnt = 0;
	for(int i = 0 ; i < v.size() ; ++i) {
		if(cnt & 1) {
			if(v[i] == 1) {
				cnt++;
				ans++;
			}
		} else {
			if(v[i] == 0) {
				cnt++;
				ans++;
			}
		}
	}
	return ans;
}

int main() {
	int n;
	vector < int > v;
	cin >> n;
	int t;
	for(int i = 0 ; i < n ; ++i) {
		cin >> t;
		v.push_back(t);
	}
	cout << getSol(v) << endl;
	return 0;
}