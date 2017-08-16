#include <cstdio>
#include <queue>
using namespace std;

struct P { int i, j; };
struct PP { P R, B; };

int n, m;
char g[20][20];
bool visited[20][20][20][20];

int main()
{
	scanf("%d%d", &n, &m);

	for(int i=0; i<n; i++)
		scanf("%s", g[i]);

	P R, B;
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(g[i][j] == 'R') {
				R = (P){i, j}; 
			}
			else if(g[i][j] == 'B') {
				B = (P){i, j}; 
			}
		}
	}

	int ans=0, ok=0, no=1;
	queue<PP> q;
	q.push((PP){R, B});
	visited[R.i][R.j][B.i][B.j] = 1;

	while(!q.empty()) {
		int sz = q.size();
		ans++;
		if(ans > 10) { ok=0; break; }
		for(int k=0; k<sz; k++) {
			P curR = q.front().R;
			P curB = q.front().B;
			q.pop();
			
			// Left
			ok = 2; R = curR; B = curB; 
			if(R.j < B.j) {
				while(g[R.i][R.j-1] != '#') {
					R.j--;
					if(g[R.i][R.j] == 'O') {
						ok = 1; break;
					}
				}
				while(g[B.i][B.j-1] != '#') {
					B.j--;
					if(g[B.i][B.j] == 'O') {
						ok = 0; break;
					}
					if(R.i == B.i && R.j == B.j) {
						B.j++; break;
					}
				}
			}
			else { // R.j > B.j
				while(g[B.i][B.j-1] != '#') {
					B.j--;
					if(g[B.i][B.j] == 'O') {
						ok = 0;  break;
					}
				}
				if(ok) {
					while(g[R.i][R.j-1] != '#') {
						R.j--;
						if(g[R.i][R.j] == 'O') {
							ok = 1; break;
						}
						if(R.i == B.i && R.j == B.j) {
							R.j++; break;
						}
					}
				}
			}
			if(ok == 1) break;
			if(ok)  { 
				if(!visited[R.i][R.j][B.i][B.j]) {
					q.push((PP){R, B});
					visited[R.i][R.j][B.i][B.j] = 1;
				}
			}

			// Right
			ok = 2; R = curR; B = curB; 
			if(R.j > B.j) {
				while(g[R.i][R.j+1] != '#') {
					R.j++;
					if(g[R.i][R.j] == 'O') {
						ok = 1; break;
					}
				}
				while(g[B.i][B.j+1] != '#') {
					B.j++;
					if(g[B.i][B.j] == 'O') {
						ok = 0; break;
					}
					if(R.i == B.i && R.j == B.j) {
						B.j--; break;
					}
				}
			}
			else { // R.j < B.j
				while(g[B.i][B.j+1] != '#') {
					B.j++;
					if(g[B.i][B.j] == 'O') {
						ok = 0; break;
					}
				}
				if(ok) {
					while(g[R.i][R.j+1] != '#') {
						R.j++;
						if(g[R.i][R.j] == 'O') {
							ok = 1; break;
						}
						if(R.i == B.i && R.j == B.j) {
							R.j--; break;
						}
					}
				}
			}
			if(ok == 1) break;
			if(ok)  { 
				if(!visited[R.i][R.j][B.i][B.j]) {
					q.push((PP){R, B});
					visited[R.i][R.j][B.i][B.j] = 1;
				}
			}

			// Down
			ok = 2; R = curR; B = curB; 
			if(R.i > B.i) {
				while(g[R.i+1][R.j] != '#') {
					R.i++;
					if(g[R.i][R.j] == 'O') {
						ok = 1; break;
					}
				}
				while(g[B.i+1][B.j] != '#') {
					B.i++;	
					if(g[B.i][B.j] == 'O') {
						ok = 0; break;
					}
					if(B.i == R.i && B.j == R.j) {
						B.i--; break;
					}
				}
			}
			else { // R.i < B.i
				while(g[B.i+1][B.j] != '#') {
					B.i++;
					if(g[B.i][B.j] == 'O') {
						ok = 0; break;
					}
				}
				if(ok) {
					while(g[R.i+1][R.j] !='#') {
						R.i++;
						if(g[R.i][R.j] == 'O') {
							ok = 1; break;
						}
						if(R.i == B.i && R.j == B.j) {
							R.i--; break;
						}
					}
				}
			}
			if(ok == 1) break;
			if(ok)  { 
				if(!visited[R.i][R.j][B.i][B.j]) {
					q.push((PP){R, B});
					visited[R.i][R.j][B.i][B.j] = 1;
				}
			}

			// Up
			ok = 2; R = curR; B = curB; 
			if(R.i < B.i) {
				while(g[R.i-1][R.j] != '#') {
					R.i--;
					if(g[R.i][R.j] == 'O') {
						ok = 1; break;
					}
				}
				while(g[B.i-1][B.j] != '#') {
					B.i--;
					if(g[B.i][B.j] == 'O') {
						ok = 0; break;
					}
					if(B.i == R.i && B.j == R.j) {
						B.i++; break;
					}
				}
			}
			else { // R.i > B.i
				while(g[B.i-1][B.j] != '#') {
					B.i--;
					if(g[B.i][B.j] == 'O') {
						ok = 0; break;
					}
				}
				if(ok) {
					while(g[R.i-1][R.j] != '#') {
						R.i--;
						if(g[R.i][R.j] == 'O') {
							ok = 1; break;
						}
						if(R.i == B.i && R.j == B.j) {
							R.i++; break;
						}
					}
				}
			}
			if(ok == 1) break;
			if(ok)  { 
				if(!visited[R.i][R.j][B.i][B.j]) {
					q.push((PP){R, B});
					visited[R.i][R.j][B.i][B.j] = 1;
				}
			}
		}
		if(ok == 1) break;
	}

	if(ok != 1) ans = -1;
	printf("%d\n", ans);

}
