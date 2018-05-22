#include <stdio.h>

main() {
	
	char n;
	int s = 0;
	bool flag[3];
		
	while(true) {
		scanf("%c", &n);
		if(n != 10) {
			n -= 48;
			s += n;
			flag[0] = n%2 ? false : true;
			flag[1] = s%3 ? false : true;
			flag[2] = n%5 ? false : true;
		}
		else {
			break;
		}
	}
	
	int d[3] = {2, 3, 5};
	
	for(int k=0; k<3; k++) {
		printf(flag[k] ? "S\n" : "N\n");
	}
	
}
