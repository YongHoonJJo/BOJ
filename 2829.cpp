#include <stdio.h>

int n, m[402][402];
int sumA[402][402], sumB[402][402];
int ans = -987654321;

int max(int a, int b)
{
	return a > b ? a : b;
}

int go(int i, int j, int k)
{
	int A=-100000000, B=0;
	if(i+k <=n && j+k <=n) {	
		A = sumA[i+k][j+k]-sumA[i-1][j-1];
	}
	j += k;
	if(j-k > 0 && i+k <= n) {
		B = sumB[i+k][j-k]-sumB[i-1][j+1];
	}
	return A-B;
}

int main()
{
	int i, j, k;
	scanf("%d", &n);

	for(i=1; i<=n; i++) {
		for(j=1; j<=n; j++) {
			scanf("%d", &m[i][j]); 
			sumA[i][j] = sumB[i][j] = m[i][j];
		}
	}

	for(i=2; i<=n; i++) {
		for(j=2; j<=n; j++)
			sumA[i][j] += sumA[i-1][j-1];
	}

	for(i=2; i<=n; i++) {
		for(j=1; j<n; j++)
			sumB[i][j] += sumB[i-1][j+1];
	
	}

	for(i=1; i<=n; i++) {
		for(j=1; j<=n; j++) { 
			for(k=0; k<n; k++) {
				ans = max(ans, go(i, j, k)); 
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
