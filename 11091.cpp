#include <stdio.h>
#include <string.h>

int main()
{
	int tc;
	scanf("%d", &tc);
	getchar();
	while(tc--) {
		char str[101], ch[26]={0};
		int i, len, miss=26;
		gets(str);
		len = strlen(str);
		for(i=0; i<len; i++) {
			if('a' <= str[i] && str[i] <='z')
				ch[str[i]-'a']++;
			else if('A' <= str[i] && str[i] <= 'Z')
				ch[str[i]-'A']++;
			else
				;
		}
		for(i=0; i<26; i++) {
			if(ch[i])
				miss--;
		}
		if(miss) {
			printf("missing ");
			for(i=0; i<26; i++)
				if(!ch[i])
					printf("%c", i+'a');
			puts("");
		}
		else
			puts("pangram");
	}

	return 0;
}
