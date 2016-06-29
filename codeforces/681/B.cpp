using namespace std;

#include "bits/stdc++.h"

typedef long long LL;

int main() {
	LL n;
	cin >> n;
	for(int a = 0 ; a * 1234567L <= n; a++) {
		for(int b = 0 ; b * 123456L <= n - a * 1234567L ; b++) {
			if((n - a * 1234567L - b * 123456L) % 1234L == 0) {
				cout << "YES" << endl;
				return 0;
			}
		}
	}
	cout << "NO" << endl;
	return 0;
}