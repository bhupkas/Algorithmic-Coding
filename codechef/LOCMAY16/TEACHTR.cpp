using namespace std;

#include "bits/stdc++.h"

vector < int > getParents(vector < int > &parent, int a) {
	vector < int > res;
	while(parent[a] != a) {
		res.push_back(a);
		a = parent[a];
	}
	res.push_back(0);
	reverse(res.begin(),res.end());
	return res;
}

int getLCA(vector < int > & parent, int a, int b) {
	vector < int > l1,l2;
	l1 = getParents(parent,a);
	l2 = getParents(parent,b);
	int i;
	for(i = 0 ; i < min(l1.size(),l2.size()) ; ++i) {
		if(l1[i] == l2[i]) {
			if(l1[i] == a)	return a;
			if(l1[i] == b)	return b;
		} else break;
	}
	return -1;
}

vector < int > constructTree(vector < int > &parent, int last) {
	vector < int > res;
	while(last != 0) {
		res.push_back(last);
		last = parent[last];
	}
	res.push_back(0);
	reverse(res.begin(), res.end());
	return res;
}

vector < int > reverseMapping(vector < int > &tree) {
	int n = tree.size();
	vector < int > res(n);
	for(int i = 0 ; i < n ; ++i) {
		res[tree[i]] = i;
	}
	return res;
}

int getForOnlyOne(vector < int > &mapper, int a, int b) {
	if(mapper[a] < mapper[b])	return a;
	return b;
}

int main() {
	int n;
	cin >> n;
	vector < int > parent(n);
	vector < int > pcount(n);
	for(int i = 0 ; i < n ; ++i)	pcount[i] = 0;
	parent[0] = 0;
	int a,b;
	for(int i = 0 ; i < n - 1 ; ++i) {
		cin >> a >> b;
		parent[b-1] = a-1;
		pcount[a-1]++;
	}
	bool onlyOne = true;
	int cnt = 0;
	int last;
	for(int i = 0 ; i < n ; ++i) {
		if(pcount[i] != 1)	{
			last = i;
			cnt++;
		}
	}
	if(cnt != 1) onlyOne = false;
	vector < int > tree;
	vector < int > mapper;
	if(onlyOne) {
		tree = constructTree(parent,last);
		mapper = reverseMapping(tree);
	}
	int q;
	cin >> q;
	int ans;
	while(q--) {
		cin >> a >> b;
		if(onlyOne) {
			ans = getForOnlyOne(mapper,a-1,b-1);
		} else {
			ans = getLCA(parent,a-1,b-1);
		}
		if(ans == a-1) {
			cout << a;
			cout << " taught ";
			cout << b << endl;
		} else if(ans == b-1) {
			cout << b;
			cout << " taught ";
			cout << a << endl;
		} else {
			puts("No idea");
		}
	}
	return 0;
}