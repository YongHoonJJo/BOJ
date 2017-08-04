#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

int g[51][51];

int main()
{
	int n;
	scanf("%d", &n);

	while(1){
		int a, b;
		scanf("%d%d", &a, &b);
		if(a == -1) break;
		g[a][b] = g[b][a] = 1;
	}

	int cnt=0, ans=n;
	int visited[51]={0};
	int member[51]={0};
	for(int i=1; i<=n; i++) {
		cnt=-1;
		queue<int> q;
		q.push(i);
		visited[i] = i;
		while(!q.empty()) {
			int sz = q.size();
			cnt++;
			while(sz--) {
				int s = q.front(); q.pop();
				for(int k=1; k<=n; k++) {
					if(g[s][k] && visited[k]!=i) {
						visited[k] = i;
						q.push(k);
					}
				}
			}
		}
		if(ans > cnt) ans = cnt;
		member[i] = cnt;
	}
	
	cnt=0;
	for(int i=1; i<=n; i++)
		if(member[i] == ans)
			cnt++;
	printf("%d %d\n", ans, cnt);
	for(int i=1; i<=n; i++)
		if(member[i] == ans)
			printf("%d ", i);
	puts("");

}
