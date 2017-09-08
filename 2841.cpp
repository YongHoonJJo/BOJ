#include <cstdio>
#include <stack>
using namespace std;

long long ans;

int main()
{
	int i, N, P;
	scanf("%d %d", &N, &P);

	stack<int> s[7];
	for(i=0; i<N; i++) {
		int n, p;
		scanf("%d %d", &n, &p);

		if(s[n].empty()) s[n].push(p);
		else {
			if(s[n].top() < p) s[n].push(p);
			else if(s[n].top() == p) ans--;
			else {
				while(!s[n].empty() && s[n].top() > p) {
					ans++;
					s[n].pop();
				}
				if(s[n].empty() || s[n].top() < p) s[n].push(p);
				else ans--;
			}
		}
		ans++;
	}
	printf("%lld\n", ans);
}


