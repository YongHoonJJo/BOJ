#include <stdio.h>

void mBinary(int n)
{
	if(!n) return ;
	if(n%2 == 0) {
		mBinary(-(n/2));
		printf("0");
	}
	else {
		if(n>0) mBinary(-(n/2));
		else {
			// -2 * 7 = -14 + 1 = -13
			mBinary((-n+1)/2);
		}
		printf("1");
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	if(n) mBinary(n);
	else puts("0");
	return 0;
}
