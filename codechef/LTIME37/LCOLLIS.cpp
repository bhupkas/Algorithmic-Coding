using namespace std;

#include "bits/stdc++.h"

typedef long long LL;

int A[1005][1005];

int main() {
	int t;
	cin >> t;
	int n,m;
	string str;
	while(t--) {
		cin >> n >> m;
		for(int i = 0 ; i < n ; ++i) {
				cin >> str;
				for(int j = 0; j < str.size() ; ++j)	{
					if(str[j] == '1') {
						A[i][j] = 1;
					} else A[i][j] = 0;
				}
			}
		LL ans = 0;
		for(int j = 0 ; j < m ; ++j) {
			int cnt = 0;
			for(int i = 0 ; i < n ; ++i) {
				if(A[i][j])	cnt++;
			}
			ans += (cnt*(cnt-1))/2;
		}
		cout << ans << endl;	
	}
	return 0;
}