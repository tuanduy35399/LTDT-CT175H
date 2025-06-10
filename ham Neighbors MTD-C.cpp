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
    pG->m=m;
    for(int i=1; i<=pG->n; i++) {
        for(int j=1; j<=pG->m; j++) {
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

int main() {
    Graph G;
    int n, m; scanf("%d %d", &n, &m);
    init_graph(&G, n, m);
    for(int i=1; i<=m; i++) {
        int u,v;
        scanf("%d %d", &u, &v);
        add_edge(&G,i,u,v);
    }
    int u;
    scanf("%d", &u);
    List danhSach = neigbors(&G, u);
    for(int k=1; k<=count_list(&danhSach); k++) {
        printf("%d\n", element_at(&danhSach, k));
    }
    return 0;
}
