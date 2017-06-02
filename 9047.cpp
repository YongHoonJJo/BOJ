#include <stdio.h>

int main()
{
	int tc;
	scanf("%d", &tc);

	while(tc--) {
		int i, n, ans=0;
		scanf("%d", &n);

		while(n != 6174) {
			int left=0, right=0;
			int ckL[10]={0}, ckR[10]={0};
			ans++;
			while(n) {
				ckL[n%10]++;
				ckR[n%10]++;
				n /= 10;
			}
			for(i=9; i>=0; i--) {
				while(ckL[i]--) {
					left *= 10;
					left += i;
				}
			}
			while(left/1000==0)
				left *= 10;
			
			for(i=0; i<10; i++) {
				while(ckR[i]--) {
					right *= 10;
					right += i;
				}
			}
			n = left-right;
		}
		printf("%d\n", ans);	
	}

	return 0;
}
