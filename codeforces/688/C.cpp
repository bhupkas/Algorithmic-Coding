using namespace std;

#include "bits/stdc++.h"

int n,m;

vector < int > v[100005];

bool B[100005];

int cnt;

vector < int > CC[100005];

void dfs(int x, int p) {
	CC[cnt].push_back(x);
	B[x] = true;
	for(int i = 0 ; i < v[x].size() ; ++i) {
		if(!B[v[x][i]]) {
			dfs(v[x][i],x);
		}
	}
}

int C[100005];

bool T[100005];

bool g;

void color(int x) {
	for(int i = 0 ; i < v[x].size() ; ++i) {
		if(C[v[x][i]] == -1) {
			C[v[x][i]] = 1 - C[x];
			color(v[x][i]);
		} else if(C[v[x][i]] == C[x]) {
			g = true;
		}
	}
}

int main() {
	g = false;
	cin >> n >> m;
	cnt = 0;
	int x,y;
	for(int i = 0 ; i < n ; ++i) B[i] = false, C[i] = -1, T[i] = true;
	for(int i = 0 ; i < m ; ++i) {
		cin >> x >> y;
		x--;
		y--;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for(int i = 0 ; i < n ; ++i) {
		if(!B[i]) {
			dfs(i,-1);
			cnt++;
		}
	}
	for(int i = 0 ; i < cnt ; ++i) {
		if(CC[i].size() == 1) {
			T[CC[i][0]] = false;
		}
	}
	for(int i = 0 ; i < n ; ++i) {
		if((C[i] == -1) && T[i]) {
			C[i] = 0;
			color(i);
		}
	}
	if(g) {
		cout << -1 << endl;
		return 0;
	}
	vector < int > ans1,ans2;
	for(int i = 0 ; i < n ; ++i) {
		if(C[i] == 1)	ans1.push_back(i+1);
		else if(C[i] == 0)	ans2.push_back(i+1);
	}
	cout << ans1.size() << endl;
	for(int i = 0 ; i < ans1.size() ; ++i) cout << ans1[i] << " ";
	cout << endl;
	cout << ans2.size() << endl;
	for(int i = 0 ; i < ans2.size() ; ++i) cout << ans2[i] << " ";
	cout << endl;

	return 0;
}