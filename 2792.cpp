#include <stdio.h>

int n, m;
int jw[300001];

int isPossible(int mid)
{
	int i, cnt=0;
	for(i=0; i<m; i++) {
		cnt += jw[i]/mid;
		if(jw[i]%mid) cnt++;
	}
	return cnt <= n;
}

int main()
{
	int i, s=1, e=0;
	scanf("%d%d", &n, &m);

	for(i=0; i<m; i++) {
		scanf("%d", jw+i);
		if(e < jw[i]) e = jw[i];
	}

	while(s <= e) {
		int mid = (s + e)/2;
		if(isPossible(mid)) e = mid-1;
		else s = mid+1;
	}
	
	printf("%d\n", s);
	return 0;
}
