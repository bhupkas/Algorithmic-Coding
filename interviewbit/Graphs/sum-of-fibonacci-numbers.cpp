using namespace std;

#include "bits/stdc++.h"

int justMax(int n, vector < int > &fib) {
	for(int i = fib.size() - 1 ; i >= 0 ; i--) {
		if(fib[i] <= n) return fib[i];
	}
}

int getSol(int n) {
	vector < int > fib;
	fib.push_back(1);
	fib.push_back(2);
	int a, b;
	a = 1;
	b = 2;
	int c = a + b;
	while(c <= n) {
		fib.push_back(c);
		a = b;
		b = c;
		c = a + b;
	}
	fib.push_back(c);
	int cnt = 0;
	while(n) {
		cnt++;
		n -= justMax(n,fib);
	}
	return cnt;
}

int main() {
	int n;
	cin >> n;
	cout << getSol(n) << endl;
	return 0;
}