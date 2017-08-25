#include <stdio.h>

int request[10001];
int n, deposit;

int isOk(int limit)
{
	int i, sum=0;
	for(i=0; i<n; i++) 
		sum += (request[i] < limit ? request[i] : limit);
	return sum <= deposit;
}

int main()
{
	int i, s=0, e=0;
	scanf("%d", &n);
	
	for(i=0; i<n; i++) {
		scanf("%d", request+i);
		if(e < request[i])
			e = request[i];
	}
	scanf("%d", &deposit);

	while(s <= e) {
		int mid = (s+e)/2;
		if(isOk(mid)) s = mid+1;
		else e = mid-1;
	}
	printf("%d\n", e);
	return 0;
}
