using namespace std;

#include "bits/stdc++.h"

string getFourBit(char ch) {
	int n;
	if(ch > '9' || ch < '0') n = ch - 'A' + 10;
	else n = ch - '0';
	string ans = "";
	char c;
	for(int i = 0 ; i < 4 ; ++i) {
		if(n&1)	c = '1';
		else c = '0';
		ans.push_back(c);
		n/=2;
	}
	reverse(ans.begin(),ans.end());
	return ans;
}

string getBit(string str) {
	string ans = "";
	for(int i = 0 ; i < str.size() ; ++i) {
		ans += getFourBit(str[i]);
	}
	return ans;
}

string padding(int n, string str) {
	string p = "";
	for(int i = 0 ; i < n - str.size() ; ++i)	p.push_back('0');
	string ans = p + str;
	return ans;
}

string getHex(string str) {
	string ans = "";
	int n = str.size();
	for(int i = 0 ; i < str.size() ; i+= 4) {
		int num = (str[i]-'0') * 8 + (str[i+1]-'0') * 4 + (str[i+2]-'0') * 2 + (str[i+3]-'0') * 1;
		char ch;
		if(num >= 10) {
			num -= 10;
			ch = 'A' + num;
		} else {
			ch = num + '0';
		}
		ans.push_back(ch);
	}
	return ans;
}

string removePadding(string str) {
	if(str.size() <= 1)	return str;
	string ans = "";
	int i = 0;
	while(i < str.size() - 1) {
		if(str[i] == '0')	i++;
		else break;
	}
	while(i < str.size()) {
		ans.push_back(str[i]);
		i++;
	}
	return ans;
}

pair <string, string> getAns(string A, string B, string C, int k) {
	string a = getBit(A);
	string b = getBit(B);
	string c = getBit(C);
	int mx = max(a.size(), max(b.size(), c.size()));
	a = padding(mx,a);
	b = padding(mx,b);
	c = padding(mx,c);
	for(int i = 0 ; i < mx ; i++) {
		if(c[i] == '1') {
			if(a[i] != '1' && b[i] != '1') {
				b[i] = '1';
				k--;
			}
		} else {
			if(a[i] == '1') {
				a[i] = '0';
				k--;
			}
			if(b[i] == '1') {
				b[i] = '0';
				k--;
			}
		}
		if(k < 0)	return make_pair("-1","-1");
	}
	for(int i = 0 ; i < mx ; i++) {
		if(k == 0)	break;
		if(c[i] == '1') {
			if(a[i] == '1' && b[i] == '1') {
				a[i] = '0';
				k--;
			} else if(a[i] == '1') {
				if(k >= 2) {
					a[i] = '0';
					b[i] = '1';
					k -= 2;
				}
			}
		}
		if(k < 0)	break;
	}
	return make_pair(removePadding(getHex(a)),removePadding(getHex(b)));
}

int main() {
	int t;
	cin >> t;
	int k;
	string A,B,C;
	while(t--) {
		cin >> k;
		cin >> A >> B >> C;
		pair < string, string > p = getAns(A,B,C,k);
		if(p.first == "-1") {
			cout << -1 << endl;
		} else {
			cout << p.first << endl;
			cout << p.second << endl;
		}
	}
	return 0;
}