#include <cstdio>
#include <vector>
#include <stack>
using namespace std;

typedef pair<char, int> P;

int a[31];
char str[31];
stack<P> S;

int go(int l, int r)
{
	int i, ans=0, ret = (str[l]=='('?2:3);
	if(l+1 != r) {
		int s=l+1, e=a[s];
		while(1) {
			ans += go(s, e);
			s = e+1;
			if(s == r) break;
			e = a[s];
		}
		ret *= ans;	
	}
	return ret;
}

int main()
{	
	int i, ans=0;
	scanf("%s", str);

	for(i=0; str[i]; i++) {
		a[i] = -1;
		if(str[i]=='(' || str[i]=='[')
			S.push(P(str[i], i));
		else {
			if(S.empty()) {
				puts("0");
				return 0;
			}
			char tmp = S.top().first;
			if((str[i]==')' && tmp!='(' ) || (str[i]==']' && tmp!='[')) {
				puts("0");
				return 0;
			}
			a[S.top().second] = i;
			S.pop();
		}
	}
	if(S.size() == 0) {
		int s, e=-1;
		do {
			s = e+1;
			e = a[s];
			ans += go(s, e);
		} while(e != i-1); 
	}
	printf("%d\n", ans);
}
