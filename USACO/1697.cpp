#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

bool safe(int k)
{
    return (0 <= k && k <= 100000);
}

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);

    queue<int> q;
    q.push(n);

    int visited[100001]={0};
    visited[n] = 1;

    while(!q.empty()) {
        int cur = q.front(); q.pop();
        if(cur == k) break;
       
        int next = cur+1;
        if(safe(next) && !visited[next]) { q.push(next); visited[next] = visited[cur]+1; } 
        
        next = cur-1;
        if(safe(next) && !visited[next]) { q.push(next); visited[next] = visited[cur]+1; } 

        next = cur*2;
        if(safe(next) && !visited[next]) { q.push(next); visited[next] = visited[cur]+1; } 
    }
    printf("%d\n", visited[k]-1);
}

