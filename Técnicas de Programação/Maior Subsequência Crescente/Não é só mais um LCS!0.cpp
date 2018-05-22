#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

const int MAX = 1000010;
//const int MAX = 1010;

int s1[MAX];
int s2[MAX];
int b[MAX];

int lcs(int i1, int i2) {
	printf("%d, %d\n", i1, i2);
	if(b[i1] != -1) {
		return b[i1];
	}
	if(!i1 || !i2) {
		return 0;
	}
	if(s1[i1] == s2[i2]) {
		return 1+lcs(i1-1, i2-1);
	}
	return b[i1]=max(lcs(i1, i2-1), lcs(i1-1, i2));
}

main() {
	
	int n;	//Tamanho s1
	int m;	//Tamanho s2
	
	scanf("%d %d", &n, &m);
	
	for(int k=0; k<n; k++) {
		scanf("%d", &s1[k]);
	}
	
	for(int k=0; k<m; k++) {
		scanf("%d", &s2[k]);
	}
	
	memset(b, -1, sizeof(b));
	
	printf("%d", lcs(n, m));
	
}
