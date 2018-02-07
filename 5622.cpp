#include <stdio.h>

int main()
{
    int i, ans=0;
    int dial[]={2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 9, 9, 9, 9};
    char str[20];
    scanf("%s", str);

    for(i=0; str[i]; i++) 
         ans += (dial[str[i]-'A']+1);

    printf("%d\n", ans);
    return 0;
}
