#include <stdio.h>

int isP(int n)
{
	int i, j;
	for(i=2; i<=64; i++) {
		int tmp=n, idx=0;
		int arr[10000];
		int isOk=1;
		while(tmp) {
			arr[idx++] = tmp%i;
			tmp /= i;
		}
		for(j=0; j<idx/2; j++) {
			if(arr[j]!=arr[idx-1-j]) {
				isOk = 0;
				break;
			}
		}
		if(isOk) return 1;
	}
	return 0;
}

int main()
{
	int tc;
	scanf("%d", &tc);

	while(tc--) {
		int n;
		scanf("%d", &n);
		isP(n) ? puts("1") : puts("0");
	}
	
	return 0;
}
