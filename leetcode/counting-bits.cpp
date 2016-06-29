using namespace std;

#include "bits/stdc++.h"

vector <int> getCount(int n) {
	vector <int> res(n+1);
	res[0] = 0;
	for(int i = 1 ; i <= n ; ++i) {
		res[i] = 1 + res[i&(i-1)];
	}
	return res;
}

int main() {
	return 0;
}