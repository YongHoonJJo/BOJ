#include <stdio.h>

int main()
{
	int i=0, ans=0;
	char str[1000001];
	gets(str);

	while(str[i]) {
		if(('A' <= str[i] && str[i] <= 'Z') || ('a' <= str[i] && str[i] <= 'z')) {
			ans++;
			while(str[i] && (('A' <= str[i] && str[i] <= 'Z') || ('a' <= str[i] && str[i] <= 'z')))
				i++;
		}
		else
			i++;
		
	}
	printf("%d\n", ans);
	return 0;
}
