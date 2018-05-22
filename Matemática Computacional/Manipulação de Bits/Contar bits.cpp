#include <stdio.h>

typedef long long int lli;

main() {
	
	lli n;
	
	scanf("%lld", &n);
	
	lli k = 0;
	
	while(n) {
		k++;
		n -= n&-n;
	}
	
	printf("%lld", k);
	
}
