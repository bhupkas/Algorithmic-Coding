using namespace std;

#include "bits/stdc++.h"

int getAns(string str) {
	int i = 0;
	int j = 1;
	map <char, bool> m;
	m[str[0]] = true;
	int ans = 1;
	while(j < str.size()) {
		if(m.find(str[j]) == m.end()) {
			m[str[j]] = true;
			j++;
			ans = max(ans, j - i);
		} else {
			while(m.find(str[j]) != m.end()) {
				m.erase(str[i]);
				i++;
			}
		}
	}
	return ans;
}

int main() {
	string str;
	cin >> str;
	cout << getAns(str) << endl;
	return 0;
}