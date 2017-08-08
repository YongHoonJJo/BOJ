#include <cstdio>
#include <stack>
using namespace std;

char brk[100001];
stack<int> S;

int main()
{
	int i, ans=0;
	scanf("%s", brk);

	for(i=0; brk[i]; i++) {			
		if(brk[i] == '(')
			S.push(i);
		else {
			int idx = S.top(); S.pop();
			if(i-1 == idx) ans += S.size();
			else ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}
