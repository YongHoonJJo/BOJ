#include <cstdio>
#include <map>
using namespace std;

int main()
{
	int tc = 0;
	while(1) {
		tc++;
		map<int, bool> node;
		int edge = 0;
		int nodeCnt = 0;
		while(1) {
			int u, v;
			scanf("%d%d", &u, &v);
			if(!u && !v) break;
			if(u == -1) return 0;
			if(!node[u]) { node[u] = 1; nodeCnt++; }
			if(!node[v]) { node[v] = 1; nodeCnt++; }
			edge++;
		}
		bool isTree = (nodeCnt == edge+1) || !nodeCnt; 
		printf("Case %d is %sa tree.\n", tc, isTree ? "" : "not ");
	}
}
