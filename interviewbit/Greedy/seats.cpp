using namespace std;

#include "bits/stdc++.h"

int getSol(string s) {
	long long int mod = 10000003;
	long long int ans = (1e18);
	vector < int > v;
	for(int i = 0 ; i < s.size() ; ++i) {
		if(s[i] == 'X') {
			v.push_back(i);
		}
	}
	for(int i = 0 ; i <= s.size() - v.size() ; ++i) {
		
	}
}

int main() {
	return 0;
}