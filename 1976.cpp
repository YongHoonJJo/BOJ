#include <stdio.h>

int p[200];

int Find(int x)
{
	if(p[x] == x) return x;
	return p[x] = Find(p[x]);
}

void Union(int a, int b)
{
	int x = Find(a);
	int y = Find(b);
	if(x != y) p[x] = y;
}

int main()
{
	int i, j;
	int n, m, k, t;
	int ok=1;


	scanf("%d %d", &n, &m);

	for(i=1; i<n; i++)
		p[i] = i;

	for(i=0; i<n; i++) {
		for(j=0; j<n; j++) {
			scanf("%d", &k);
			if(k) Union(i, j);
		}
	}

	scanf("%d", &k);
	t = Find(k);

	for(i=1; i<m; i++) {
		scanf("%d", &k);
		if(t != Find(k))
			ok = 0;
	}

	ok ? puts("YES") : puts("NO");
	return 0;
}

/*
#include <stdio.h>

int n, m;
int g[201][201];
int path[1001];

int isPossible()
{
	int i;
	for(i=1; i<m; i++)
		if(!g[path[i-1]][path[i]])
			return 0;
	return 1;
}

int main()
{
	int i, j, k;
	scanf("%d%d", &n, &m);

	for(i=1; i<=n; i++) {
		for(j=1; j<=n; j++)
			scanf("%d", &g[i][j]);
		g[i][i] = 1;
	}

	for(i=0; i<m; i++)
		scanf("%d", path+i);

	for(k=1; k<=n; k++)
		for(i=1; i<=n; i++)
			for(j=1; j<=n; j++)
				if(g[i][k] && g[k][j])
					g[i][j] = 1;

	isPossible() ? puts("YES") : puts("NO");
	return 0;
}
*/
