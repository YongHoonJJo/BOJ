#include <stdio.h>

int main()
{
	int i, j;
	int n, k, ans=0;
	int room[2][7]={0};
	scanf("%d%d", &n, &k);
	
	for(i=0; i<n; i++) {
		int s, y;
		scanf("%d%d", &s, &y);
		room[s][y]++;
	}
	
	for(i=0; i<2; i++) {
		for(j=1; j<=6; j++) {
			ans += room[i][j]/k;
			if(room[i][j]%k) ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}
