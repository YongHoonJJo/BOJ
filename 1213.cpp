#include <stdio.h>

char s[51];
char a[26];
char ans[51];

int main()
{
    int odd=0;
    int oddIdx=0, idx=0;
    scanf("%s", s);

    for(int i=0; s[i]; i++)
        a[s[i]-'A']++;

    for(int i=0; i<26; i++) {
        if(a[i]&1) {
            odd++;
            oddIdx = i;
        }
    }

    if(odd > 1) {
        puts("I'm Sorry Hansoo");
        return 0;
    }
    
    for(int i=0; i<26; i++) {
        while(a[i] > 1) {
            printf("%c", 'A'+i);
            ans[idx++] = 'A'+i;
            a[i] -= 2;
        }
    }

    if(odd) printf("%c", 'A'+oddIdx);

    for(int i=idx-1; i>=0; i--)
        printf("%c", ans[i]);
    

    return 0;
}
