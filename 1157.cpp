#include <stdio.h>

int check[26];
int idx, max, cnt;

int main()
{
	int i;
	char ch;
	while((ch=getchar()) != EOF) {
		ch <= 'Z' ? check[ch-'A']++ : check[ch-'a']++;
	}
	
	for(i=0; i<26; i++) {
		if(max < check[i]) {
			max = check[i];
			idx = i;
		}
	}

	for(i=0; i<26; i++)
		if(max == check[i])
			cnt++;
	
	if(cnt == 1) printf("%c\n", idx+'A');
	else puts("?");

	return 0;
}
