#include <stdio.h>

int g[401][401];

int main()
{
	int N, K, S;
	int i, j, k;
	int a, b;
	scanf("%d%d", &N, &K);

	while(K--) {
		scanf("%d%d", &a, &b);
		g[a][b] = 1;
	}

	for(k=1; k<=N; k++)
		for(i=1; i<=N; i++)
			for(j=1; j<=N; j++)
				if(g[i][k] && g[k][j])
					g[i][j] = 1;

	scanf("%d", &S);
	while(S--) {
		scanf("%d%d", &a, &b);
		if(g[a][b]) puts("-1");
		else g[b][a] ? puts("1") : puts("0");  
	}

	return 0;
}
