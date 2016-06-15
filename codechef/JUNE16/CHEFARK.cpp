using namespace std;

#include "bits/stdc++.h"

typedef long long LL;

LL MOD=1e9+7;

LL getPow(int p) {
	LL ans = 1;
	LL num = 2;
	while(p) {
		if(p&1) {
			ans = (ans * num) % MOD;
		}
		num = (num * 2) % MOD;
		p /= 2;
	}
	return ans;
}

LL nCk(int n, int k) {
	if(k == 0)	return 1;
	k = min(k,n-k);
	LL ans = 1;
	for(int i = 1 ; i <= k ; ++i) {
		ans = (ans * ((n - k + i) / i)) % MOD;
	}
	return ans;
}

LL getAns(int n, int k) {
	LL ans = 0;
	if(k&1) {
		for(int i = 1 ; i <= k ; i += 2) {
			ans = (ans + nCk(n,i)) % MOD;
		}
	} else {
		for(int i = 0 ; i <= k ; i += 2) {
			ans = (ans + nCk(n,i)) % MOD;
		}
	}
	ans = (ans + MOD) % MOD;
	return ans;
}

LL getAns(int x) {
	LL ans;
	if(x&1) {
		ans = getPow(x-1);
	} else {
		ans = getPow(x-1);
	}
	return ans;
}

int main() {
	int t;
	cin >> t;
	int n,k;
	int val;
	int cnt;
	LL ans;
	bool zero;
	while(t--) {
		zero = false;
		cin >> n >> k;
		cnt = 0;
		for(int i = 0; i < n; ++i) {
			cin >> val;
			if(val != 0)	cnt++;
			else zero = true;
		}
		n = cnt;
		if(zero) {
			ans = getPow(min(n,k));
		} else{
			if(k <= n) {
			ans = getAns(n,k) ;
			} else {
				if((n&1 && k&1) || !(n&1) && !(k&1)) {
					ans = getAns(n);
				} else {
					ans = getAns(n-1);
				}
			}	
		}
		ans = (ans + MOD) % MOD;
		cout << ans << endl;
	}
	return 0;
}