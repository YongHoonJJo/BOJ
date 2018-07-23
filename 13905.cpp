#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

struct P { int to, w; };

int n, m;
int s, e;
vector<P> g[100001];

bool isPossible(int mid)
{
    queue<int> q;
    q.push(s);

    vector<bool> visited(n+1, 0);
    visited[s] = 1;

    while(!q.empty()) {
        int cur = q.front(); q.pop();

        for(auto &p : g[cur]) {
            int next = p.to;
            int w = p.w;
            if(!visited[next] && mid <= w) {
                if(next == e) return 1;
                visited[next] = 1;
                q.push(next);
            }
        }
    }
    return 0;
}

int main()
{
    scanf("%d%d%d%d", &n, &m, &s, &e);

    while(m--) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        g[a].push_back((P){b, c});
        g[b].push_back((P){a, c});
    }

    if(s == e) return !printf("0\n");

    int S=1, E=1000000;
    while(S <= E) {
        int mid = (S+E)/2;
        if(isPossible(mid)) S = mid+1;
        else E = mid-1;
    }
    printf("%d\n", S-1);
    return 0;
}
