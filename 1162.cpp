#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1e9;

typedef pair<int, int> P;
typedef pair<int, P> K;

int main()
{
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);

    vector<P> g[10001];
    while(m--) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        g[a].push_back(P(b, c));
        g[b].push_back(P(a, c));
    }

    vector<vector<int> > dist(k+1, vector<int>(n+1, INF)); 
    dist[k][1] = 0; // kth pave, cur vertex

    priority_queue<K> pq;
    pq.push(K(0, P(1, k))); // dist, v, k

    bool visited[21][10001]={0}; 
  
    while(!pq.empty()) {
        int curV, curK;
        do {
            curV = pq.top().second.first;
            curK = pq.top().second.second; 
            pq.pop();
        } while(!pq.empty() && visited[curK][curV]);
  
        if(visited[curK][curV]) break;
        visited[curK][curV] = 1;

        for(auto &p : g[curV]) {
            int nextV = p.first;
            int d = p.second;
            
            if(dist[curK][nextV] > dist[curK][curV] + d) {
                dist[curK][nextV] = dist[curK][curV] + d;
                pq.push(K(-dist[curK][nextV], P(nextV, curK)));
            }
            if(curK-1 >= 0 && dist[curK-1][nextV] > dist[curK][curV]) {
                dist[curK-1][nextV] = dist[curK][curV];
                pq.push(K(-dist[curK-1][nextV], P(nextV, curK-1)));
            }
        }
    }
    
    int ans = 1e9;
    for(int i=0; i<=k; i++) {
        ans = min(ans, dist[i][n]);
    }
    
    printf("%d\n", ans);
    return 0;
}
