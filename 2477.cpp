#include <cstdio>
#include <vector>
using namespace std;

struct P { int dir, cir; };

int Max(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	int k, n=6;
	scanf("%d", &k);

	// East 1, West 2, South 3, North 4
	// CCW..

	vector<P> v;
	int W=0, H=0;
	while(n--) {
		int dir, cir;
		scanf("%d%d", &dir, &cir);
		v.push_back((P){dir, cir});
		if(dir < 3) W = Max(W, cir);
		else H = Max(H, cir);
	}
	v.push_back(v[0]);

	int ans = W*H;
	for(int i=0; i<6; i++) {
		if((v[i].dir == 2 && v[i+1].dir == 4) ||
			(v[i].dir == 4 && v[i+1].dir == 1) ||
	    	(v[i].dir == 1 && v[i+1].dir == 3) ||
	    	(v[i].dir == 3 && v[i+1].dir == 2)) {
			ans -= v[i].cir*v[i+1].cir;
		}
	}
	printf("%d\n", ans*k);	
	return 0;
}
