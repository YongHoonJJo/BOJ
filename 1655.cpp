#include <cstdio>
#include <queue>
using namespace std;

int main()
{
    int n, k;
    scanf("%d", &n);

    priority_queue<int> minQ, maxQ;
    scanf("%d", &k);
    printf("%d\n", k);
    maxQ.push(k);

    for(int i=1; i<n; i++) {
        scanf("%d", &k);
        if(i&1) {
            if(maxQ.top() < k) minQ.push(-k);
            else {
                maxQ.push(k); minQ.push(-maxQ.top()); maxQ.pop();
            }
        }
        else {
            if(-minQ.top() > k) maxQ.push(k);
            else {
                minQ.push(-k); maxQ.push(-minQ.top()); minQ.pop();
            }
        }
        printf("%d\n", maxQ.top());
    }
    return 0; 
}

