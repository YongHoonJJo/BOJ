#include <stdio.h>

char str[21];
char ang[101], dev[101];
int d[101][2][21];

int bridge(int bidx, int ad, int sidx)
{
    int *ret = &d[bidx][ad][sidx];
    if(!str[sidx]) return 1;
    if(ad == 0 && !ang[bidx]) return 0;
    if(ad == 1 && !dev[bidx]) return 0;
    
    if(*ret) return *ret;

    if(ad == 0) {
        if(ang[bidx] == str[sidx])
            *ret = bridge(bidx+1, !ad, sidx+1);
        *ret += bridge(bidx+1, ad, sidx);
    }
    else {
        if(dev[bidx] == str[sidx])
            *ret = bridge(bidx+1, !ad, sidx+1);
        *ret += bridge(bidx+1, ad, sidx);
    }
    return *ret;
}

int main()
{   
    scanf("%s%s%s", str, ang, dev);
    printf("%d\n", bridge(0, 0, 0)+bridge(0, 1, 0));
    return 0;
}
