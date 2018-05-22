#include <stdio.h>

const int MAX = 10000010;

bool mrk[MAX];

main() {
	
	int n;
	
	scanf("%d", &n);
	
	for(int k=2; k<=n; k++) {
		if(!mrk[k]) {
			printf("%d ", k);
			for(int i=k; i<=n; i+=k) {
				mrk[i] = true;
			}
		}
	}
	
}
