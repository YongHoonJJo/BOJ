#include <stdio.h>

char oc[333335];

void go(int k)
{
	if(!k) return ;
	go(k/2);
	printf("%d",k%2); 
}

void go2(int k)
{
	int i=2, s[3] = {0};
	do {
		s[i--] = k%2;
		k /= 2;
	} while(k);
	i=0;
	while(i<3)
		printf("%d", s[i++]);
}

int main()
{
	int i=0;
	scanf("%s", oc);
	if(oc[0] == '0') puts("0");
	else {
		go(oc[i]-'0');
		while(oc[++i])
			go2(oc[i]-'0');
		puts("");
	}
	return 0;
}


