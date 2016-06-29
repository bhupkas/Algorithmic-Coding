using namespace std;

#include "bits/stdc++.h"

int main() {
	int n;
	cin >> n;
	string str;
	int a,b;
	bool f = false;
	for(int i = 0 ; i < n ; ++i) {
		cin >> str >> a >> b;
		if(a >= 2400 && b > a) f = true;
	}
	if(f)	cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}
