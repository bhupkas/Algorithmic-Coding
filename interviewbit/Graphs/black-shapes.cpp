using namespace std;

#include "bits/stdc++.h"

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

bool contains(int x, int y , int n, int m) {
	return (x >= 0 && y >= 0 && x < n && y < m);
}

void dfs(int i, int j, vector < vector < bool > > &visited, vector < string > &v) {
	if(v[i][j] != 'X' || visited[i][j])	return;
	visited[i][j] = true;
	for(int k = 0 ; k < 4 ; ++k) {
		int x = i + dx[k];
		int y = j + dy[k];
		if(contains(x,y,v.size(),v[0].size())) {
			dfs(x,y,visited,v);
		}
	}
}

int getCount(vector < string > v) {
	int n = v.size();
	int m = v[0].size();
	vector < bool > t;
	vector < vector < bool > > visited;
	for(int i = 0 ; i < m ; ++i)	t.push_back(false);
	for(int i = 0 ; i < n ; ++i)	visited.push_back(t);
	int cnt = 0;
	for(int i = 0 ; i < n ; ++i) {
		for(int j = 0 ; j < m ; ++j) {
			if(v[i][j] == 'X') {
				if(visited[i][j] == false) {
					cnt++;
					dfs(i,j,visited,v);
				}
			}
		}
	}
	return cnt;
}

int main() {
	int n,m;
	cin >> n >> m;
	vector < string > grid;
	for(int i = 0 ; i < n ; ++i)	{
		string temp;
		cin >> temp;
		grid.push_back(temp); 
	}
	cout << getCount(grid) << endl;
	return 0;
}