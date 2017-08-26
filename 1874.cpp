#include <cstdio>
#include <vector>
#include <stack>
using namespace std;

int a[100001];

stack<int> s;
vector<char> ans;

int main()
{
	int i, n, idx=0;
	scanf("%d", &n);
	
	for(i=0; i<n; i++)
		scanf("%d", a+i);

	for(i=1; i<=n; i++) {
		s.push(i);
		ans.push_back('+');
		while(s.top() == a[idx]) {
			s.pop();
			ans.push_back('-');
			idx++;
			if(idx == n || s.size() == 0) break;
		}
	}
	
	if(s.size()) puts("NO");
	else {
		for(i=0; i<ans.size(); i++)
			printf("%c\n", ans[i]);
	}
}
