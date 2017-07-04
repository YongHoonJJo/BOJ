#include <stdio.h>

int main()
{
	int i, n, k; 
	int ok=0, ans=-1;
	scanf("%d", &n);
	
	k = n/5;

	for(i=k; i>=0; i--) {
		int t = n-(5*i); 
		if(t%3 == 0) {
			ans = i + (t/3);
			break;
		}
	}

	printf("%d\n", ans);
	return 0;
}
