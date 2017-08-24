#include <stdio.h>

char ch;
int ans, tmp;

int main()
{
	while((ch=getchar())!=EOF) {
		if(ch == ',') {
			ans += tmp;
			tmp = 0;
		}
		else if('0' <= ch && ch <= '9') {
			tmp = tmp*10 + ch-'0';
		}
	}
	printf("%d\n", ans+tmp);
	return 0;
}
