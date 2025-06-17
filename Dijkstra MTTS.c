#include <stdio.h>
#define oo 999999
#define NO_EDGE -1 //nen gan -1 vi trong so co the bang 0
#define MAX 50

typedef struct {
    int A[MAX][MAX];
    int m, n;
} Graph;


// Khởi tạo đồ thị
void init_graph(Graph* pG, int n) {
    pG->n = n;
    pG->m = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            pG->A[i][j] = NO_EDGE; // Khởi tạo không có cạnh
        }
    }
}

int adjacent(Graph* pG, int u, int v) { //minh sai buoc nay do nham lan vo huong co huong => Doc ky de
    return pG->A[u][v]!=NO_EDGE;
}
void add_edge(Graph* pG, int u, int v, int w) {
    if(adjacent(pG, u, v)) return;
    pG->A[u][v] = w;
    pG->A[v][u] = w;
    pG->m++;
}
int p[MAX], pi[MAX], mark[MAX];
void Dijkstra(Graph* pG, int s) {
    for(int i=1; i<=pG->n; i++) {
        mark[i]=0;
        pi[i]=oo;
        p[i]=-1;
    }

    pi[s]=0;
    // mark[s]=1; khong duoc danh dau o day phai qua buoc so sanh roi moi danh dau
    for(int i=1; i<pG->n; i++) {
        int u=-1, min_pi=oo;
        //So sanh ca 1 hang
        for(int i=1; i<=pG->n; i++) {
            if(!mark[i] && pi[i]<min_pi) {
                min_pi=pi[i];
                u=i;
            }
        }
        //Cai nao nho nhat thi danh dau cai do
        if(u==-1) break;
        mark[u]=1; 
        for(int v=1; v<=pG->n; v++) {
            if(adjacent(pG, u, v)) {
                if(!mark[v] && pi[u]+ pG->A[u][v] < pi[v]) {
                    pi[v]=pi[u]+ pG->A[u][v];
                    p[v]=u;
                }
            }
        }
    }
}

int main() {
    Graph G;
    int n, m, u, v, w, e;

    scanf("%d %d", &n, &m);
    init_graph(&G, n);

    for (e = 0; e < m; e++) {
        scanf("%d %d %d", &u, &v, &w);
        add_edge(&G, u, v, w);
    }
    Dijkstra(&G, 1);

    for (int i = 1; i <= n; i++) {
        printf("pi[%d] = %d, p[%d] = %d\n", i, pi[i], i, p[i]);
    }
    return 0;
}
