#include <stdio.h> 
#define MAX 50
//Khai bao cau truc Stack
typedef struct {
	int data[MAX];
	int top;	
}Stack;

void makeNull(Stack* pS) {
	pS->top=-1;
}
void push(Stack* pS, int x) {
	pS->data[++pS->top]=x;
}
int top(Stack* pS) {
	return pS->data[pS->top];
}
void pop(Stack* pS) {
	pS->top--;
}
int empty(Stack* pS) {
	return pS->top==-1;	
}

typedef struct {
	int u, v;
}Edge;

typedef struct {
	int n,m;
	Edge edges[MAX];
}Graph;

void init_graph(Graph* pG, int n) {
	pG->n=n;
	pG->m=0;
}

void add_edge(Graph* pG, int u, int v) {
	pG->edges[pG->m].u=u;
	pG->edges[pG->m].v=v;
	pG->m++;
}

int adjacent(Graph* pG, int u, int v) { 
	for(int i=0; i<pG->m; i++) { //sai 1, loi duyet n thay vi m
		if(pG->edges[i].u==u && pG->edges[i].v==v) return 1;
	}
	return 0;
}
int min(int a, int b) {
	return (a>b)? b:a;
}	
int num[MAX],min_num[MAX], mark[MAX],k=1,l=0,on_stack[MAX], cnt=0, dinh=0, max=-9999;
void SCC(Graph* pG,Stack* pS, int u) {
	num[u]=k; min_num[u]=k; k++;
	
	push(pS, u); on_stack[u]=1;
	mark[u]=1;
	for(int v=1; v<=pG->n; v++) {
		if(adjacent(pG,u,v)) {
			if(mark[v]==0) {
				SCC(pG, pS,v);
				min_num[u]=min(min_num[u], min_num[v]);	
				dinh++;
			} else if (on_stack[v]==1) {
				min_num[u]=min(min_num[u], num[v]);
				dinh++;
			} else continue;
		}
	}
	
	if(num[u]==min_num[u]) {
		int i, dinh=0;
		do{
			i=top(pS); pop(pS);	
			on_stack[i]=0;
			dinh++;
		}while(i!=u);
		max =(max<dinh)? dinh:max;	
		cnt++;
	}
	
	
}


int main() {
	int n,m,u,v;
//	freopen("dt.txt", "r", stdin);
	scanf("%d %d", &n,&m);
	Graph G;
	init_graph(&G,n);
	Stack S;
	makeNull(&S);
	for(int i=1; i<=m; i++) {
		scanf("%d %d", &u, &v);
		add_edge(&G,u,v);
	}
	for(int i=1; i<=n; i++) {
		mark[i]=0;
		on_stack[i]=0;
	}
	for(int i=1; i<=n; i++) {
		if(mark[i]==0) SCC(&G,&S, i);
	}
	
	printf("CNT: %d \n", cnt);
	printf("So dinh cuoi cung: %d \n", dinh);
	printf("MAX dinh: %d ", max);
	return 0;
}



