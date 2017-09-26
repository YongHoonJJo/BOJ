#include <stdio.h>

int tc;

int main()
{
	while(1) {
		char s[2001];
		int st[2001], top=0;
		int i, ans=0;
		scanf("%s", s);
		if(s[0] == '-') break;

		for(i=0; s[i]; i++) {
			if(s[i] == '{')
				st[top++] = 1;
			else {
				if(st[top-1] == 1) top--;
				else st[top++] = 2;
			}
		}
		i=0; top--;
		while(i < top) {
			if(st[i] == st[i+1]) ans++; 
			else ans += 2;
			i += 2;
		}
		tc++;
		printf("%d. %d\n", tc, ans);
	}
	return 0;
}
