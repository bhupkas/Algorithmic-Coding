using namespace std;

#include "bits/stdc++.h"

typedef long long LL;

vector < pair <int, int > > v[100005];

int n,m;

int P[100005];

int S[100005];

LL C[200105];

bool B[100005];

vector < pair < int , pair < int, int > > > g;

vector < pair < int , int > > G[100005];


LL getLog(LL num) {
	LL ans = 0;
	if(num <= 1)	return 0;
	while(num) num/=2, ans++;
	return ans - 1;
}

void initParent() {
	for(int i = 0 ; i < n ; ++i) P[i] = i;
	for(int i = 0 ; i < n ; ++i) S[i] = 1;
}

int getParent(int i) {
	while(i != P[i])	i = P[i];
	return i;
}

void doUnion(int a, int b) {
	int p1 = getParent(a);
	int p2 = getParent(b);
	if(S[p1] > S[p2]) {
		P[p2] = p1;
		S[p1] += S[p2];
		S[p2] = 0;
	} else {
		P[p1] = p2;
		S[p2] += S[p1];
		S[p1] = 0;
	}
}

void getMST() {
	initParent();
	sort(g.begin(),g.end());
	for(int i = 0 ; i < m ; ++i) {
		int a = g[i].second.first;
		int b = g[i].second.second;
		int c = g[i].first;
		if(getParent(a) != getParent(b)) {
			G[a].push_back(make_pair(b,c));
			G[b].push_back(make_pair(a,c));
			doUnion(a,b);
		}
	}
}

void scanGraph() {
	cin >> n >> m;
	int a,b,c;
	for(int i = 0 ; i < m ; ++i) {
		cin >> a >> b >> c;
		v[a-1].push_back(make_pair(b-1,c));
		v[b-1].push_back(make_pair(a-1,c));
		g.push_back(make_pair(c,make_pair(a-1,b-1)));
	}
}

int dfs(int x) {
	int cnt = 1;
	int val;
	for(int i = 0 ; i < G[x].size() ; ++i) {
		int y = G[x][i].first;
		int d = G[x][i].second;
		if(!B[y]) {
			B[y] = true;
			val = dfs(y);
			C[d] += (LL)(val) * (LL)(n - val);
			cnt += val;
		}
	}
	return cnt;
}

void resolve(LL a, int idx) {
	vector < LL > bi;
	while(a) {
		bi.push_back(a&1);
		a /= 2;
	}
	C[idx] = 0;
	for(int i = idx; i < idx + bi.size() ; ++i) {
		C[i] += bi[i-idx];
	}
}

vector < LL > convertAns() {
	vector < LL > s;
	int i = 0;
	int k = 200104;
	while(C[k] == 0) k--;
	for(int l = 0 ; l < k ; ++l) {
		C[l+1] += C[l]/2;
		C[l] %= 2;
	}
	while(C[k] > 1) {
		C[k+1] += C[k]/2;
		C[k] %= 2;
		k++;
	}
/*	while(C[i] > 1 || i < k) {
		resolve(C[i],i);
		i++;
	}*/
	for(int j = k ; j >= 0 ; j--) s.push_back(C[j]);
	return s;
}

void getAnswer() {
	for(int i = 0 ; i < 200105 ; ++i)	C[i] = 0;
	for(int i = 0 ; i < n ; ++i)	B[i] = false;
	B[0] = true;
	int foo = dfs(0);
}

int main() {
	scanGraph();
	getMST();
	getAnswer();
	vector < LL > ans = convertAns();
	for(int i = 0 ; i < ans.size() ; ++i) {
		cout << ans[i];
	}
	cout << endl;
	return 0;
}