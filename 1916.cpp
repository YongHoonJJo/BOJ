#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define MAX	1001
#define INF	1000000000
typedef pair<int, int> P;

int main()
{
	int n, m;
	int a, b, w;
	
	scanf("%d %d", &n, &m);
	
	vector<P> g[MAX];
	for(int i=0; i<m; i++) {
		scanf("%d %d %d", &a, &b, &w);
		g[a].push_back(P(b, w));
	}
	scanf("%d %d", &a, &b);

	int dist[MAX];
	fill(dist, dist+MAX, INF);
	bool visited[MAX]={0};
	priority_queue<P, vector<P>, greater<P> > pq;
	
	dist[a] = 0;
	pq.push(P(0, a));
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
			int cost = g[cur][i].second;
			if(dist[next] > dist[cur]+cost) {
				dist[next] = dist[cur]+cost;
				pq.push(P(dist[next], next));
			}
		}
	}
	printf("%d\n", dist[b]);
}
