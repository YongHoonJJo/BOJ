#include <cstdio>
#include <vector>
using namespace std;

int n, k;
int s[101], cs[101];
vector<int> si[5], csi[5];

bool isOk(vector<int> &seq)
{
	int i, k, dir=seq[0];
	
	for(k=0; k<si[dir].size(); k++) {
		bool ok=1;
		int sIdx = si[dir][k];
		for(i=0; i<n; i++) {
			if(s[sIdx+i] != seq[i]) {
				ok = 0;		
				break;
			}
		}
		if(ok) return 1;		
	}

	for(k=0; k<csi[dir].size(); k++) {
		bool ok=1;
		int sIdx = csi[dir][k];
		for(i=0; i<n; i++) {
			if(cs[sIdx+i] != seq[i]) {
				ok = 0;		
				break;
			}
		}
		if(ok) return 1;		
	}
	return 0;
}

int main()
{
	int i, j;
	scanf("%d", &n);

	// 1 : Right, 2 : Up, 3 : Left, 4 : Down
	for(i=0; i<n; i++) {
		scanf("%d", s+i);
		cs[n-1-i]= s[i]<3 ? s[i]+2 : s[i]-2;
		si[s[i]].push_back(i);
		csi[cs[n-1-i]].push_back(n-1-i);
	}

	for(i=0; i<n; i++) {
		s[n+i] = s[i];
		cs[n+i] = cs[i];
	}
	
	scanf("%d", &k);
	vector<vector<int> > ans;
	while(k--) {
		vector<int> seq(n);
		for(i=0; i<n; i++)
			scanf("%d", &seq[i]);
		
		if(isOk(seq))		
			ans.push_back(seq);
	}

	int sz = ans.size();
	printf("%d\n", sz);
	for(i=0; i<sz; i++) {
		for(j=0; j<n; j++)
			printf("%d ", ans[i][j]);
		puts("");
	}
}
