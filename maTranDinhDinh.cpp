#include <stdio.h> 
#include <iostream>
#define MAX_Vertices 20
using namespace std;
typedef struct {
	int A[MAX_Vertices][MAX_Vertices];
	int n; //so luong dinh
}Graph;

//Ham khoi tao ma tran 00
void init_Graph(Graph *G, int n) {
	G->n=n;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			G->A[i][j]=0;
		}
	}
	printf("So luong dinh %d\n", G->n);
}
void print_Matrix(Graph* G, int n) {
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			printf("%d ", G->A[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
void add_edge(Graph* G, int row, int col) {
	G->A[row][col]=1;
	G->A[col][row]=1;
}
string adjacent(Graph* G, int x, int y){
	
	return (G->A[x][y]==1&& G->A[y][x]==1)? "true": "false";
}
int degree(Graph* G, int dinh) {
	int countDegree=0;
	for(int i=1; i<=G->n; i++) {
			if(G->A[i][dinh]==1) countDegree++;
		}
	return countDegree;
}
int main() {
	Graph G;
	//khoi tao ma tran 0
	init_Graph(&G, 6);
	//in ma tran 0
	print_Matrix(&G, 6);
	//them cac cung
	int row, col;
	char check=' ';
	while(1) {
		cin>> row>> col;
		add_edge(&G, row, col);
		cout<<"Want to break? Y/N"<<endl;
		cin>> check;
		if(check == 'Y') break;
	}
	
	print_Matrix(&G, 6);
//	cout<< "Kiem tra xem 2 dinh co phai lang gieng ko?"<<endl;
//	while(1) {
//		cout<<"Nhap vao 2 dinh x va y\n";
//		cout<<"X: "; cin>>row;
//		cout<<endl;
//		cout<<"Y: "; cin>>col;
//		cout<< adjacent(&G, row,col);
//		cout<<"\nWant to break? Y/N"<<endl;
//		cin>> check;
//		if(check == 'Y') break;
//	}	
	cout<<"Kiem tra so bac"<<endl;
	int dinh;
	cin>>dinh;
	cout<<"So bac cua dinh "<<dinh <<" la "<<degree(&G, dinh);
	
	return 0;
}
