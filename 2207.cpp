#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int n, m;
int cnt, SN;
vector<vector<int> > v;
vector<int> sn, dfsn;
vector<bool> finished;
stack<int> S;

int op(int x)
{
	return x <= n ? x+n : x-n;
}

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
		while(1) {
			int t = S.top();
			S.pop();
			finished[t] = 1;
			sn[t] = SN;
			if(t == cur) break;
		}
		SN++;
	}
	return ret;	
}

int main()
{
	scanf("%d%d", &n, &m);
	
	sn = dfsn = vector<int>(n*2+1, 0);
	v = vector<vector<int> >(n*2+1);
	finished = vector<bool>(n*2+1, 0);

	for(int i=0; i<n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		if(x < 0) x = (x*-1)+n;	
		if(y < 0) y = (y*-1)+n;
		v[op(x)].push_back(y);
		v[op(y)].push_back(x);
	}

	for(int i=1; i<=n*2; i++)
		if(!dfsn[i])
			dfs(i);

	for(int i=1; i<=n; i++) {
		if(sn[i] == sn[i+n]) {
			puts("OTL");
			return 0;
		}
	}
	puts("^_^");
}
