#include <stdio.h>

typedef long int li;

li mdc(li a, li b) {
	if(!b) {
		return a;
	}
	return mdc(b, a%b);
}

main() {
	
	li a;
	li b;
	li c;
	li d;
	li ac;
	li bd;
	
	scanf("%ld %ld %ld %ld", &a, &b, &c, &d);
	
	bd = (b*d)/mdc(b, d);
	a *= bd/b;
	c *= bd/d;
	ac = a + c;
	a = mdc(ac, bd);
	ac /= a;
	bd /= a;
	
	printf("%ld %ld", ac, bd);
	
}
