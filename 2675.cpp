#include <stdio.h>

int main()
{   
    int tc;
    scanf("%d", &tc);
    while(tc--) {
        int i, j, n;
        char s[21];
        scanf("%d%s", &n, s);
        
        for(i=0; s[i]; i++)
            for(j=0; j<n; j++)
                printf("%c", s[i]);
        puts("");
    }

    return 0;
}
