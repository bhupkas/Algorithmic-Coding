/* 

Exceeding Time Limit

bhupkas 

Problem Link : https://www.interviewbit.com/problems/smallest-multiple-with-0-and-1/

Problem Statement : You are given an integer N. You have to find smallest multiple of N which consists of digits 0 and 1 only. Since this multiple could be large, return it in form of a string.

*/

using namespace std;

#include "bits/stdc++.h"

string getSol(int n) {
	if(n == 0)	return "0";
	if(n == 1)	return "1";
	long long N = (long long)n;
	vector < long long > parent, state;
	for(int i = 0 ; i <= N ; ++i) {
		parent.push_back(-1);
		state.push_back(-1);
	}	
	queue <  long long  > q;
	vector < bool > visited;
	for(int i = 0 ; i <= N ; ++i)	visited.push_back(false);
	visited[1%n] = true;
	parent[1%n] = -1;
	state[1] = 1;
	string temp;
	q.push(1%n);
	while(!q.empty()) {
		long long top = q.front();
		q.pop();
		if(top == 0) {
			long long t = top;
			string ans = "";
			while(parent[t] != -1) {
				ans.push_back(state[t] + '0');
				t = parent[t];
			}
			ans.push_back('1');
			reverse(ans.begin(), ans.end());
			return ans;
		}
		long long m = top;
		m = ((long long)(m*10) + 1) % n;
		if(!visited[m]) {
			parent[m] = top;
			state[m] = 1;
			q.push(m);
			visited[m] = true;

			if(m == 0) {
				long long t = 0;
				string ans = "";
				while(parent[t] != -1) {
					ans.push_back(state[t] + '0');
					t = parent[t];
				}
				ans.push_back('1');
				reverse(ans.begin(), ans.end());
				return ans;
			}

		}
		m = top;
		m = (long long)((m*10)) % n;
		if(!visited[m]) {
			parent[m] = top;
			state[m] = 0;
			q.push(m);
			visited[m] = true;


			if(m == 0) {
				long long t = 0;
				string ans = "";
				while(parent[t] != -1) {
					ans.push_back(state[t] + '0');
					t = parent[t];
				}
				ans.push_back('1');
				reverse(ans.begin(), ans.end());
			return ans;
			}
		}
	}
}

int main() {
	int n;
	cin >> n;
	cout << getSol(n) << endl;
	return 0;
}