#include <stdio.h>

int main()
{
	int i=1, ans=10;
	char s[51];
	scanf("%s", s);

	while(s[i]) {
		ans += (s[i-1] == s[i] ? 5 : 10);
		i++;
	}
	printf("%d\n", ans);
	return 0;
}
