using namespace std;

#include "bits/stdc++.h"

#define LL long long

int main() {
	int t;
	cin >> t;
	LL n;
	while(t--) {
		cin >> n;
		if(n&1 || n == 2) {
			puts("NO");
		} else puts("YES");
	}
	return 0;
}