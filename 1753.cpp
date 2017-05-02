#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define MAXV	20001
#define INF		1000000000

typedef pair<int, int> P;

int main()
{
	int n, e, s;
	scanf("%d %d %d", &n, &e, &s);

	vector<P> g[MAXV];
	while(e--) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		g[u].push_back(P(v, w));
	}
	
	int dist[MAXV];
	bool visited[MAXV]={0};
	priority_queue<P, vector<P>, greater<P> > pq;
	fill(dist, dist+MAXV, INF);

	dist[s] = 0;
	pq.push(P(0, s));
	while(!pq.empty()) {
		int cur;
		do {
			cur = pq.top().second;
			pq.pop();
		} while(!pq.empty() && visited[cur]);

		if(visited[cur]) break;
		
		visited[cur] = true;
		for(int i=0; i<g[cur].size(); i++) {
			int next = g[cur][i].first;
			int d = g[cur][i].second;
			if(dist[next] > dist[cur] + d) {
				dist[next] = dist[cur] + d;
				pq.push(P(dist[next], next));
			}
		}
	}
	
	for(int i=1; i<=n; i++) {
		if(dist[i] == INF) puts("INF");
		else printf("%d\n", dist[i]); 
	}

}
