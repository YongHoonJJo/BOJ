#include <cstdio>

int n, X[20], Y[20];
int next[20];
int pair[20];

int isCycle()
{
    for(int s=1; s<=n; s++) {
        int nWH = pair[s];
        for(int k=0; k<n; k++) {
            nWH = pair[next[nWH]];
        }
        if(nWH != 0) return 1;
    }
    return 0;
}

int solve()
{
    int ret=0;
    int k, paired = 1;
    for(k=1; k<=n; k++) {
        if(pair[k] == 0) {
            paired = 0;
            break;
        }
    }

    if(paired) {
        return isCycle();
    }

    for(int i=1; i<=n; i++) {
       if(k != i && pair[i] == 0) {
           pair[k] = i;
           pair[i] = k;
           ret += solve();
           pair[k] = pair[i] = 0;
       }
    }

    return ret; 
}   

int main()
{
    scanf("%d", &n);

    for(int i=1; i<=n; i++)
        scanf("%d%d", X+i, Y+i);

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(Y[i] == Y[j] && X[i] < X[j]) {
                if(next[i] == 0 || X[j] < X[next[i]])
                    next[i] = j;
            }
        }
    }

    printf("%d\n", solve());    

    return 0;
}

