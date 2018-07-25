#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int n, m, s, e;
const int INF=1e9;
typedef pair<int, int> P;

bool check[501];

void remove(vector<int> *from, int path[][501], int next)
{
    if(next == s) return ; 

    for(int i=0; i<from[next].size(); i++) {
        int cur = from[next][i];
        path[cur][next] = INF;
        remove(from, path, cur);
    }

}

int dijkstra(vector<P> *g, int path[][501], vector<int> &distE)
{
    priority_queue<P> pq;
    pq.push(P(0, s));

    vector<int> dist(n+1, INF);
    dist[s] = 0;

    vector<bool> visited(n+1, 0);
    vector<int> from[501];

    while(!pq.empty()) {
        int cur;
        do {
            cur = pq.top().second;
            pq.pop();
        } while(!pq.empty() && visited[cur]);

        if(visited[cur]) break;

        visited[cur] = 1;

        for(auto &p : g[cur]) {
            int next = p.first;
            int d = path[cur][next];

            if(dist[cur] + d == distE[next]) {
                from[next].push_back(cur);
            }

            if(dist[next] > dist[cur] + d) {
                dist[next] = dist[cur] + d;
                pq.push(P(-dist[next], next));
            }
        }
    }
  
    remove(from, path, e);

    return dist[e];    
}

int main()
{
    while(1) {
        scanf("%d%d", &n, &m);
        if(n == 0 && m == 0) break;

        scanf("%d%d", &s, &e);

        vector<P> g[501];
        int path[501][501]={0};
        while(m--) {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            g[a].push_back(P(b, c));
            path[a][b] = c;
        }

        priority_queue<P> pq;
        pq.push(P(0, s));

        vector<int> dist(n+1, INF);
        dist[s] = 0;

        vector<bool> visited(n+1, 0);

        while(!pq.empty()) {
            int cur;
            do {
                cur = pq.top().second;
                pq.pop();
            } while(!pq.empty() && visited[cur]);

            if(visited[cur]) break;

            visited[cur] = 1;

            for(auto &p : g[cur]) {
                int next = p.first;
                int d = path[cur][next];

                if(dist[next] > dist[cur] + d) {
                    dist[next] = dist[cur] + d;
                    pq.push(P(-dist[next], next));
                }
            }
        }

        if(dist[e] == INF) {
            puts("-1");
            continue;
        }

       int ans;
        do {
            ans = dijkstra(g, path, dist);
        } while(ans == dist[e]);

        if(ans == INF) ans = -1;
        printf("%d\n", ans);
    }
    return 0;
}
