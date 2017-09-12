#include <stdio.h>

int ans;
int tree[1<<21], dist[1<<21];

int max(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	int i, level, node=1;
	scanf("%d", &level);
	
	for(i=0; i<=level; i++)
		node <<= 1;

	for(i=2; i<node; i++) {
		int w;
		scanf("%d", &w);
		tree[i] = w;
	}

	// dist[i] : i에서 리프까지의 거리
	for(i=node-1; i>1; i-=2) {
		dist[i/2] = max(tree[i]+dist[i], tree[i-1]+dist[i-1]);
		tree[i] = dist[i/2]-dist[i];
		tree[i-1] = dist[i/2]-dist[i-1];
		ans += (tree[i]+tree[i-1]);
	}
	
	printf("%d\n", ans);	
	return 0;
}
