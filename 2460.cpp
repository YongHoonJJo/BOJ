#include <stdio.h>

int main()
{
	int tc=10, tmp=0, ans=0;

	while(tc--) {
		int off, on;
		scanf("%d%d", &off, &on);
		tmp += (on-off);
		if(ans < tmp) ans = tmp;
	}
	printf("%d\n", ans);
	return 0;
}
