#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair<int, int> P;

int n, m, t;
const int INF = 1e9;

vector<int> dijkstra(vector<P> *v, int s)
{
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

        for(auto &p : v[cur]) {
            int next = p.first;
            int d = p.second;
            if(dist[next] > dist[cur] + d) {
                dist[next] = dist[cur] + d;
                pq.push(P(-dist[next], next));
            }
        }
    }
    return dist;
}

int main()
{
    int tc;
    scanf("%d", &tc);

    while(tc--) {
        scanf("%d%d%d", &n, &m, &t);

        int s, g, h;
        scanf("%d%d%d", &s, &g, &h);

        vector<P> v[2001];
        while(m--) {
            int a, b, d;
            scanf("%d%d%d", &a, &b, &d);
            v[a].push_back(P(b, d));
            v[b].push_back(P(a, d));
        }

        vector<int> X;
        while(t--) {
            int x;
            scanf("%d", &x);
            X.push_back(x);
        }

        vector<int> distS = dijkstra(v, s);
        vector<int> distG = dijkstra(v, g);
        vector<int> distH = dijkstra(v, h);

        vector<int> ans;
        for(int i=0; i<X.size(); i++) {
            int a = distS[g] + distG[h] + distH[X[i]];
            int b = distS[h] + distH[g] + distG[X[i]];
            if(a == distS[X[i]] || b == distS[X[i]])
                ans.push_back(X[i]);
        }

        sort(ans.begin(), ans.end());
        for(int i=0; i<ans.size(); i++)
            printf("%d ", ans[i]);
        puts("");
    }
    return 0;
}

