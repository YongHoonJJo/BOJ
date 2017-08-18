#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <map>
using namespace std;

int main()
{
	int n, m, ans=0;
	char name[21];
	scanf("%d%d", &n, &m);

	map<string, int> mp;

	while(n--) {
		scanf("%s", name);	
		if(!mp[name]) mp[name]=1;
	}

	priority_queue<string, vector<string>, greater<string> > pq;

	while(m--) {
		scanf("%s", name);
		if(mp[name]) {
			ans++;
			pq.push(name);
		}
	}

	printf("%d\n", ans);
	while(!pq.empty()) {
		cout << pq.top() << '\n';
		pq.pop();
	}
}
