#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

#define MAX	100001

int ans, from[MAX];
bool visited[MAX];

void path(int k)
{
	if(k == -1) return ;
	path(from[k]);
	printf("%d ", k);
}

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);

	memset(from, -1, sizeof(from));

	queue<int> q;
	q.push(n);
	visited[n] = 1;
	while(!q.empty()) {
		int sz = q.size();
		for(int i=0; i<sz; i++) {
			int x = q.front();
			q.pop();
			
			if(x == k) {
				printf("%d\n", ans);
				path(k);
				return 0;
			}

			if(0 <= x-1 && !visited[x-1]) { q.push(x-1); visited[x-1]=1; from[x-1] = x; }
			if(x+1 < MAX && !visited[x+1]) { q.push(x+1); visited[x+1]=1; from[x+1] = x; }
			if(x*2 < MAX && !visited[x*2]) { q.push(x*2); visited[x*2]=1; from[x*2] = x; }
		}
		ans++;
	}
}
