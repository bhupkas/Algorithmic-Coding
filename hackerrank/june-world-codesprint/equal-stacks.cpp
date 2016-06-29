using namespace std;

#include "bits/stdc++.h"

int main() {
	int ans = 0;
	int n1,n2,n3;
	cin >> n1 >> n2 >> n3;
	vector <int> v1(n1+1);
	vector <int> v2(n2+1);
	vector <int> v3(n3+1);
	int s1,s2,s3;
	s1 = s2 = s3 = 0;
	for(int i = 0 ; i < n1 ; ++i)	cin >> v1[i], s1 += v1[i];
	for(int i = 0 ; i < n2 ; ++i)	cin >> v2[i], s2 += v2[i];
	for(int i = 0 ; i < n3 ; ++i)	cin >> v3[i], s3 += v3[i];
	reverse(v1.begin(),v1.end());
	reverse(v2.begin(),v2.end());
	reverse(v3.begin(),v3.end());
	while(!(s1 == s2 && s2 == s3)) {
		if(s1 >= s2 && s1 >= s3) {
			s1 -= v1[v1.size() - 1];
			v1.pop_back();
		} else if(s2 >= s1 && s2 >= s3) {
			s2 -= v2[v2.size() - 1];
			v2.pop_back();
		} else if(s3 >= s1 && s3 >= s2) {
			s3 -= v3[v3.size() - 1];
			v3.pop_back();
		}
		ans ++;
	}
	cout << s1 << endl;
	return 0;
}