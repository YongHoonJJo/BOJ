#include <stdio.h>

int B[100000];
int n, m;

int bs(int mid)
{
	int i, cnt=1, sum=0;
	for(i=0; i<n; i++) {
		if(sum+B[i] > mid) {
			sum = 0;
			cnt++;
		}
		sum += B[i];
	}
	return cnt <= m;
}

int main()
{
	int i, s=1, e=0;
	scanf("%d%d", &n, &m);

	for(i=0; i<n; i++) {
		scanf("%d", B+i);
		e += B[i];
		if(s < B[i]) s = B[i];
	}

	while(s <= e) {
		int mid = (s + e)/2;
		if(bs(mid)) e = mid-1;
		else s = mid+1;
	}
	printf("%d\n", s);
	return 0;
}


