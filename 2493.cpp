#include <cstdio>
#include <stack>
using namespace std;

stack<int> S;
int ans[500001];

int main()
{
	int n, k;
	int tower[500001];
	scanf("%d", &n);

	for(int i=1; i<=n; i++) 
		scanf("%d", tower+i);

	for(int i=1; i<=n; i++) {
		while(!S.empty()) {
			int prev = S.top();
			if(tower[prev] > tower[i]) {
				ans[i] = prev;
				break;
			}
			S.pop();
		}
		if(S.empty()) ans[i] = 0;
		S.push(i);
	}

	for(int i=1; i<=n; i++)
		printf("%d ", ans[i]);
	puts("");
}
