#include <stdio.h>

const int MAX = 100010;

int n;				//Caixas
int c[MAX];			//Moedas[caixa]
int tree[4*MAX];	//Segment tree
int lazy[4*MAX];	//Lazy propagation

void showTree() {
	printf("\n\n");
	for(int k=1; k<=9; k++) {
		printf("%d = %d(%d)\n", k, tree[k], lazy[k]);
	}
	printf("\n\n");
}

void refresh(	int i,	//Index
				int l,	//Left index range
				int r	//Right index range
				) {
	//printf("lazy(%d, %d, %d)\n", i, l, r);
	if(!lazy[i]) {
		//printf("\t!lazy[%d]\n", i);
		return;
	}
	tree[i] = lazy[i]*(r-l+1);
	if(l != r) {
		int ls = 2*i;	//Left son
		int rs = 2*i+1;	//Right son
		lazy[ls] = lazy[i];
		lazy[rs] = lazy[i];
	}
	lazy[i] = 0;
	//showTree();
}

void build(	int i,	//Index
			int l,	//Left index range
			int r	//Right index range
			) {
	if(l == r) {
		tree[i] = c[l];
	}
	else {
		int ls = 2*i;		//Left son
		int m = (l+r)/2;	//Middle
		int rs = 2*i+1;		//Right son
		build(ls, l, m);
		build(rs, m+1, r);
		tree[i] = tree[ls]+tree[rs];
	}
}

void build() {
	build(1, 1, n);
	//showTree();
}

int query(	int i,	//Index
			int l,	//Left index range
			int r,	//Right index range
			int ql,	//Left query index range
			int qr	//Right query index range
			) {
	//printf("query(%d, %d, %d, %d, %d)\n", i, l, r, ql, qr);
	refresh(i, l, r);
	if(l>r || l>qr || ql>r) {
		//printf("return 0\n");
		return 0;
	}
	if(ql<=l && r<=qr) {
		//printf("%d<=%d && %d<=%d\n\t", ql, l, r, qr);
		//printf("return tree[%d]=%d\n", i, tree[i]);
		return tree[i];
	}
	int ls = 2*i;		//Left son
	int m = (l+r)/2;	//Middle
	int rs = 2*i+1;		//Right son
	//printf("return query(%d, %d, %d, %d, %d)+query(%d, %d, %d, %d)\n", ls, l, m, ql, qr, rs, m+1, r, ql, qr);
	return query(ls, l, m, ql, qr)+query(rs, m+1, r, ql, qr);
}

int query(int l, int r) {
	return query(1, 1, n, l, r);
}

void update(int i,	//Index
			int l, 	//Left index range
			int r,	//Right index range
			int lu,	//Left update index range
			int ru,	//Right update index range
			int v	//Value to update
			) {
	int ls = 2*i;		//Left son
	int m = (l+r)/2;	//Middle
	int rs = 2*i+1;		//Right son
	refresh(i, l, r);
	if(ru<l || lu>r) {
		return;
	}
	if(lu<=l && ru>=r) {
		tree[i] = v*(r-l+1) ;
		if(l != r) {
			lazy[ls] = v;
			lazy[rs] = v;
		}
	}
	else {
		update(ls, l, m, lu, ru, v);
		update(rs, m+1, r, lu, ru, v);
		tree[i] = tree[ls]+tree[rs];
	}
}

void update(int l, int r, int v) {
	update(1, 1, n, l, r, v);
	//showTree();
}

main() {
	
	int q;	//Operações
	int o;	//Operação
	int a;
	int b;
	int v;	//Valor
	
	scanf("%d %d", &n, &q);
	
	for(int k=1; k<=n; k++) {
		scanf("%d", &c[k]);
	}
	
	build();
	
	for(int k=0; k<q; k++) {
		scanf("%d %d %d", &o, &a, &b);
		if(o == 1) {
			scanf("%d", &v);
			update(a, b, v);
		}
		else {
			printf("%d\n", query(a, b));
		}
	}
	
}
