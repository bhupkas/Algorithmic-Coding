using namespace std;

#include "bits/stdc++.h"

typedef long long LL;

int main() {
	int t;
	cin >> t;
	vector < LL > v;
	map < LL, LL > m;
	map < LL, LL > :: iterator it;
	while(t--) {
		int n;
		v.clear();
		m.clear();
		cin >> n;
		LL te;
		for(int i = 0 ; i  < n ; ++i) {
			cin >> te;
			m[te]++;
		}
		for(it = m.begin() ; it != m.end() ; it++) {
			if(it -> second >= 4) {
				v.push_back(it -> first);
				v.push_back(it -> first);
			} else if(it -> second >= 2) {
				v.push_back(it -> first);
			}	
		}
		sort(v.begin(),v.end());
		if(v.size() < 2) {
			puts("-1");
		} else {
			cout << v[v.size() - 1] * v[v.size() - 2] << endl;
		}
	}
	return 0;
}