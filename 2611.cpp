#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

struct P { int to, cost; };

int n, m;

void go(vector<int> &from, int x)
{
	if(x != 1)	
		go(from, from[x]);
	printf("%d ", x);
}

int main()
{
	scanf("%d%d", &n, &m);

	vector<vector<P> > g(n+1);
	while(m--) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		g[a].push_back((P){b, c});
	}

	queue<int> q;
	vector<int> dist(n+1, 0);
	vector<int> from(n+1, 0);

	q.push(1);
	while(!q.empty()) {
		int sz = q.size();
		
		for(int i=0; i<sz; i++) {
			int cur = q.front();
			q.pop();

			for(int j=0; j<g[cur].size(); j++) {
				int next = g[cur][j].to;
				int cost = g[cur][j].cost;
				if(dist[next] < dist[cur]+cost) {
					dist[next] = dist[cur]+cost;
					from[next] = cur;
					if(next != 1)
						q.push(next);
				}
			}
		}
	}
	printf("%d\n", dist[1]);	
	go(from, from[1]);	
	puts("1");
}
