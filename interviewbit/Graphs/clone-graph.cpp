using namespace std;

#include "bits/stdc++.h"

struct UndirectedGraphNode {
	int label;
	vector < UndirectedGraphNode * > neighbors;
	UndirectedGraphNode(int x) : label(x) {};
};

void dfs(UndirectedGraphNode * node, map < UndirectedGraphNode * , UndirectedGraphNode * > &mp) {
	UndirectedGraphNode * re;
	if(node == NULL)	return ;
	re = new UndirectedGraphNode(re -> label);
	vector < UndirectedGraphNode * > v;
	for(int i = 0 ; i < node -> neighbors.size() ; ++i) {
		if(mp.find(node -> neighbors[i]) == mp.end()) {
			dfs(node -> neighbors[i], mp);
		}
		v.push_back(mp[node -> neighbors[i]]);
	}
	re -> neighbors = v;
	mp[node] = re;
}

UndirectedGraphNode * cloneGraph(UndirectedGraphNode * node) {
	UndirectedGraphNode * head;
	map < UndirectedGraphNode *, UndirectedGraphNode * > mp;
	dfs(node, mp);
	return mp[node];
}

int main() {

	return 0;
}