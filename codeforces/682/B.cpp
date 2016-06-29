using namespace std;

#include "bits/stdc++.h"

typedef long long LL;

int A[100005];

int main() {
	int n;
	cin >> n;
	for(int i = 0 ; i < n ; ++i)	cin >> A[i];
	sort(A,A+n);
	int ans = 1;
	for(int i = 1 ; i <= n ; ++i)	ans += (A[i-1] >= ans);
	cout << ans << endl;
	return 0;
}