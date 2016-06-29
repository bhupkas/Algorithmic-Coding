using namespace std;

#include "bits/stdc++.h"

int main() {
	int x1,v1,x2,v2;
	cin >> x1 >> v1 >> x2 >> v2;
	if(x1 == x2) {
		puts("YES");
	} else {
		if(x1 > x2) {
			if(v1 < v2) {
				if((x1-x2)%(v2-v1) == 0) puts("YES");
				else puts("NO");
			} else puts("NO");
		} else {
			if(v1 > v2) {
				if((x2-x1)%(v1-v2) == 0) puts("YES");
				else puts("NO");
			} else puts("NO");
		}
	}
	return 0;
}