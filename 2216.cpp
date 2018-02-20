#include <stdio.h>
#include <string.h>
#define mINF 0x80000000

int a, b, c;
int slen, tlen;
char s[3005], t[3005];
int d[3005][3005];

int max(int x, int y)
{
    return x > y ? x : y;
}

int go(int si, int ti)
{
    int ret = mINF;
    if(d[si][ti]!=mINF) return d[si][ti];

    if(si == slen) return b * (tlen-ti);
    if(ti == tlen) return b * (slen-si);

    if(s[si] == t[ti])
        ret = max(ret, go(si+1, ti+1)+a);
    if(s[si] != t[ti])
        ret = max(ret, go(si+1, ti+1)+c);
    ret = max(ret, go(si+1, ti)+b);
    ret = max(ret, go(si, ti+1)+b);
    return d[si][ti] = ret; 
}

int main()
{
    int i, j;
    scanf("%d%d%d%s%s", &a, &b, &c, s, t);
    slen = strlen(s);
    tlen = strlen(t);
    for(i=0; i<3005; i++) for(j=0; j<3005; j++) d[i][j] = mINF;
    printf("%d\n", go(0, 0)); 
    return 0;
}
