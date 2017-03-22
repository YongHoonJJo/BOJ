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
