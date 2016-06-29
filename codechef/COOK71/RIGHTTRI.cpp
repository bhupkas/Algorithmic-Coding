using namespace std;

#include "bits/stdc++.h"

typedef long double LD;

LD disc(LD H, LD S) {
	LD d = (LD)H*H*H*H - 16.0*S*S;
	return d;
}

int main() {
	int t;
	cin >> t;
	LD H,S;
	vector < LD > sides;
	while(t--) {
		sides.clear();
		cin >> H >> S;
		LD d = disc(H,S);
		if(d < 0.0) {
			puts("-1");
			continue;
		}
		LD bsq = (H*H + (LD)sqrtl(d))/2.0;
		LD b = (LD)sqrtl(bsq);
		sides.push_back(b);
		sides.push_back(H);
		sides.push_back((2.0*S)/b);
		sort(sides.begin(), sides.end());
		cout << setprecision(12) << (LD)sides[0] << " " << sides[1] << " " << sides[2] << endl;
	}
	return 0;
}