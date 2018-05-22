#include <stdio.h>

main() {
	
	long long int n;
	
	scanf("%lld", &n);
	
	if(n == 1LL) {
		printf("N");
		return 0;
	}
	
	for(long int k=2LL; k*k<=n; k++) {
		if(!(n%k)) {
			printf("N");
			return 0;
		}
	}
	printf("S");
	
}
