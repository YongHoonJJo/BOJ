#include <stdio.h>

int main()
{
	int i, flag=0, ans=0;
	int arr1[9], arr2[9];

	for(i=0; i<9; i++) {
		scanf("%d", arr1+i);
	}
	for(i=0; i<9; i++) {
		scanf("%d", arr2+i);
	}

	for(i=0; i<9; i++) {
		ans += arr1[i];
		if(ans > 0) flag = 1;
		ans -= arr2[i];
	}
	flag ? puts("Yes") : puts("No");

	return 0;
}
