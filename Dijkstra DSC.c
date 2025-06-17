#include <stdio.h>
#define MAX 50
typedef struct {
    int u, v, w;
}Edge;
typedef struct {
    int n, m;
    Edge edges[MAX];
}Graph;

void init_graph(Graph* pG, int n) {
    pG->n=n;
    pG->m=0;
}
int adjacent(Graph* pG, int u, int v) {
    for(int i=0; i<pG->m; i++) {
        if((pG->edges[i].u==u && pG->edges[i].v==v)) return 1;
    }
    return 0;
}
void add_edge(Graph* pG, int u, int v, int w) {
    if(adjacent(pG,u,v)) return;
    pG->edges[pG->m].u=u;
    pG->edges[pG->m].v=v;
    pG->edges[pG->m].w=w;
    pG->m++;
}
#define oo 9999999

int p[MAX], pi[MAX], mark[MAX];
void Dijkstra(Graph* pG, int s) {
    //init
    for(int i=1; i<=pG->n; i++) {
        mark[i]=0;
        p[i]=-1;
        pi[i]=oo;
    }
    //boc s
    pi[s]=0;
    for(int i=1; i<pG->n; i++) {
        int u=-1;
        int min_pi=oo;
        for(int i=1; i<=pG->n; i++) {
            if(!mark[i] && pi[i]<min_pi) {
                min_pi=pi[i];
                u=i;
            }
        }
        if(u==-1) break;
        mark[u]=1;
        for(int e=0; e<pG->m; e++) {
            if(pG->edges[e].u==u) {
                int v=pG->edges[e].v;
                int w=pG->edges[e].w;
                if(!mark[v] && pi[u]+ w < pi[v]) {
                    pi[v]=pi[u]+w;
                    p[v]=u;
                }
            }
        }
    }
}
int main() {
    int n, m, u,v, w;
    scanf("%d %d", &n, &m);
    Graph G;
    init_graph(&G, n);
    for(int i=1; i<=m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        add_edge(&G, u, v, w);
    }
    
    Dijkstra(&G, 1);
    for(int i = 1; i <= n; i++) {
        printf("pi[%d] = %d, p[%d] = %d\n", i, pi[i], i, p[i]);
    }
    return 0;
}