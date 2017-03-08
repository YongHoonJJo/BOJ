#include <stdio.h>

char set[9], check[9];

void permutation(int s, int n, int idx)
{
	int i;
	check[s] = 1;
	set[idx] = s+'0';
	
	if(idx == n-1) {
		for(i=0; i<n; i++) {
			printf("%c ", set[i]);
		}
		puts("");
		return ;
	}

	for(i=1; i<=n; i++) {
		if(!check[i]) {
			permutation(i, n, idx+1);
			check[i] = 0;
		}
	}
}

int main()
{
	int i, n;
	scanf("%d", &n);

	for(i=1; i<=n; i++) {
		permutation(i, n, 0);
		check[i] = 0;
	}

	return 0;
}
