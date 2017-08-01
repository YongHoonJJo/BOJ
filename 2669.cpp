#include <stdio.h>

int s[101][101];

int main()
{
	int i, j;
	int tc=4, ans=0;
	while(tc--) {
		int a, b, c, d;
		scanf("%d%d%d%d", &a, &b, &c, &d);
		for(i=a; i<c; i++)
			for(j=b; j<d; j++)
				s[i][j] = 1;
	}
	
	for(i=1; i<101; i++)
		for(j=1; j<101; j++)
			if(s[i][j])
				ans++;

	printf("%d\n", ans);
	return 0;
}
