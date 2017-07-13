#include <stdio.h>

int main()
{
	int i, n, prev, ans=0;
	int roof[1001]={0};
	int maxH=0, hIdx=0;
	int maxL=0, minL=1000;
	
	scanf("%d", &n);
	while(n--) {
		int l, h;
		scanf("%d%d", &l, &h);
		if(!roof[l] ||roof[l] > h) {
			roof[l] = h;
			if(maxH	< h) {
				maxH = h;
				hIdx = l;
			}
			if(maxL < l)
				maxL = l;
			if(minL > l)
				minL = l;
		}
	}

	prev = roof[minL];
	for(i=minL; i<=hIdx; i++) {
		if(prev >= roof[i])
			ans += prev;
		else {
			ans += roof[i];
			prev = roof[i];
		}
	}

	prev = roof[maxL];
	for(i=maxL; i>hIdx; i--) {
		if(prev >= roof[i])
			ans += prev;
		else {
			ans += roof[i];
			prev = roof[i];
		}
	}
	printf("%d\n", ans);
	return 0;
}
