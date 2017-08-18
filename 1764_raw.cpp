#include <cstdio>
#define MAX	10007

struct Data {
	char name[21];
	int len;

	Data() {}
	Data(char name[]) {
		len = 0;
		for(len=0; name[len]; len++)
			this->name[len] = name[len];
		this->name[len] = 0;
	}
};

Data hasArr[MAX][100];
bool keyArr[MAX];
int hashSize[MAX];

Data arr[500001];
int arrCnt;

int setKey(Data data)
{
	int key = 0;
	for(int i=0; i<data.len; i++) {
		key = (key * 11) % MAX;
		key = (key + data.name[i]) % MAX;
	}
	return key % MAX;
}

bool isSame(Data a, Data b)
{
	if(a.len != b.len) return 0;
	for(int i=0; i<a.len; i++)
		if(a.name[i] != b.name[i])
			return 0;
	return 1;
}

void find(int key, Data data)
{
	int size = hashSize[key];
	for(int i=0; i<size; i++)
		if(isSame(data, hasArr[key][i]))
			arr[arrCnt++] = data;
}

inline void swap(Data &a, Data &b) { Data t=a; a=b; b=t; }

inline bool cmp(Data a, Data b)
{
	for(int i=0; i<a.len; i++) 
		if(a.name[i] != b.name[i])
			return a.name[i] < b.name[i];
	return a.len < b.len;
}

void qsort(Data *arr, int s, int e)
{
	if(s <= e) {
		int S = s, E = e;
		Data pivot = arr[(S+E)/2];

		while(S <= E) {
			while(cmp(arr[S], pivot)) S++;
			while(cmp(pivot, arr[E])) E--;

			if(S <= E) {
				swap(arr[S], arr[E]);
				S++; E--;
			}
		}

		if(s < E) qsort(arr, s, E);
		if(S < e) qsort(arr, S, e);
	}
}

int main()
{
	int n, m;
	char name[21];
	scanf("%d%d", &n, &m);

	while(n--) {
		scanf("%s", name);

		Data tmp = Data(name);
		int key = setKey(tmp);

		keyArr[key] = 1;
		hasArr[key][hashSize[key]] = tmp;
		hashSize[key]++;
	}

	while(m--) {
		scanf("%s", name);

		Data tmp = Data(name);
		int key = setKey(tmp);

		if(keyArr[key])
			find(key, tmp);
	}

	qsort(arr, 0, arrCnt-1);

	printf("%d\n", arrCnt);
	for(int i=0; i<arrCnt; i++)
		printf("%s\n", arr[i].name);
}
