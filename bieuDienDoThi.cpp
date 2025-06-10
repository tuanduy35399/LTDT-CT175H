#include <iostream>
#define MAX_M 20
using namespace std;
typedef struct {
    int u, v; // u la dinh dau, v la dinh cuoi
}Edge;

typedef struct{
    Edge E[MAX_M]; // mang chua cung
    int n,m; // n la so dinh, m la so cung
}Graph;

void init_graph(Graph* ptrG, int n) {
    ptrG->n=n;
    ptrG->m=0;
}
void add_edge(Graph* ptrG, int u, int v) {
//	if(u<1 || v>ptrG->n || v<1 || u>ptrG->n ) {
//	cout<<"(" <<u<<","<<v<<") khong hop le"<<endl;
//	return; // kiem tra tinh hop le cua dinh
//}
    ptrG->E[ptrG->m].u= u;
    ptrG->E[ptrG->m].v= v;
    ptrG->m++;
}
int adjacent(Graph* ptrG, int u, int v) {
    int i=0;
    //2 dinh ke co dang (u,v) hoac (v,u)
    for(; i<ptrG->m; i++) {
        if(ptrG->E[i].u==u && ptrG->E[i].v==v ||
            ptrG->E[i].u==v && ptrG->E[i].v==u
        ) return 1;
    }
    // neu khong thay cap (u,v) hay (v,u) nao thi u va v khong ke nhau
    return 0;
}
int degree(Graph* ptrG, int dinh) {
    //dinh co the nam o ben u hoac ben v (u,v)
    //Nen ta kiem tra 2 truong hop luon
    int count=0;
    for(int i=0; i< ptrG->m; i++) {
        if(ptrG->E[i].u==dinh || ptrG->E[i].v==dinh) count++;
    }
    return count;
}
void print_G(Graph* ptrG) {
    cout<<"So dinh n "<< ptrG->n <<endl;
    cout<<"So cung m "<< ptrG->m <<endl;
    cout<<"Do thi G "<<endl;
    for(int i=0; i<ptrG->m; i++) {
        cout<< "("<<ptrG->E[i].u<<","<< ptrG->E[i].v<<")"<<endl;
    }
} 
//Liet ke cac dinh ke voi u
void neighbors(Graph* ptrG, int u) {   
    for(int i = 0; i < ptrG->m; i++) {
        if(ptrG->E[i].u == u)
            cout << ptrG->E[i].v << " ";
        else if(ptrG->E[i].v == u)
            cout << ptrG->E[i].u << " ";
    }
    cout << endl;
}

int main() {
    Graph G; //	1,3,4,6,9
    int n=5;
    init_graph(&G, n);
    print_G(&G);
    add_edge(&G, 1, 6);
    add_edge(&G, 1, 3);
//    add_edge(&G, 1, 3);
    add_edge(&G, 9, 3);
    add_edge(&G, 1, 4);
    print_G(&G);
//    int dinh;
//    cin>>dinh;
//    for(int i=1; i<=n; i++) {
//        cout<<"degree ("<<i<<") = "<< degree(&G, i)<<endl;
//    }
    neighbors(&G, 1);
    
    return 0;
}
