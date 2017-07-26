#include <stdio.h>
#include <string.h>

char dna[501];
int d[501][501];

int Max(int a, int b)
{
	return a > b ? a : b;
}

int go(int s, int e)
{
	int i, ret = d[s][e];
	if(s >= e) return 0;
	if(ret != -1) return ret;

	ret = 0;
	if(dna[s]=='a' && dna[e]=='t') ret = go(s+1, e-1)+2;
	else if(dna[s]=='g'&&dna[e]=='c') ret = go(s+1, e-1)+2;
	for(i=s; i<e; i++) {
		ret = Max(ret, go(s, i)+go(i+1, e));
	}		

	return d[s][e] = ret;	
}

int main()
{
	int len;
	scanf("%s", dna);

	len = strlen(dna);
	memset(d, -1, sizeof(d));
	printf("%d\n", go(0, len-1));

	return 0;
}
