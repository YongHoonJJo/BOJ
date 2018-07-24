#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

typedef long long int lli;
const lli INF = 1e15;
typedef pair<int, int> P;

int main()
{
    int tc;
    scanf("%d", &tc);

    while(tc--) {
        int n, d, c;
        scanf("%d%d%d", &n, &d, &c);

        vector<P> g[10001];
        for(int i=0; i<d; i++) {
            int a, b, s;
            scanf("%d%d%d", &a, &b, &s);
            // a 가 b를 의존
            // b 가 감염되면 s초 후에 a도 감염.
            g[b].push_back(P(a, s));
        }
    
        priority_queue<P> pq;
        pq.push(P(0, c)); 

        vector<bool> visited(n+1);
        vector<lli> dist(n+1, INF);
        dist[c] = 0;

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

        int cnt=0, time=0;
        for(int i=1; i<=n; i++) {
            if(dist[i] != INF) {
                cnt++;
                if(time < dist[i])
                    time = dist[i];
            }
        }
        printf("%d %d\n", cnt, time);
    }
    return 0;
}

