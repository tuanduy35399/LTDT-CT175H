#include <stdio.h> 
#define MAX 50

typedef struct {
	ElementType data[MAX];
	int size;
}List;

void make_null(List* pL) {
	pL->size=0;
}
void push_back(List* pL, int dinh) {
//do thi co huong thi moi kiem tra 
//	for(int i=0; i<pL->size; i++) {
//		if(pL->elements[i]==dinh) {
//			return;	
//		} 
//	}
	//neu dinh chua ton tai
		pL->data[pL->size]=dinh;
		pL->size++;
}
//lay phan tu thu i (0,1,2,3...n-1) => (i-1)
int getElement(List* pL, int i) {
	return pL->data[i-1];
}
typedef struct {
	int n;
	List adj[MAX];
}Graph;
void init_graph(Graph* pG, int n) {
	pG->n=n;
	for(int i=1; i<=pG->n; i++) {
		make_null(pG->adj[i]);
	}
}


int main() {
	Graph G;
	//khoi tao danh sach dinh ke
	int n=5;
	init_graph(&G, n);
	
	return 0;
}

