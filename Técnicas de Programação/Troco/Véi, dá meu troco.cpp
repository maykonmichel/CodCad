#include <stdio.h>
#include <string.h>

const int MAX = 1010;

int c[MAX];
int b[MAX][MAX];

bool solve(int v, int i) {
	//printf("v=%d i=%d\n", v, i);
	if(!i) {
		return false;
	}
	if(!v) {
		return true;
	}
	if(v < 0) {
		return false;
	}
	if(b[v][i] != -1) {
		return b[v][i];
	}
	return b[v][i] = solve(v, i-1)||solve(v-c[i], i);
}

main() {
	
	int n;	//Moedas
	int	m;	//Valor
	
	scanf("%d %d", &n, &m);
	
	for(int k=1; k<=n; k++) {
		scanf("%d", &c[k]);
	}
	
	memset(b, -1, sizeof(b));
	
	printf(solve(m, n) ? "S" : "N");
	
}
