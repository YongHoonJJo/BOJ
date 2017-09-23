#include <stdio.h>

int main()
{
	int i;
	char str[101];
	char del[]="CAMBRIDGE";
	char check[26]={0};
	scanf("%s", str);

	for(i=0; del[i]; i++)
		check[del[i]-'A'] = 1;

	for(i=0; str[i]; i++)
		if(!check[str[i]-'A'])
			printf("%c", str[i]);
	puts("");
	return 0;
}
