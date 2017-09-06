#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

#define INF 0x3f3f3f3f

int g[101][101], ticket[101][101];

int main()
{
	int n, r, m, k;
	char city[21];
	scanf("%d%d", &n, &r);

	for(int i=0; i<=100; i++) {
		for(int j=0; j<=100; j++)
			g[i][j] = ticket[i][j] = INF;
		g[i][i] = ticket[i][i] = 0;
	}
	
	map<string, int> cities;
	for(int i=1; i<=n; i++) {
		scanf("%s", city);
		cities[city] = i;
	}
	
	vector<string> path;
	scanf("%d", &m);
	for(int i=0; i<m; i++) {
		scanf("%s", city);
		path.push_back(city);
	}

	scanf("%d", &k);
	for(int i=0; i<k; i++) {
		int S, E, cost;
		char type[21], s[21], e[21];
		scanf("%s%s%s%d", type, s, e, &cost);
		
		S = cities[s]; E = cities[e];
		g[E][S] = g[S][E] = min(g[S][E], cost); 
		if(!strcmp(type, "Mugunghwa") || !strcmp(type, "ITX-Saemaeul") || !strcmp(type, "ITX-Cheongchun"))
			cost = 0;
		else if(!strcmp(type, "S-Train") || !strcmp(type, "V-Train")) cost /= 2;
		ticket[E][S] = ticket[S][E] = min(ticket[S][E], cost);
	}
	
	for(int z=1; z<=n; z++) {
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				g[i][j] = min(g[i][j], g[i][z]+g[z][j]);
				ticket[i][j] = min(ticket[i][j], ticket[i][z]+ticket[z][j]);
			}
		}
	}
	int price=0, tPrice=0;
	for(int i=0, E, S=cities[path[0]]; i<path.size()-1; i++) {
		E = cities[path[i+1]];
		price += g[S][E];
		tPrice += ticket[S][E];
		S = E;
	}
	price > tPrice+r ? puts("Yes") : puts("No");
}
