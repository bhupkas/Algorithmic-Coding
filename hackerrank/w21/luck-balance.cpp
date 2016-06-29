using namespace std;

#include "bits/stdc++.h"

int main() {
	int n,k;
	vector < int > v;
	cin >> n >> k;
	int ans = 0;
	for(int i = 0 ; i < n ; ++i) {
		int a,b;
		cin >> a >> b;
		if(!b)	ans += a;
		else v.push_back(a);
	}
	sort(v.begin(),v.end());
	reverse(v.begin(),v.end());
	int i = 0;
	while(i < v.size() && i < k) {
		ans +=  v[i];
		i++;
	}
	for(int j = i ; j < v.size() ; ++j) {
		ans -= v[j];
	}
	cout << ans << endl;
	return 0;
}