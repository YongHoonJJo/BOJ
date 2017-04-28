#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define MAXV	52
#define INF		1000000000

int ctoi(char ch)
{
	if(ch <= 'Z') return ch - 'A';
	return ch - 'a' + 26;
}

int main()
{
	int i, n;
	int f[MAXV][MAXV] = {0};
	int c[MAXV][MAXV] = {0};
	vector<int> v[MAXV];

	scanf("%d", &n);

	while(n--) {
		char a, b;
		int w;
		scanf(" %c %c %d", &a, &b, &w);
		
		a = ctoi(a);
		b = ctoi(b);
		c[a][b] += w;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	int total=0, s=0, e=25;

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

		if(from[e] == -1) break;

		int flow = INF;
	
		for(i=e; i!=s; i=from[i])
			flow = min(flow, c[from[i]][i]-f[from[i]][i]);

		for(i=e; i!=s; i=from[i]) {
			f[from[i]][i] += flow;
			f[i][from[i]] -= flow;
		}
		total += flow;
	}
	printf("%d\n", total);
}
