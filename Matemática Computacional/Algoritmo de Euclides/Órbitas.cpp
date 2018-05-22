#include <stdio.h>

typedef long long int lli;

lli mdc(lli a, lli b) {
	if(!b) {
		return a;
	}
	return mdc(b, a%b);
}

main() {
	
	lli a;
	lli b;
	
	scanf("%lld %lld", &a, &b);
	
	printf("%lld", (a*b)/mdc(a, b));
	
}
