#include <stdio.h>

char node[27][2];

void pre(char r)
{
	if(!r) return ;
	printf("%c", r); 
	pre(node[r-'A'][0]);
	pre(node[r-'A'][1]);
}

void in(char r)
{
	if(!r) return ;
	in(node[r-'A'][0]);
	printf("%c", r); 
	in(node[r-'A'][1]);
}

void post(char r)
{
	if(!r) return ;
	post(node[r-'A'][0]);
	post(node[r-'A'][1]);
	printf("%c", r); 
}

int main()
{
	int i, n;
	scanf("%d", &n);
	getchar();
	for(i=0; i<n; i++) {
		char s[10];;
		gets(s);
		if(s[2] == '.') s[2]=0;
		if(s[4] == '.') s[4]=0;
		node[s[0]-'A'][0] = s[2];
		node[s[0]-'A'][1] = s[4];
	}

	pre('A'); puts("");	
	in('A'); puts("");	
	post('A'); puts("");	

	return 0;
}
