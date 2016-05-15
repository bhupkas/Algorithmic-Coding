using namespace std;

#include "bits/stdc++.h"

int getLength(int num) {
	if(num == 0)	return 1;
	int cnt = 0;
	while(num) {
		num /= 10;
		cnt++;
	}
	return cnt;
}

void dfs(int start, int end, int num, int len, vector < int > &ans) {
	if(len == 0)
	{
		if(num >= start && num <= end) {
			ans.push_back(num);
		}
		return;
	}
	int a = num % 10;
	if(a == 0)	{
		dfs(start,end,num *10 +1,len-1,ans);
	} else if(a == 9) {
		dfs(start,end,num*10 +8, len-1,ans);
	} else {
		dfs(start,end,num*10 + a - 1, len-1,ans);
		dfs(start,end,num*10 + a + 1, len-1,ans);
	}
}

vector < int > getSol(int n, int m) {
	int a = getLength(n);
	int b = getLength(m);
	vector < int > ans;
	if(n == 0)	ans.push_back(0);
	for(int i = a ; i <= b ; ++i) {
		for(int j = 1 ; j <= 9 ; ++j) {
			dfs(n,m,j,i-1,ans);
		}
	}
	return ans;
}

int main() {
	int n,m;
	cin >> n >> m;
	vector < int > ans = getSol(n,m);
	for(int i = 0 ; i < ans.size() ; ++i)	{
		cout << ans[i] << " ";
	}
	cout << endl;
	return 0;
}