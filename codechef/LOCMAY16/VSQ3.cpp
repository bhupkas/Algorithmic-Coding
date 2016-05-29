using namespace std;

#include "bits/stdc++.h"

#define LL long long

int main() {
	int t,n;
	cin >> t;
	vector < LL > v;
	vector < LL > sum;
	LL temp,q1,q2,q3,q4,ans;
	while(t--) {
		cin >> n >> q1 >> q2 >> q3 >> q4;
		for(int i = 0 ; i < n ; ++i) {
			cin >> temp;
			v.push_back(temp);
			sum.push_back(0);
		}
		if(v[0] != q1 && v[0] != q2 && v[0] != q3 && v[0] != q4) {
			sum[0] = v[0];
		}
		for(int i = 1 ; i < n ; ++i) {
			if(v[i] != q1 && v[i] != q2 && v[i] != q3 && v[i] != q4) {
				if(sum[i-1] >= 0) {
					sum[i] = v[i] + sum[i-1];
				} else sum[i] = v[i];
			}	
		}
		ans = -1e18;
		for(int i = 0 ; i < n ; ++i) {
			if(v[i] != q1 && v[i] != q2 && v[i] != q3 && v[i] != q4) {
				ans = max(ans,sum[i]);	
			}
		}
		if(ans == -1e18)	ans = 0;
		cout << ans << endl;
		v.clear();
		sum.clear();
	}
	
	return 0;
}