/*

bhupkas

Problem Link : https://www.interviewbit.com/problems/word-break-ii/

Problem Statement : Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.

Return all such possible sentences.

*/

using namespace std;

#include "bits/stdc++.h"

void recur(int st, vector < int > &space, vector < vector < bool > > & inDict, vector < string > &ans, string &str) {
	if(st >= str.size()) {
		string temp = str;
        for (int i= 0 ; i < (int)space.size()-1 ; i++){
            temp.insert(space[i]+i," ");
        }
        ans.push_back(temp);
		return;
	}
	string sub = "";
	for(int i = st; i < str.size() ; ++i) {
		sub.push_back(str[i]);
		if(inDict[st][i]) {
			space.push_back(i+1);
			recur(i + 1, space,inDict,ans,str);
			space.pop_back();
		}
	}
}

vector < string > getSol(string s, vector < string > words) {
	vector < vector < bool > > inDict ; 
	vector < string > ans ;
	string str ;
	int n = s.size();
	for(int i = 0 ; i < n ; ++i)	str.push_back(s[i]);
	vector < bool > temp;
	map < string , bool > mp;
	for(int i = 0 ; i < words.size() ; i++) {
		mp.insert(make_pair(words[i], true));
	}
	for(int i = 0 ; i < n ; ++i)	{
		temp.push_back(false);
	}
	for(int i = 0 ; i < n ; ++i) {
		inDict.push_back(temp);
	}
	for(int i = 0 ; i < n ; ++i) {
		string sub = "";
		for(int j = i ; j < n ; ++j) {
			sub.push_back(s[j]);
			if(mp.find(sub) != mp.end()) {
				inDict[i][j] = true;
			}
		}
	}
	vector < int > space;
	recur(0,space,inDict,ans,str);
	return ans;
}

int main() {
	string s;
	int n;
	cin >> s;
	cin >> n;
	vector < string > se;
	for(int i = 0 ; i < n ; ++i) {
		string s;
		cin >> s;
		se.push_back(s);
	}
	vector < string > ans;
	ans = getSol(s,se);
	for(int i = 0 ; i < ans.size() ; ++i)	{
		cout << ans[i] << endl;
	}
	return 0;
}