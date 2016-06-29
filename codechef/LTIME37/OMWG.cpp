using namespace std;

#include "bits/stdc++.h"

bool visited[1005][1005];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

bool contains(int x, int y, int n, int m) {
	return (x >= 0 && y >= 0 && x < n && y < m);
}

int main() {
	int t;
	cin >> t;
	int n,m;
	int ans;
	queue < pair < int,int> > q;
	while(t--) {
		cin >> n >> m;
		ans = 0;
		for(int i = 0 ; i < n ; ++i) {
			for(int j = 0 ; j < m ; ++j) {
				visited[i][j] = false;
			}
		}
		while(!q.empty())	q.pop();
		q.push(make_pair(0,0));
		visited[0][0] = true;
		while(!q.empty()) {
			pair <int,int> t = q.front();
			q.pop();
			for(int i = 0 ; i < 4 ; ++i) {
				int xk = t.first + dx[i];
				int yk = t.second + dy[i];
				if(contains(xk,yk,n,m)) {
					if(!visited[xk][yk]) {
						for(int j = 0 ; j < 4 ; ++j) {
							int nx = xk + dx[j];
							int ny = yk + dy[j];
							if(contains(nx,ny,n,m)) {
								if(visited[nx][ny]) ans++;
							}
						}
						visited[xk][yk] = true;
						q.push(make_pair(xk,yk));	
					}
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}