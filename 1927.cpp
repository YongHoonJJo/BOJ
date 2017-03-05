#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	int i, n;
	scanf("%d", &n);

	priority_queue<int, vector<int>, greater<int> > pq;

	while(n--) {
		int k, ans;
		scanf("%d", &k);

		if(k)
			pq.push(k);
		else {
			if(pq.empty()) ans=0;
			else {
				ans = pq.top();
				pq.pop();
			}
			printf("%d\n", ans);
		}
	}
}


