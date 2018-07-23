#include <stdio.h>

char space[101][101];

int main()
{
    int ans=0;
    int r, c, k;
    scanf("%d%d%d", &r, &c, &k);

    for(int i=0; i<r; i++)
        scanf("%s", space[i]);

    for(int i=0; i<r; i++) {
        int j=0, tmp=0;
        while(j < c) {
            if(space[i][j] == '.') tmp++;
            else { 
                if(tmp-k+1 > 0) ans += (tmp-k+1);
                tmp = 0;
            }
            j++;
        }
        if(tmp-k+1 > 0) ans += (tmp-k+1);
    }

    for(int j=0; j<c; j++) {
        int i=0, tmp=0;
        while(i < r) {
            if(space[i][j] == '.') tmp++;
            else { 
                if(tmp-k+1 > 0) ans += (tmp-k+1);
                tmp = 0;
            }
            i++;
        }
        if(tmp-k+1 > 0) ans += (tmp-k+1);
    }
    printf("%d\n", ans);
    return 0;
}
