#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

#define MAXV	1001
#define INF		1000000000

typedef pair<int, int> P;

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);

	vector<P> g[MAXV];

	while(m--) {
		int a, b, w;
		scanf("%d%d%d", &a, &b, &w);
		g[a].push_back(P(b, w));		
	}
	
	int s, e;
	scanf("%d%d", &s, &e);
	
	int dist[MAXV];
	fill(dist, dist+MAXV, INF);
	
	bool visited[MAXV]={0};
	priority_queue<P, vector<P>, greater<P> > pq;
	
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
		for(auto &p : g[cur]) {
			int next = p.first, d = p.second;
			if(dist[next] > dist[cur] + d) {
				dist[next] = dist[cur] + d;
				pq.push(P(dist[next], next));
			}
		}
	}
	printf("%d\n", dist[e]);
}
