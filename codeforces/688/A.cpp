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
	cin	>> n;
	int d;
	cin >> d;
	for(int i = 0 ; i < d ; ++i) {
		string str;
		cin >> str;
		bool foo = false;
		for(int j = 0 ; j < n ; ++j) {
			if(str[j] == '0')	foo =true;
		}
		if(foo) v.push_back(1);
		else 	v.push_back(0);
	}
	int mx = 0;
	for(int i = 0 ; i < d ; ++i) {
		if(v[i] == 1) {
			int len = 0;
			int j = i;
			while(v[j] == 1 && j < d) {
				len++;
				j++;
			}
			mx = max(mx,len);
		}
	}
	cout << mx << endl;
	return 0;
}