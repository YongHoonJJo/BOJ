#include <cstdio>
#include <vector>

using namespace std;

int ans;
int n, m;
int set[5];
vector<int> s[201];

bool isOk()
{
    for(int i=0; i<s[set[0]].size(); i++) {
        int no = s[set[0]][i];
        if(no == set[1] || no == set[2]) return 0;
    }

    for(int i=0; i<s[set[1]].size(); i++) {
        int no = s[set[1]][i];
        if(no == set[0] || no == set[2]) return 0;
    }

    return 1;
}

void go(int num, int idx)
{
    if(idx == 3) {
       if(isOk()) ans++;
       return ;
    }
    if(num > n) return ;

    set[idx] = num;
    go(num+1, idx+1);
    go(num+1, idx);
}

int main()
{
    scanf("%d%d", &n, &m);

    while(m--) {
        int a, b;
        scanf("%d%d", &a, &b);
        if(a > b) { int t=a; a=b; b=t; }
        s[a].push_back(b);
    }
    
    go(1, 0);
    printf("%d\n", ans);

    return 0;
}
