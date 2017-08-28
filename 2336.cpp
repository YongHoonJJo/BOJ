#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 500001

struct Student { int rank[4]; };

int seg[1<<20];
int sIdx=1<<19;

bool cmp(Student a, Student b)
{
	return a.rank[2] < b.rank[2];
}

void update(int i, int rank)
{
	i += sIdx;
	seg[i] = rank;
	while(i > 1) {
		i >>= 1;
		seg[i] = seg[i*2]<seg[i*2+1] ? seg[i*2] : seg[i*2+1];
	}
	
}

int Min(int L, int R, int node, int nodeL, int nodeR)
{
	int mid = (nodeL+nodeR)/2;
	if(R < nodeL || nodeR < L) return MAX;
	if(L <= nodeL && nodeR <= R) return seg[node];
	int a = Min(L, R, node*2, nodeL, mid);
	int b = Min(L, R, node*2+1, mid+1, nodeR);
	return a < b ? a : b;
}

int main()
{
	int n, id;
	scanf("%d", &n);

	// 굉장한 학생 : 자기보다 세번의 시험을 전부 다 잘본 학생이 한명도 없는 경우
	Student s[MAX];
	for(int i=1; i<=3; i++) {
		for(int j=1; j<=n; j++) {
			scanf("%d", &id);
			s[id].rank[i] = j; // id학생의 i번째 시험의 등수
		}
	}
	// 10
	// 2 5 3 8 10 7 1 6 9 4
	// 1 2 3 4 5 6 7 8 9 10
	// 3 8 7 10 5 4 1 2 6 9

	sort(s+1, s+n+1, cmp);
	
	for(int i=1; i<=n; i++)
		update(i, n+1);

	// 7 1 7
	// 1 2 8
	// 3 3 1
	// 10 4 6
	// 2 5 5
	// 8 6 9
	// 6 7 3
	// 4 8 2
	// 9 9 10
	// 5 10 4
	
	// set[sIdx+i] = 1번 시험을 i등한 학생의 3번 시험의 등수
	int ans = 0;
	for(int i=1; i<=n; i++) {
		int rank = Min(1, s[i].rank[1]-1, 1, 0, sIdx-1);
		if(rank > s[i].rank[3])
			ans++;
		update(s[i].rank[1], s[i].rank[3]);
	}
	printf("%d\n", ans);
	return 0;
}
