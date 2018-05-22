#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

const int MAX = 1010;
const int INF = 100000000;

int c[MAX];	//Moedas
int b[MAX][MAX];

int change(int v, int i) {
	//printf("v=%d, i=%d\n", v, i);
	if(!i || v<0) {
		//printf("return(%d, %d) INF\n", v, i);
		return INF;
	}
	if(!v) {
		//printf("return(%d, %d) 0\n", v, i);
		return 0;
	}
	if(b[v][i] == -1) {
		b[v][i] = min(change(v-c[i], i)+1, change(v, i-1));
	}
	return b[v][i];
}

main() {
	
	int n;	//Moedas
	int m;	//Valor
	
	scanf("%d %d", &n, &m);
	
	for(int k=1; k<=n; k++) {
		scanf("%d", &c[k]);
	}
	
	memset(b, -1, sizeof(b));
	
	printf(change(m, n)<10 ? "S\n" : "N\n");
	
}
