using namespace std;

#include "bits/stdc++.h"

bool hotel(vector<int> &arrive, vector<int> &depart, int K) {
    vector < pair < int , int > > book;
    int n = arrive.size();
    for(int i = 0 ; i < n ; ++i) book.push_back(make_pair(arrive[i],depart[i]));
    sort(book.begin(),book.end());
    int mx = 1;
    int i = 0;
    int j = 1;
    int l,r;
    while(j < n) {
        if(book[j].first < book[i].second) {
            if(mx > j-i+1)	{
            	l = i;
            	r = j;
            }
            mx = max(mx,j-i+1);
            j++;
        } else {
            i++;
        }
    }
    for(int i = l ; i <= r ; ++i) {
    	cout << book[i].first << " " << book[i].second << endl;
    }
    cout << K << " " << mx << endl;
    return mx <= K;
}

bool hotel1(vector<int> &arrive, vector<int> &depart, int K) {
    vector < pair < int , int > > book;
    int n = arrive.size();
    for(int i = 0 ; i < n ; ++i) book.push_back(make_pair(depart[i],arrive[i]));
    sort(book.begin(),book.end());
    int mx = 1;
    int i = 0;
    int j = 1;
    int l,r;
    while(j < n) {
        if(book[j].second < book[i].first) {
            if(mx > j-i+1)	{
            	l = i;
            	r = j;
            }
            mx = max(mx,j-i+1);
            j++;
        } else {
            i++;
        }
    }
    for(int i = l ; i <= r ; ++i) {
    	cout << book[i].first << " " << book[i].second << endl;
    }
    cout << K << " " << mx << endl;
    return mx <= K;
}

int main() {
	vector <int> a,b;
	int k;
	int n;
	cin >> n;
	for(int i = 0 ; i < n ; ++i) {
		int t1;
		cin >> t1;
		a.push_back(t1);
	}
	for(int i = 0 ; i < n ; ++i) {
		int t1;
		cin >> t1;
		b.push_back(t1);
	}
	cin >> k;
	cout << hotel1(a,b,k) << endl;
	return 0;
}