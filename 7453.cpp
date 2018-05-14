#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 4001;

int A[MAX], B[MAX], C[MAX], D[MAX];

int main()
{
    int n;
    scanf("%d", &n);

    vector<int> X, Y;
    for(int i=0; i<n; i++)
        scanf("%d%d%d%d", A+i, B+i, C+i, D+i);

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            int x = A[i]+B[j];
            int y = C[i]+D[j];

            X.push_back(x);
            Y.push_back(y); 
        }
    }

    sort(Y.begin(), Y.end());

    long long ans = 0LL;
    
    vector<int>::iterator lo, up;
    for(int i=0; i<X.size(); i++) {
        if(binary_search(Y.begin(), Y.end(), -X[i])) {
	        lo = lower_bound(Y.begin(), Y.end(), -X[i]); 
	        up = upper_bound(Y.begin(), Y.end(), -X[i]);
            ans += (up-lo);
        }
    }
    printf("%lld\n", ans); 
    return 0;
}
