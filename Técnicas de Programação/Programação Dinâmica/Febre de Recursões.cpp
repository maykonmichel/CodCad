#include <stdio.h>
#include <string.h>

const int MAX = 99999999;

int n;
int m;
int a[MAX];
long int f[MAX];

long int fk(int k) {
	if(f[k] == -1L) {
		f[k] = 0L;
		for(int i=1; i<=n; i++) {
			f[k] += a[i]*fk(k-i);
		}
		f[k] %= m;
	}
	return f[k];
}

main() {
	
	int k;
	
	scanf("%d %d %d", &n, &k, &m);
	
	for(int i=1; i<=n; i++) {
		scanf("%d", &a[i]);
	}
	
	memset(f, -1L, sizeof(f));
	
	for(int i=1; i<=n; i++) {
		scanf("%ld", &f[i]);
	}
	
	printf("%ld", fk(k));
	
}
