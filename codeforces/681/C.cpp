using namespace std;

#include "bits/stdc++.h"

int main() {
	int n;
	cin >> n;
	vector < pair < char, int > > v;
	string str;
	int num;
	int mx = -1e9 - 1;
	priority_queue < int, vector<int>, std::greater<int> > q;
	for(int i = 0 ; i < n ; ++i) {
		cin >> str;
		if(str == "insert") {
			cin >> num;
			mx = max(mx, num);
			v.push_back(make_pair('i',num));
			q.push(num);
		} else if(str == "getMin") {
			cin >> num;
			mx = max(mx, num);
			if(q.empty()) {
				v.push_back(make_pair('i',num));
				q.push(num);
			}
			else if(num != q.top()) {
				if(num > q.top()) {
					while(!q.empty() && num > q.top()) {
						v.push_back(make_pair('r',0));
						q.pop();
					}
					if(q.empty()) {
						v.push_back(make_pair('i',num));
						q.push(num);
					}
					else {
							v.push_back(make_pair('i',num));
							q.push(num);
						}
					}
				 else {
				 	v.push_back(make_pair('i',num));
					q.push(num);
				}
			}
			v.push_back(make_pair('g',num));
		} else {
			if(q.empty()) {
				v.push_back(make_pair('i',1));
				q.push(1);
			}
			v.push_back(make_pair('r',0));
			q.pop();
		}
	}
	cout << v.size() << endl;	
	for(int i = 0 ; i < v.size() ; ++i) {
		if(v[i].first == 'i') {
			cout << "insert " << v[i].second << endl;
		} else if(v[i].first == 'g') {
			cout << "getMin " << v[i].second << endl;	
		} else {
			cout << "removeMin " << endl;
		}
	}
	return 0;
}