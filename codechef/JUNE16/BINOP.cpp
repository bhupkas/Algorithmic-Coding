using namespace std;

#include "bits/stdc++.h"

pair <int, int> getCnt(string a) {
	int arr[2];
	arr[0] = arr[1] = 0;
	for(int i = 0 ; i < a.size() ; ++i) {
		arr[a[i] - '0']++;
	}
	return make_pair(arr[0],arr[1]);
}

pair <int,int> getDiff(string a, string b) {
	int cnt1, cnt2;
	cnt1 = cnt2 = 0;
	for(int i = 0 ; i < a.size() ; ++i) {
		if(a[i] == '0' && b[i] == '1')	cnt1++;
		if(a[i] == '1' && b[i] == '0')	cnt2++;
	}
	return make_pair(cnt1,cnt2);
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		string a,b;
		cin >> a >> b;
		pair<int,int> f,s;
		f = getCnt(a);
		s = getCnt(b);
		if(!(f.first) || !(f.second)) {
			puts("Unlucky Chef");
			continue;
		}
		puts("Lucky Chef");	
		pair <int,int> res = getDiff(a,b);
		cout << max(res.first,res.second) << endl;
 	}
	return 0;
}