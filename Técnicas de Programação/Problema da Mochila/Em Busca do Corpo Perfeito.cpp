#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

const int MAX = 2010;

int n;				//Pedaços
int c[MAX];			//Peso
int v[MAX];			//Valor proteico
int b[MAX][MAX];	//Backup

int dp(int p, int i=0) {
	//printf("p=%d, i=%d\n", p, i);
	if(p < 0) {
		//printf("return 0\n");
		return -v[i-1];
	}
	if(b[p][i] != -1) {
		//printf("return(%d, %d) %d\n", p, i, b[p][i]);
		return b[p][i];
	}
	if(i == n-1) {
		if(p-c[i] >= 0) {
			return v[i];
		}
		else {
			return 0;
		}
	}
	return b[p][i] = max(v[i]+dp(p-c[i], i+1), dp(p, i+1));
}

main() {
	
	int p;	//Peso máximo
	
	scanf("%d %d", &p, &n);
	
	for(int k=0; k<n; k++) {
		scanf("%d %d", &c[k], &v[k]);
	}
	
	memset(b, -1, sizeof(b));
	
	printf("%d", dp(p));
	
}
