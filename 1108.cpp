#include <cstdio>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

map<string, int> mp;
vector<vector<int> > v, scc;
vector<int> sn, dfsn;
vector<bool> finished;
stack<int> S;
int cnt, SN;

int dfs(int cur)
{
	int ret = dfsn[cur] = ++cnt;
	S.push(cur);

	for(int i=0; i<v[cur].size(); i++) {
		int next = v[cur][i];
		if(!dfsn[next]) ret = min(ret, dfs(next));
		else if(!finished[next]) ret = min(ret, dfsn[next]);
	}

	if(ret == dfsn[cur]) {
		vector<int> curScc;
		while(1) {
			int t = S.top();
			S.pop();
			finished[t] = 1;
			sn[t] = SN;
			curScc.push_back(t);
			if(t == cur) break;
		}
		SN++;
		scc.push_back(curScc);
	}
	return ret;
}

int main()
{
	int n, pos=0;
	scanf("%d", &n);

	v = vector<vector<int> >(2501);
	while(n--) {
		int k;
		string next;
		cin >> next >> k;
		if(!mp[next]) mp[next] = ++pos;	
		
		while(k--) {
			int x = mp[next];
			string cur;
			cin >> cur;
			if(!mp[cur]) mp[cur] = ++pos;
			v[mp[cur]].push_back(x);
		}
	}
	string w;
	cin >> w;
	if(!mp[w]) mp[w] = ++pos;

	sn = dfsn = vector<int>(pos+1, 0);
	finished = vector<bool>(pos+1, 0);
	for(int i=1; i<=pos; i++)
		if(!dfsn[i])
			dfs(i);

	vector<int> ind(SN, 0);
	vector<vector<int> > g(SN);
	for(int i=1; i<=pos; i++) {
		for(int j=0; j<v[i].size(); j++) {
			int k = v[i][j];
			if(sn[i] != sn[k]) {
				g[sn[i]].push_back(sn[k]);
				ind[sn[k]]++;
			}
		}
	}
	
	queue<int> q;
	for(int i=0; i<SN; i++)
		if(!ind[i])
			q.push(i);
	
	vector<long long> ans(pos+1, 1); 
	while(!q.empty()) {
		int cur = q.front();
		q.pop();

		for(int i=0; i<scc[cur].size(); i++) {
			int c = scc[cur][i];
			for(int j=0; j<v[c].size(); j++) {
				int k = v[c][j];
				if(sn[c] != sn[k])
					ans[k] += ans[c];
			}
		}

		for(int i=0; i<g[cur].size(); i++) {
			int next = g[cur][i];
			if(--ind[next]==0) q.push(next);
		}
	}

	printf("%lld\n", ans[mp[w]]);	
}
