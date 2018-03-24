#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int F, S, G, U, D;
int visited[1000001];

int main()
{
    scanf("%d%d%d%d%d", &F, &S, &G, &U, &D);

    queue<int> q;
    q.push(S);
    visited[S] = 1;

    while(!q.empty()) {
        int cur = q.front(); q.pop();
        
        if(cur == G) break;

        int next = cur+U;
        if(next < 1000001 && !visited[next]) { q.push(next); visited[next] = visited[cur]+1; }

        next = cur-D;
        if(0 <= next && !visited[next]) { q.push(next); visited[next] = visited[cur]+1; }
    }
    
    if(!visited[G]) puts("use the stairs");
    else printf("%d\n", visited[G]-1);
}
