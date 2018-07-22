#include <stdio.h>

int arr[10001];

void post(int L, int R)
{
    if(L >= R) return ;
    int k = L+1;
    while(k < R && arr[k] < arr[L]) k++;
    post(L+1, k);
    post(k, R);
    printf("%d\n", arr[L]);
}

int main()
{
    int n;
    int idx=0;
    while(scanf("%d", &n) == 1) {
        arr[idx++] = n;
    }
    
    post(0, idx);
    return 0;
}
