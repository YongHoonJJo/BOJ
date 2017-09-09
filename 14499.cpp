#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

struct P { int r, c; };

int n, m;
int dice[7], g[21][21];
int dr[]={0, 0, 0, -1, 1};
int dc[]={0, 1, -1, 0, 0};

// index of dir
int UP    = 6;
int DOWN  = 1;
int EAST  = 3;
int WEST  = 4;
int SOUTH = 5;
int NORTH = 2;

bool safe(int r, int c)
{
	return (0 <= r && r < n) && (0 <= c && c < m);
}

void diceRotate(int cmd)
{
	int tUp=UP, tDown=DOWN;
	int tEast=EAST, tWest=WEST;
	int tSouth=SOUTH, tNorth=NORTH;	
	switch(cmd)
	{
		case 1: // East
			EAST = tDown; WEST = tUp; 
			UP = tEast; DOWN = tWest; return;				
		case 2: // West
			WEST = tDown; EAST = tUp;
			DOWN = tEast; UP = tWest; return ;
		case 3: // North
			SOUTH = tDown; NORTH = tUp;
			UP = tSouth; DOWN = tNorth; return ;
		case 4: // South
			NORTH = tDown; SOUTH = tUp;
			DOWN = tSouth; UP = tNorth;
	}
}

int main()
{
	int x, y, k;
	scanf("%d%d%d%d%d", &n, &m, &x, &y, &k);

	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			scanf("%d", &g[i][j]);

	// 1:East, 2:West, 3:North, 4:South
	queue<P> q;
	q.push((P){x, y});
	for(int i=0; i<k; i++) {
		int cmd;
		scanf("%d", &cmd);
		
		int nR = (q.front().r) + dr[cmd];
		int nC = (q.front().c) + dc[cmd];
		if(safe(nR, nC)) {
			q.pop(); q.push((P){nR, nC});
			diceRotate(cmd);
			printf("%d\n", dice[UP]);
			if(!g[nR][nC]) g[nR][nC] = dice[DOWN];
			else { dice[DOWN] = g[nR][nC]; g[nR][nC] = 0; }
		}
	}
}
