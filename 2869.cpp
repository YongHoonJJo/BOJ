#include <stdio.h>

int a, b, v;

int isPossible(int mid)
{
	return ((a-b)*(mid-1))+a >= v;
}

int main()
{
	int s, e;;
	scanf("%d%d%d", &a, &b, &v);

	s = 1;
	e = v; // caution..!!
	while(s <= e) {
		int mid = (s + e)/2;
		if(isPossible(mid)) e = mid-1;
		else s = mid+1;
	}
	printf("%d\n", s);
	return 0;
}
