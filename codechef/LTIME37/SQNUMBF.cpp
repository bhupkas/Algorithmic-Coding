using namespace std;

#include "bits/stdc++.h"

typedef long long LL;

vector < LL > p;

#define SIZE 10000005

int P[SIZE];

void init() {
	for(int i = 0 ; i < SIZE ; ++i)	P[i] = i;
	for(int i = 2 ; i * i <= SIZE ; ++i) {
		if(P[i] == i) {
			for(int j = i ; j <= SIZE / i ; ++j) {
				P[i*j] = min(P[i*j],i);
			}
		}
	}
	for(int i = 2 ; i < SIZE ; ++i) {
		if(P[i] == i)	p.push_back(i);
	} 
}	

int main() {
	init();
	int t;
	cin >> t;
	set <LL> s;
	while(t--) {
		s.clear();
		int n;
		cin >> n;
		LL num;
		bool f = false;
		LL ans;
		for(int j = 0 ; j < n ; ++j) {
			cin >> num;
			if(f)	continue;
			int k = 0;
			while(num != 1 && !f && k < p.size()) {
				if(num % p[k] == 0) {
					while(num % p[k] == 0) {
						if(s.find(p[k]) != s.end()) {
							ans = p[k];
							f = true;
							break;
						}
						s.insert(p[k]);
						num /= p[k];
					}
				}
				k++;
			}
			if(num != 1)	s.insert(num);
			
		}
		cout << ans << endl;
	}
	return 0;
}