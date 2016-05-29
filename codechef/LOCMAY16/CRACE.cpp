using namespace std;

#include "bits/stdc++.h"

int main() {
	int t;
	cin >> t;
	int n;
	while(t--) {
		cin >> n;
		if(n&1)	puts("JENNY");
		else puts("JACK");
	}
	return 0;
}