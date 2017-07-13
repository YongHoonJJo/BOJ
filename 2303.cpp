#include <stdio.h>

int main()
{
	int i, j, k, n;
	int card[1000][5];
	int sum[1000]={0};
	int ans[1000]={0};
	int idx=0, Max=0;
	scanf("%d", &n);

	for(i=0; i<n; i++) { 
		for(j=0; j<5; j++) {
			scanf("%d", &card[i][j]);
			sum[i] += card[i][j];
		}
	}

	for(i=0; i<n; i++) {
		for(j=0; j<4; j++) {
			for(k=j+1; k<5; k++) {
				if(j != k) {
					int t = (sum[i]-card[i][j]-card[i][k])%10;
					if(ans[i] < t)
						ans[i] = t;
				}
			}
		}
	}

	for(i=0; i<n; i++) {
		if(Max <= ans[i]) {
			Max = ans[i];
			idx = i;
		}
	}

	printf("%d\n", idx+1);
	return 0;
}
