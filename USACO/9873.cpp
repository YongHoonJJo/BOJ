#include <cstdio>
#include <algorithm>
using namespace std;

int pos[1001];

int main()
{
    int n;
    scanf("%d", &n);

    for(int i=0; i<n; i++) 
        scanf("%d", pos+i);

    sort(pos, pos+n);
    
    int ans=0;
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            int ji = pos[j]-pos[i];
            for(int k=j+1; k<n; k++) {
                int kj = pos[k]-pos[j];
                if(ji <= kj && kj <= 2*ji) ans++;
                if(kj > 2*ji) break;
            }
        }
    }
    printf("%d\n", ans); 
    return 0;
}
