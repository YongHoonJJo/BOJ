#include <stdio.h>
#include <string.h>

#define MAX	1000001

char T[MAX], P[MAX];

int main()
{
	int n, m, fail[MAX]={0};
	int ans[MAX], idx=0;
	int i, j;

	gets(T);
	gets(P);

	n = strlen(T);
	m = strlen(P);
	

	if(n < m) {
		puts("0");
	}
	else {
		for(i=1, j=0; i<m; i++) {
			while(j>0 && P[i]!=P[j]) j=fail[j-1];
			if(P[i] == P[j]) fail[i] = ++j;
		}

		for(i=0, j=0; i<n; i++) {
			while(j>0 && T[i]!=P[j]) j=fail[j-1];
			if(T[i] == P[j]) {
				if(j == m-1) { 
					ans[idx++] = i-m+2;
					j = fail[j];
				}
				else
					j++;
			}
		}

		printf("%d\n", idx);
		for(i=0; i<idx; i++)
			printf("%d ", ans[i]);
		
	}
	return 0;
}
