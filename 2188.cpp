#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define MAXN	200
#define MAXV	MAXN*2+2

int main()
{
	int i, n, m;
	const int s = MAXV-2;
	const int e = MAXV-1;
	scanf("%d %d", &n, &m);
	
	int f[MAXV][MAXV];
	int c[MAXV][MAXV];
	vector<int> v[MAXV];

	for(i=0; i<n; i++) {
		int k, j;
		scanf("%d", &k);
		while(k--) {
			scanf("%d", &j);
			j = MAXN+j-1;
			c[i][j]=1;
			v[i].push_back(j);
			v[j].push_back(i);
		}
		c[s][i] = 1;
		v[s].push_back(i);
		v[i].push_back(s);
	}
	
	for(i=MAXN; i<MAXN+m; i++) {
		c[i][e] = 1;
		v[i].push_back(e);
		v[e].push_back(i);
	}

	int total=0; 

	while(1) {
		int from[MAXV];
		fill(from, from+MAXV, -1);

		queue<int> q;
		q.push(s);
		while(!q.empty()) {
			int cur = q.front();
			q.pop();

			if(cur == e) break;

			for(i=0; i<v[cur].size(); i++) {
				int next = v[cur][i];
				if(c[cur][next]-f[cur][next]>0 && from[next]==-1) {
					q.push(next);
					from[next] = cur;
				}
			}
		}
	
		if(from[e] == -1)
			break;
		
		for(i=e; i!=s; i=from[i]) {
			f[from[i]][i]++;
			f[i][from[i]]--;
		}
		total++;
	}
	printf("%d\n", total);
}
