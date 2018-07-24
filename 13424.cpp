#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

const int INF=1e9;
typedef pair<int, int> P;

int main()
{
    int tc;
    scanf("%d", &tc);

    while(tc--) {
        int n, m;
        scanf("%d%d", &n, &m);

        vector<P> g[101];
        while(m--) {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            g[a].push_back(P(b, c));
            g[b].push_back(P(a, c));
        }
        
        int k, f;
        scanf("%d", &k);
        
        vector<int> ans(n+1, 0);
        for(int i=0; i<k; i++) {
            scanf("%d", &f);
            vector<bool> visited(n+1);
            vector<int> dist(n+1, INF);
            dist[f] = 0;

            priority_queue<P> pq;
            pq.push(P(0, f));

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
                    int d = p.second;
                    if(dist[next] > dist[cur] + d) {
                        dist[next] = dist[cur] + d;
                        pq.push(P(-dist[next], next));
                    }
                }
            }
            for(int i=0; i<=n; i++) {
                ans[i] += dist[i]; 
            }
        }

        int idx=1, minD=INF; 
        for(int i=1; i<=n; i++) {
            if(minD > ans[i]) {
                minD = ans[i];
                idx = i;
            }
        }
        printf("%d\n", idx);
    }
}

