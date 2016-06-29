using namespace std;

#include "bits/stdc++.h"

int A[100005];

int main() {
	int n;
	cin >> n;
	map < int, int > m;
	int ans = n + 1;
	for(int i = 0 ; i < n ; ++i) {
		cin >> A[i];
		if(m.find(A[i]) == m.end()) m[A[i]] = i;
		else {
			ans =  min(ans, abs(i-m[A[i]]));
			m[A[i]] = max(i,m[A[i]]);
		}
	}
	if(ans == n + 1)	ans = -1;
	cout << ans << endl;
	return 0;
}