#include <stdio.h>

typedef long long int lli;

main() {
	
	lli n;
	
	scanf("%lld", &n);
	
	if(!n) {
		printf("N");
		return 0;
	}
	
	while(n) {
		if(n&1) {
			n >>= 1;
		}
		else {
			printf("N");
			return 0;
		}
	}
	
	printf("S");
	
}
