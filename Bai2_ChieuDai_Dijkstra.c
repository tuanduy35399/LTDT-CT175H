// #include <stdio.h>
// #define MAX 200 
// typedef struct {
//     int u, v, w;
// }Edge;

// typedef struct {
//     int n,m;
//     Edge edges[MAX];
// }Graph;

// void init_graph(Graph* pG, int n) {
//     pG->n=n;
//     pG->m=0;
// }
// int adjacent(Graph* pG, int u, int v) {
//     for(int i=0; i<pG->m; i++) {
//         if((pG->edges[i].u==u && pG->edges[i].v==v) ) return 1;
//     }
//     return 0;
// }

// void add_edge(Graph* pG, int u, int v, int w) {
//     if(adjacent(pG, u, v)) return;
//     pG->edges[pG->m++]= (Edge) {u, v, w};
// }
// #define oo 999999
// int p[MAX], pi[MAX],mark[MAX];
// void Dijkstra(Graph* pG, int s) {
//     for(int i=1; i<=pG->n; i++) {
//         mark[i]=0;
//         p[i]=-1;
//         pi[i]=oo;
//     }
//     pi[s]=0;
//     for(int i=1; i<pG->n; i++) {
//         int u=-1, min_pi=oo;
//         for(int i=1; i<=pG->n; i++) {
//             if(!mark[i] && pi[i] < min_pi) {
//                 min_pi=pi[i];
//                 u=i;
//             }
//         }
//         if(u==-1) break;
//         mark[u]=1;
//         for(int i=0; i<pG->m; i++) {
//             if(pG->edges[i].u==u) {
//                 int v=pG->edges[i].v;
//                 int w=pG->edges[i].w;
//                 if(!mark[v] && pi[u]+w < pi[v]) {
//                     pi[v]=pi[u]+w;
//                     p[v]=u;
//                 } 
//             }
//         }
//     }
// }
// int main() {
//     int n, m, u, v, w;
//     scanf("%d %d", &n, &m);
//     Graph G;
//     init_graph(&G, n);
//     for(int i=1; i<=m; i++) {
//         scanf("%d %d %d", &u, &v, &w);
//         add_edge(&G, u, v, w);
//     }
//     int s, t;
//     scanf("%d %d", &s, &t);
//     Dijkstra(&G, s);
//     // if(pi[n]==oo) printf("-1");
//     // else printf("%d", pi[n]);


//     if(pi[t]!=oo) {
//         int u=t, len=0,path[MAX];
//         while(u!=-1) {
//             path[len++]=u;
//             if(u==s) break;
//             u=p[u]; 
//         }
//         printf("%d", path[len-1]);
//         for(int i=len-2; i>=0; i--) {
//             printf(" -> %d", path[i]);
//         }
//     }
//     return 0;
// }


#include <stdio.h>
#define MAX 200 
typedef struct {
    int u, v, w;
}Edge;

typedef struct {
    int n,m;
    Edge edges[MAX];
}Graph;

void init_graph(Graph* pG, int n) {
    pG->n=n;
    pG->m=0;
}
int adjacent(Graph* pG, int u, int v) {
    for(int i=0; i<pG->m; i++) {
        if((pG->edges[i].u==u && pG->edges[i].v==v) ||
        (pG->edges[i].u==v && pG->edges[i].v==u) ) return 1;
    }
    return 0;
}

void add_edge(Graph* pG, int u, int v, int w) {
    if(adjacent(pG, u, v)) return;
    pG->edges[pG->m++]= (Edge) {u, v, w};
    pG->edges[pG->m++]= (Edge) {v, u, w};
    
}
#define oo 999999
int p[MAX], pi[MAX],mark[MAX];
void Dijkstra(Graph* pG, int s) {
    for(int i=1; i<=pG->n; i++) {
        mark[i]=0;
        p[i]=-1;
        pi[i]=oo;
    }
    pi[s]=0;
    for(int i=1; i<pG->n; i++) {
        int u=-1, min_pi=oo;
        for(int i=1; i<=pG->n; i++) {
            if(!mark[i] && pi[i] < min_pi) {
                min_pi=pi[i];
                u=i;
            }
        }
        if(u==-1) break;
        mark[u]=1;
        for(int i=0; i<pG->m; i++) {
            if(pG->edges[i].u==u) {
                int v=pG->edges[i].v;
                int w=pG->edges[i].w;
                if(!mark[v] && pi[u]+w < pi[v]) {
                    pi[v]=pi[u]+w;
                    p[v]=u;
                } 
            }
        }
    }
}
int main() {
    int n, m, u, v, w;
    scanf("%d %d", &n, &m);
    Graph G;
    init_graph(&G, n);
    for(int i=1; i<=m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        add_edge(&G, u, v, w);
    }
    int s, t;
    scanf("%d %d", &s, &t);
    Dijkstra(&G, s);
    // if(pi[n]==oo) printf("-1");
    // else printf("%d", pi[n]);


    if(pi[t]!=oo) {
        int u=t, len=0,path[MAX];
        while(u!=-1) {
            path[len++]=u;
            if(u==s) break;
            u=p[u]; 
        }
        printf("%d", path[len-1]);
        for(int i=len-2; i>=0; i--) {
            printf(" -> %d", path[i]);
        }
    }
    return 0;
}


