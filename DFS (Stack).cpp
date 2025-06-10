#include <stdio.h> 

#define MAX 50
typedef int ElementType;

typedef struct {
	int top; // chi so top thi luon là int
	ElementType data[MAX]; // kieu du lieu cua stack co the thay doi
}Stack;

//ham makeNUll
void makeNull(Stack* pS) {//khi rong thi mang ko co phan tu va top<0
	pS->top=-1;
}
int empty(Stack* pS) {
	return pS->top==-1;
}
int full(Stack* pS) {
	return pS->top==MAX-1; //Stack co 100 phan tu, khi full thi top chi toi 99 vi mang bdau tu 0
}

void pop(Stack* pS) { //lay phan tu o dau mang
	 pS->top--; //lay roi thi giam top xuong
}
void push(Stack* pS, ElementType x) {
	if(full(pS)) return;//kiem tra co day hay khong
	pS->top++;
	pS->data[pS->top]=x;
}
ElementType top(Stack* pS) {
		//ktra neu rong thi tra ve -1 (null)
	 if(empty(pS)) return -1;
	 int temp= pS->data[pS->top];
	 pop(pS);
	 return temp;
}
//Khai bao cau truc do thi MA TRAN DINH CUNG
typedef struct {
	int edges[MAX][MAX];
	int n,m;
}Graph;

void init_graph(Graph* pG, int n){
	pG->n=n;
	pG->m=0;
}
void add_edge(Graph* pG, int e, int u, int v) {
	pG->edges[u][e]=1;
	pG->edges[v][e]=1;
	pG->m++;
}
int adjacent(Graph* pG, int u, int v) {
	for(int e=1; e<=pG->m; e++) {
		if(pG->edges[u][e]==1 && pG->edges[v][e]==1) return 1;
	}
	return 0;
}
int mark[50];
void DFS(Graph* G, int s) {
	Stack S; makeNull(&S);
	push(&S, s);
	while(!empty(&S)) {
		int checkU= top(&S);
		if(mark[checkU]==1) continue;
		else {
			//danh dau U da duyet
			printf("%d\n", checkU);
			mark[checkU]=1;
			//kiem tra lan can cua no
			for(int v=1; v<=G->n; v++) {
				if(adjacent(G, checkU, v) && v!=checkU) {
					push(&S, v);
				} 
			}
		}
	}
}
	
int main() {
	Graph G;
	int n, m, u, v, w, e;
	scanf("%d%d", &n, &m);
	init_graph(&G, n);
	
	for (e = 0; e < m; e++) {
	    scanf("%d%d", &u, &v);
	    add_edge(&G,e, u, v);
	}
	DFS(&G, 1);
}

