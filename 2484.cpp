#include <stdio.h>

int Max(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	int n, ans=0;
	scanf("%d", &n);

	while(n--) {
		int a, b, c, d, cnt=0;
		scanf("%d%d%d%d", &a, &b, &c, &d);
		
		if(a==b && b==c && c==d)
			cnt = 50000 + a*5000;
		else {
			if((a==b && b==c) || (a==c && a==d))
				cnt = 10000 + a*1000;
			else if((a==b && b==d) || (b==c && c==d))
				cnt = 10000 + b*1000;
			else {
				if(a==b && c==d)
					cnt = 2000 + a*500 + c*500;
				else if((a==d && b==c) || (a==c && b==d))
					cnt = 2000 + a*500 + b*500;
				else {
					if(a==b || a==c || a==d)
						cnt = 1000 + a*100;
					else if(b==c || b==d)
						cnt = 1000 + b*100;
					else if(c==d)
						cnt = 1000 + c*100;
					else {
						cnt = Max(a, Max(b, Max(c, d)));
						cnt = cnt*100;
					}
				}
			}
		}
		ans = Max(ans, cnt);
	}
	printf("%d\n", ans);
	return 0;
}
