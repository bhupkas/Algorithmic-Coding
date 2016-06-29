using namespace std;

#include "bits/stdc++.h"

typedef long long LL;

int n;

vector < int > v;

void inputArray() {
	cin >> n;
	int te;
	for(int i = 0 ; i < n ; ++i) {
		cin >> te;
		v.push_back(te);
	}
}

int main() {
	string str;
	cin >> str;
	string str1;
	str1 = str;
	reverse(str1.begin(), str1.end());
	string ans = str + str1;
	cout << ans << endl;
	return 0;
}