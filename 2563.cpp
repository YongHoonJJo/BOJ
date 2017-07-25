#include <stdio.h>

int ans, p[101][101];

int main()
{
	int i, j, n;
	scanf("%d", &n);
	
	while(n--) {
		int a, b;
		scanf("%d%d", &a, &b);
		for(i=a+1; i<=a+10; i++)
			for(j=b+1; j<=b+10; j++)
				p[i][j] = 1;
	}
	
	for(i=1; i<=100; i++)
		for(j=1; j<=100; j++)
			if(!p[i][j])
				ans++;
	printf("%d\n", 10000-ans);
	return 0;
}
