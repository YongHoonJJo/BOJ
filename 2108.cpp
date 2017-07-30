#include <stdio.h>

int cnt[8001];

int main()
{
	int i, n, k, Cnt;
	int Max=-4000, Min=4000;
	int mid, gap, freq=0;
	double sum=0;
	scanf("%d", &n);

	for(i=0; i<n; i++) {
		scanf("%d", &k);
		sum += (k+4000);
		if(Min > k) Min = k;
		if(Max < k) Max = k;
		cnt[k+4000]++;
	}

	gap = Max-Min;
	Cnt = (n+1)/2;
	for(i=0; i<8001; i++) {
		Cnt -= cnt[i];
		if(Cnt <= 0) {
			mid = i-4000;
			break;
		}
	}

	freq=0; Cnt=cnt[0]; 
	for(i=1; i<8001; i++) {
		if(Cnt < cnt[i]) {
			Cnt = cnt[i];
			freq = i;
		}
	}
		
	for(i=freq+1; i<8001; i++) {
		if(Cnt == cnt[i]) {
			freq = i;
			break;
		}
	}

	printf("%d\n", (int)((sum/n)+0.5)-4000);
	printf("%d\n", mid);
	printf("%d\n", freq-4000);
	printf("%d\n", gap);
	return 0;
}
