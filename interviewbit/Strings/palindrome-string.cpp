using namespace std;

#include "bits/stdc++.h"

bool isAlphaNumeric(char ch) {
	if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '1' && ch <= '9'))	return true;
	return false;
}

char getLower(char ch) {
	if(ch >= 'A' && ch <= 'Z')	ch = ch - 'A' + 'a';
	return ch;
}

int palin(string str) {
	int n = str.size();
	int i = 0;
	int j = n - 1;
	while(i < j) {
		if(!isAlphaNumeric(str[i])) {
			i++;
			continue;
		}
		if(!isAlphaNumeric(str[j])) {
			j--;
			continue;
		}
		if(getLower(str[i]) != getLower(str[j])) {
			return 0;
		}
		i++;
		j--;
	}
	return 1;
}

int main() {
	string str;
	cin >> str;
	cout << palin(str) << endl;
	return 0;
}
