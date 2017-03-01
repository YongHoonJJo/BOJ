#include <stdio.h>

int pre[1001], in[1001], inFrom[1001]; 
int rootIdx;

void post(int s, int e)
{
	int root;
	if(s > e) return ;

	root = pre[++rootIdx];
	post(s, inFrom[root]-1);
	post(inFrom[root]+1, e);
	printf("%d ", root);
}

int main()
{
	int tc;
	scanf("%d", &tc);

	while(tc--) {
		int i, n;
		scanf("%d", &n);
		for(i=1; i<=n; i++)
			scanf("%d", pre+i);
		for(i=1; i<=n; i++) {
			scanf("%d", in+i);
			inFrom[in[i]] = i;
		}
		rootIdx = 0;
		post(1, n);
		puts("");
	}

	return 0;
}
