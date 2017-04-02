#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int n, m, ind[1001];
int cnt, order[1001];
vector<int> a[1001];

int main()
{
	int i;
	scanf("%d %d", &n, &m);

	while(m--) {
		int k, u, v;
		scanf("%d %d", &k, &u);

		while(--k) {
			scanf("%d", &v);
			a[u].push_back(v);
			ind[v]++;
			u = v;
		}
	}
	
	queue<int> q;
	for(i=1; i<=n; i++)
		if(!ind[i])
			q.push(i);

	while(!q.empty()) {
		int x, sz;
		x = q.front(); q.pop();
		order[cnt++] = x;

		for(i=0; i<a[x].size(); i++) {
			int y = a[x][i];
			ind[y]--;
			if(!ind[y])
				q.push(y);
		}
	}
	
	if(cnt != n)
		puts("0");
	else {
		for(i=0; i<n; i++)
			printf("%d\n", order[i]);
	}
}
