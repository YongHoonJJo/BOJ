#include <stdio.h>

int main()
{
	int n;
	char s[81];

	scanf("%d", &n);
	while(n--) {
		int i=0, cnt=0, ans=0;
		scanf("%s", s);
		while(s[i]) {
			if(s[i++] == 'O') cnt++;
			else cnt = 0;
			ans += cnt;
		}
		printf("%d\n", ans);
	}

	return 0;
}
