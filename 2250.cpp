#include <cstdio>
#include <vector>
using namespace std;

int g[10001][2], parent[10001];
vector<int> v[10001];
int col;

void inorder(int root, int level)
{
	if(root == -1) return ;
	inorder(g[root][0], level+1);
	v[level].push_back(++col);	
	inorder(g[root][1], level+1);
}

int main()
{
	int n;
	scanf("%d", &n);

	for(int i=1; i<=n; i++) {
		int p, l, r;
		scanf("%d %d %d", &p, &l, &r);
		g[p][0] = l;
		g[p][1] = r;
		parent[l] = parent[r] = p;
	}

	int root = 1;
	while(parent[root]) {
		root = parent[root];
	}

	inorder(root, 1);

	int ansL=1, ansH=v[1][v[1].size()-1]-v[1][0];
	for(int i=2; i<=n; i++) {
		if(v[i].size()) {
			int tmp = v[i][v[i].size()-1]-v[i][0];
			if(tmp > ansH) {
				ansH = tmp;
				ansL = i;
			}
		}
	}
	printf("%d %d\n", ansL, ansH+1);
}
