#include <stdio.h>

int p[102][102];
int di[] = {0, 1, 0, -1}, dj[]={1, 0, -1, 0};

int main()
{
	int i, j, k, n, ans=0;
	scanf("%d", &n);
	while(n--) {
		int a, b;
		scanf("%d%d", &a, &b);
		for(i=a; i<a+10; i++) {
			for(j=b; j<b+10; j++)
				p[i][j] = 1;
		}
	}
	for(i=1; i<101; i++) {
		for(j=1; j<101; j++) {
			if(p[i][j]) {
				for(k=0; k<4; k++)
					if(!p[i+di[k]][j+dj[k]])
						ans++;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
