#include <stdio.h>

int parent[50], notLeaf[50];

int main()
{
	int i, n, rNode, ans=0;
	scanf("%d", &n);

	for(i=0; i<n; i++) {
		scanf("%d", parent+i); 
		if(parent[i] != -1) notLeaf[parent[i]]++;
		else notLeaf[i]++;
	}
	scanf("%d", &rNode);
	notLeaf[parent[rNode]]--;	

	for(i=0; i<n; i++) {
		if(!notLeaf[i]) {
			int k = i;
			while(k != rNode && k != -1)
				k = parent[k];
			if(k == -1)
				ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}
