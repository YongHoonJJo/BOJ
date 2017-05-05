#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

#define MAXV	801
#define INF		0x7fffffff/3

typedef pair<int, int> P;

vector<P> g[MAXV];

void dijkstra(int s, int dist[])
{
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
}

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	while(m--) {
		int a, b, w;
		scanf("%d%d%d", &a, &b, &w);
		g[a].push_back(P(b, w));
		g[b].push_back(P(a, w));
	}

	int a, b;
	long long ans, ans2;
	scanf("%d%d", &a, &b);

	int dist1[MAXV], distA[MAXV], distB[MAXV];
	for(int i=0; i<=n; i++)
		dist1[i] = distA[i] = distB[i] = INF;

	dijkstra(1, dist1);	
	dijkstra(a, distA);	
	dijkstra(b, distB);	

	ans = dist1[a] + distA[b] + distB[n];
	ans2 = dist1[b] + distB[a] + distA[n];

	if(ans > ans2)
		ans = ans2;

	if(ans >= INF) 
		ans = -1;

	printf("%lld\n", ans);

}
