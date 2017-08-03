#include <stdio.h>
#include <string.h>

int mod = 1000000, d[5001];

int go(char s[], int n)
{
	if(!n || n==1) return 1;
	if(d[n]) return d[n];

	if(s[n]-'0') d[n] = go(s, n-1)%mod;
	if(s[n-1] != '0') {
		int x = (s[n-1]-'0')*10 + (s[n]-'0');
		if(10 <= x && x <= 26)
			d[n] = (d[n] + go(s, n-2))%mod;
	}

	return d[n]%mod;
}

int main()
{
	char a[5002];
	int n;
	scanf("%s", a+1);

	n = strlen(a+1);
	if(n == 1 && a[1]=='0')
		puts("0");
	else
		printf("%d\n", go(a, n));

	return 0;
}


