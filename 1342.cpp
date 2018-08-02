#include <stdio.h>
#include <string.h>

int n, ans;
int check[26];
int count[11];

void solve(int idx, int len, int p) // p : prev
{
    if(idx == len) {
        ans++;
        return ;
    }

    for(int i=0; i<n; i++) {
        if(count[i] > 0 && i!=p) {
            count[i]--;
            solve(idx+1, len, i);
            count[i]++;
        }
    }
}

int main()
{
    char s[20];
    int len;
    scanf("%s", s);

    len = strlen(s);

    for(int i=0; i<len; i++) {
        if(!check[s[i]-'a']) {
            count[n]++;
            check[s[i]-'a'] = ++n;
        }
        else
            count[check[s[i]-'a']-1]++;

    }

    solve(0, len, -1); 
    printf("%d\n", ans);
    return 0;
}
