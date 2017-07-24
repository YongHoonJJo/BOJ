#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> In, p, lisI, lisV;

void trace(int i) 
{
	if(i != -1) {
		trace(p[i]);
		printf("%d ", In[i]); 
	}
}

int main() 
{
	int i, n, k;
	scanf("%d", &n);

	for(i=0; i<n; i++) {
		scanf("%d", &k);
		In.push_back(k);
	}

	lisI.push_back(0);
	lisV.push_back(In[0]);;
	p = vector<int>(n, -1);
	
	for(i=1; i<n; i++) {
		k = In[i];
		if(In[lisI.back()] < k) {
			p[i] = lisI.back();
			lisI.push_back(i);
			lisV.push_back(k);
		}
		else {
			int pos = lower_bound(lisV.begin(), lisV.end(), k)-lisV.begin();
			lisI[pos] = i;
			lisV[pos] = k;
			if(pos != 0) 
				p[i] = lisI[pos-1];
		}
	}
	
	printf("%d\n", lisI.size());
	trace(lisI.back());
	puts("");
}
