#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;

struct P { int i; char ch; };

int d[1001][1001];
char s[1001], t[1001], tr[1001];
stack<P> S;

int go(int n, int m)
{
	int ret;
	if(n < 0 || m < 0) return 0;
	if(d[n][m] != -1) return d[n][m];

	if(s[n] == t[m]) {
		ret = go(n-1, m-1)+1;
		S.push((P){ret, s[n]});
	}
	else {
		int a = go(n, m-1);
		int b = go(n-1, m);
		ret = a > b ? a : b;
	}
	return d[n][m] = ret;
}

int main()
{
	int i, j;
	int n, m, ret;
	scanf("%s%s", s, t);

	n = strlen(s);
	m = strlen(t);

	memset(d, -1, sizeof(d));

	ret = go(n-1, m-1);
	printf("%d\n", ret);	

	while(!S.empty()) {
		P a = S.top(); S.pop();
		if(ret == a.i) {
			tr[ret-1] = a.ch;
			ret--;
		}
	}
	printf("%s\n", tr);
	return 0;
}
