#include <stdio.h>

typedef long long int lli;

main() {
	
	char n;
	lli p = 0LL;
	lli i = 0LL;
	
	for(int k=0;; k++) {
		scanf("%c", &n);
		if(n != 10) {
			n -= 48;
			k%2 ? i+=n : p+=n;
		}
		else {
			break;
		}
	}
	
	printf(p%11==i%11 ? "S" : "N");
	
}
