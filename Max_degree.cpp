#include <stdio.h>
#include <stdio.h>
typedef struct {
    int A[100][500];
    int n, m;
} Graph;
#define MAX_ELEMENTS 100
typedef int ElementType;
typedef struct {
    ElementType data[MAX_ELEMENTS];
    int size;
} List;

void make_null(List* L) {
    L->size = 0;
}

void push_back(List* L, ElementType x) {
    L->data[L->size] = x;
    L->size++;
}

ElementType element_at(List* L, int i) {
    return L->data[i-1];
}

int count_list(List* L) {
    return L->size;
}
void add_edge(Graph* pG, int e, int x, int y) {
    pG->A[x][e]=1;
    pG->A[y][e]=1;
    pG->m++;
}
void init_graph(Graph* pG, int n, int m) {
    pG->n=n;
    pG->m=0;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            pG->A[i][j]= 0;
        }
    }
}
List neigbors(Graph* pG, int u) {
    List L;
    make_null(&L);
    for(int cung=1; cung<=pG->m; cung++) {
        if (pG->A[u][cung]==1) {
        for(int dinh=1; dinh<=pG->n; dinh++) {
            if(dinh!=u && (pG->A[dinh][cung]==1) ) {
                int already_in = 0;
                for (int i = 1; i <= count_list(&L); i++) {
                        if (element_at(&L, i) == dinh) {
                            already_in = 1;
                            break;
                        }
                    }
                if (!already_in) push_back(&L, dinh);
            }
        }
    }
    }
    return L;
}

List degreeList(Graph* pG) {
    List L;
    make_null(&L); // nho khoi tao size=0 cho List, cho nay hay sai
    int count=0;
    for(int dinh=1; dinh<=pG->n; dinh++) {
    	for(int i=1; i<=pG-> m;i++) {
        	count+=pG->A[dinh][i];
    	}
    	    push_back(&L, count);//Luc nay vi tri thu i trong List se chua bac cua dinh thu i+1
    	    count=0;// dat lai bien count de dem bac cua dinh khac
    }
    return L;
}

void MaxDegree(List* pL) {
    int max=0, index=0;
    for(int i=0; i<pL->size; i++) {
        if(max<pL->data[i]) {
            max=pL->data[i];
            index=i+1; //nhu da noi o tren, dinh thu i se la i +1 trong List vi List bat dau tu so 0
        }
    }
    printf("%d %d", index, max);
}
int main() {
	Graph G;
    int n, m, u, v, e;
    scanf("%d%d", &n, &m);
    init_graph(&G, n, m);

    for (e = 1; e <= m; e++) {
        scanf("%d%d", &u, &v);
        add_edge(&G, e, u, v);
    }
    List DS = degreeList(&G);
    MaxDegree(&DS);
	return 0;
}

