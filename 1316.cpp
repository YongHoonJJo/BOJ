#include <stdio.h>

int ans;

int main()
{
    int n;
    scanf("%d", &n);

    while(n--) {
        int i;
        char str[101];
        int check[26]={0};
        scanf("%s", str);

        check[str[0]-'a']++;
        for(i=1; str[i]; i++) {
            if(str[i-1] != str[i]) {
                if(check[str[i]-'a']) {
                    ans--;
                    break;
                }
                check[str[i]-'a']++;
            }           
        }
        ans++;
    }
    printf("%d\n", ans);
    return 0;
}
