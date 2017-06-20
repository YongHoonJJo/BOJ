#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

vector<int> g[26];
bool check[26]={0};
char w[100][11];
int ind[26];

int main()
{
	int n;
	scanf("%d", &n);

	for(int i=0; i<n; i++) {
		scanf("%s", w[i]);
		for(int j=0; w[i][j]; j++)
			check[w[i][j]-'a'] = 1;
	}

	for(int i=1; i<n; i++) {
		for(int j=0; w[i-1][j] && w[i][j]; j++) {
			int a = w[i-1][j]-'a';
			int b = w[i][j]-'a';
			if(a != b) {
				ind[b]++;
				g[a].push_back(b);
				break;
			}	
		}
	}

	int vn=0;
	queue<int> q;
	for(int i=0; i<26; i++) {
		if(check[i]) {
			vn++;
			if(!ind[i])
				q.push(i);
		}
	}

	bool multi = false;
	char ans[27]={0};
	for(int i=0; i<vn; i++) {
		if(q.empty()) {
			puts("!");
			return 0;
		}
		if(q.size() > 1) {
			multi = true;
			// break; 시 나중에 empty() 되는 것을 확인 못함.
		}

		int cur = q.front(); q.pop();
		ans[i] = cur+'a';		
		for(int next : g[cur]) {
			if(--ind[next] == 0)
				q.push(next);
		}

	}
	if(multi) puts("?");
	else puts(ans);
}
