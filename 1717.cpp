#include <stdio.h>

int p[1000001];

int Find(int x)
{
	if(p[x]==x) return x;
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
	int i, n, m;
	scanf("%d %d", &n, &m);

	for(i=0; i<=n; i++)
		p[i] = i;

	while(m--) {
		int q, a, b;
		scanf("%d %d %d", &q, &a, &b);
		if(q) Find(a) == Find(b) ? puts("YES") : puts("NO");
		else Union(a, b);
	}

	return 0;
}
