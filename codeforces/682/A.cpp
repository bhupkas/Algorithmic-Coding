using namespace std;

#include "bits/stdc++.h"

typedef long long LL;

LL get(LL num, LL i) {
	return num/5 + (num%5 >= i);
}

int main() {
	LL n,m;
	cin >> n >> m;
	LL ans = 0;	
	for(LL i = 1 ; i <= 5 ; ++i) {
		ans += get(n,i) * get(m,5-i);
	}
	cout << ans - (get(n,5)) << endl;
	return 0;
}