#include <stdio.h>

char str[BUFSIZ];

int isP(int s, int e)
{
    if(s >= e) return 1;
    return str[s] == str[e] ? isP(s+1, e-1) : 0;
}

int main()
{
    int tc;
    scanf("%d", &tc);

    while(tc--) {
        int sz = 0 ;
        scanf(" %[^\n]\n", str);

        while(str[sz]) {
           if('A' <= str[sz] && str[sz] <= 'Z')
               str[sz] += ('a'-'A');
           sz++;
        }

        isP(0, sz-1) ? puts("Yes") : puts("No");
    }
    return 0;
}
