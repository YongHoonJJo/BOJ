#include <stdio.h>

int main()
{
	int i, tc=3;
	while(tc--) {
		char n[9];
		int cnt=1, ans=1;
		scanf("%s", n);
		
		for(i=1; i<8; i++) {
			if(n[i-1] == n[i]) {
				cnt++;
				if(ans < cnt)
					ans = cnt;
			}
			else
				cnt = 1;
		}
		printf("%d\n", ans);
	}

	return 0;
}
