#include <stdio.h>

int N, L, ans=0;
int g[101][101];

int down(int r, int c)
{
    int curH;
    if(r == N-1) return 1;

    curH = g[r][c];
    if(r+L < N && curH-g[r+L][c] == 1) {
        int flag = 1;
        for(int i=1; i<L; i++) {
            if(g[r+L][c] != g[r+i][c])
                flag = 0;
        }
        if(flag){
            if(r+L == N-1) return 1;
            if(g[r+L][c] == g[r+L+1][c])
                return down(r+L+1, c);
            if(g[r+L][c] == g[r+L+1][c]+1)
                return down(r+L, c);
        }
    }
    if(r+L < N && g[r+L][c]-curH == 1) {
        int flag = 1;
        for(int i=1; i<L; i++) {
            if(curH != g[r+i][c])
                flag = 0;
        }
        if(flag) return down(r+L, c);
    }
    if(g[r+1][c] == curH) return down(r+1, c);
    return 0;
}

int right(int r, int c)
{
    int curH;
    if(c == N-1) return 1;

    curH = g[r][c];
    if(c+L < N && g[r][c+L]-curH == 1) {
        int flag = 1;
        for(int i=1; i<L; i++) {
            if(curH != g[r][c+i])
                flag = 0;
        }
        if(flag) return right(r, c+L);
    }
    if(c+L < N && curH-g[r][c+L] == 1) {
        int flag = 1;
        for(int i=1; i<L; i++) {
            if(g[r][c+L] != g[r][c+i])
                flag = 0;
        }
        if(flag) {
            if(c+L == N-1) return 1;
            if(g[r][c+L] == g[r][c+L+1])
                return right(r, c+L+1);
            if(g[r][c+L] == g[r][c+L+1]+1)
                return right(r, c+L);
        }
    }
    if(g[r][c+1] == curH) return right(r, c+1);
    return 0;
}

int main()
{
    scanf("%d%d", &N, &L);

    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            scanf("%d", &g[i][j]);

    for(int i=0; i<N; i++) {
        if(down(0, i)) ans++;
        if(right(i, 0)) ans++;
    }
    printf("%d\n", ans);
    return 0;
}
