#include <stdio.h>
#include <string.h>

int d[101][101];
int pLen, fLen;
char p[101], f[101];

int go(int pn, int fn)
{
	int i, ret = d[pn][fn];
	if(ret != -1) return ret;
	if(pn == pLen && fn == fLen) {
		return 1;	
	}
	ret = 0;
	if(p[pn] == f[fn]) ret = go(pn+1, fn+1);
	else if(p[pn] == '*') {
		for(i=fn; i<=fLen; i++)
			ret |= go(pn+1, i);
	}
	return d[pn][fn]=ret;
}

int main()
{
	int n;
	scanf("%s%d", p, &n);
	pLen = strlen(p);

	while(n--) {
		scanf("%s", f);
		fLen = strlen(f);

		memset(d, -1, sizeof(d));
		if(go(0, 0)) puts(f);
	}

	return 0;
}
