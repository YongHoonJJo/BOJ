#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> P;
const int INF=1000000000;

int n, m, x;

vector<int> dijkstra(int s, vector<P>* g)
{
	int i, k;
	vector<int> dist(n+1, INF);
	vector<bool> visit(n+1, 0);
	priority_queue<P, vector<P>, greater<P> > pq;

	dist[s]=0;
	pq.push(P(0,s));

	while(!pq.empty()) {
		int from;
		do {
			from = pq.top().second;
			pq.pop();
		} while(!pq.empty() && visit[from]);

		if(visit[from]) break;
		visit[from] = true;

		for(k=0; k<g[from].size(); k++) {
			int to = g[from][k].first;
			int cost = g[from][k].second;
			if(dist[to] > dist[from] + cost) {
				dist[to] = dist[from] + cost;
				pq.push(P(dist[to], to));
			}
		}
	}
	return vector<int>(dist);  
}

int main()
{
	int i, ans=0;
	vector<P> g[1001], g2[1001];
	scanf("%d %d %d", &n, &m, &x);

	while(m--) {
		int a, b, t;
		scanf("%d %d %d", &a, &b, &t);
		g[a].push_back(P(b, t));
		g2[b].push_back(P(a, t));
	}

	vector<int> d1 = dijkstra(x, g);
	vector<int> d2 = dijkstra(x, g2);

	for(i=1; i<=n; i++)
		ans = max(ans, d1[i]+d2[i]);

	printf("%d\n", ans);
	return 0;
}


