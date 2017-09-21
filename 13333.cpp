#include <stdio.h>

int n, qIdx[1001];

int isPossible(int mid)
{
	int i, up=0, same=0;
	for(i=0; i<n; i++) {
		if(qIdx[i] == mid) same++;
		else if(qIdx[i] > mid) up++;
	}
	return (up <= mid) && (up+same) >= mid;
}

int main()
{
	int i, ans;
	scanf("%d", &n);

	for(i=0; i<n; i++) 
		scanf("%d", qIdx+i);
	
	for(i=0; i<=10000; i++) 
		if(isPossible(i)) ans = i;
	printf("%d\n", ans);
	return 0;
}

