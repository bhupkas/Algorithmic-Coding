using namespace std;

#include "bits/stdc++.h"

int main() {
	int n,q,t;
	cin >> n >> q;
	int tem;
	int mx = -1;
	int mn = 1e9 + 1;
	for(int i = 0 ; i < n ; ++i) {
		cin >> tem;
		mx = max(mx,tem);
		mn = min(mn,tem);
	}
	while(q--) {
		cin >> t;
		if(t > mx || t < mn)	puts("No");
		else puts("Yes");
	}
	return 0;
}