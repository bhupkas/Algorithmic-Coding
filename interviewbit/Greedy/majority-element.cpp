using namespace std;

#include "bits/stdc++.h"

int getMajority(vector < int > &v) {
	int ans = v[0];
	int cnt = 1;
	for(int i = 1 ; i < v.size() ; ++i) {
		if(v[i] == ans) cnt++;
		else {
			if(cnt == 0) {
				ans = v[i];
				cnt = 1;
			} else cnt--;
		}
	}
	return ans;
}

int main() {
	int n;
	cin >> n;
	vector < int > v(n);
	for(int i = 0 ; i < n ; ++i)	cin >> v[i];
	cout << getMajority(v) << endl;
	return 0;
}
