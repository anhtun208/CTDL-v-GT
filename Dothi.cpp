#include <stdio.h>
#include <stdlib.h>

/*// Chuyen danh sach canh thanh ma tran ke
int n,m;
int a[100][100];

int main(){
	printf("Nhap so dinh: ");
	scanf("%d",&n);
	printf("Nhap so canh: ");
	scanf("%d",&m);
	int i,j;
	for(i=0;i<m;i++){
		int b,c;
		printf("Nhap dinh 1: ");scanf("%d",&b);
		printf("Nhap dinh 2: ");scanf("%d",&c);
		a[b][c]=a[c][b]=1;
	}
	//Tao ma tran co n hang n cot
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
	return 0;*/
// Chuyen doi danh sach canh sang danh sach ke
struct Node{
	int vertex;//Gia tri nut
	int visited;
	struct Node*next;
};
typedef struct Node*PNode;
typedef struct{
	PNode F,R;
}Queue;
struct Graph{
	int numvertices;//So dinh cua graph
	PNode*lists;//mang cua cac danh sach lien ket
};
typedef struct Graph*PGraph;
// Khoi tao node
PNode createNode(int value){
	PNode temp=(PNode)malloc(sizeof(Node));
	temp->vertex=value;
	temp->next=NULL;
	return temp;
}
// Khoi tao graph
// Dau vao gia tri chi so dinh cua do thi
PGraph createGraph(int vertices){//Gia tri dau vao la so dinh cua graph
	PGraph newgraph=(PGraph)malloc(sizeof(struct Graph));
	newgraph->numvertices=vertices;//Gan so dinh
	newgraph->lists=(PNode*)malloc(vertices*sizeof(PNode));// So phan tu trong mang la so dinh
	// Gan gia tri cho phan tu cua list
	int i;
	PNode temp;
	for(i=0;i<vertices;i++){
		temp=createNode(i);
		newgraph->lists[i]=temp;
	}
	return newgraph;
}
// Them phan tu
void AddEdge(PGraph g, int s, int d){// co ket noi nut s va nut d
	PNode temp=createNode(d);// Tao mot node gia tri la d
	//Them node moi vao dau o vi tri s
	temp->next=g->lists[s]->next;
	g->lists[s]->next=temp;
	temp=createNode(s);
	//Them node moi vao dau o vi tri d;
	temp->next=g->lists[d]->next;
	g->lists[d]->next=temp;
}
void DFS(PGraph g, int vertex){// vertex la dinh bat dau duyet
	g->lists[vertex]->visited=1;
	printf("%d",vertex);// In phan tu duoc tham
	PNode temp=g->lists[vertex]->next;
	while(temp!=NULL){
		int adjvertex=temp->vertex;
		if(g->lists[adjvertex]->visited==0){
			DFS(g,adjvertex);
		}
		temp=temp->next;
	}
}
// Cai dat duyet theo chieu sau
void AddQueue(Queue&q, int x){
	PNode p=createNode(x);
	if(q.F==NULL){
		q.F=q.R=p;
	}
	else{
		q.R->next=p;
		q.R=p;
	}
}
int DeQueue(Queue&q){
	if(q.F==NULL) printf("Queue is Empty");
	else{
		int x;
		x=q.F->vertex;
		q.F=q.F->next;
		return x;
	}
}
int Top(Queue q){
	return q.F->vertex;
}
void BFS(PGraph g, int vertex,Queue&q){
	PNode temp = g->lists[vertex];
	AddQueue(q,g->lists[vertex]->vertex);
}
void printGraph(PGraph g){
	int i;
	for(i=0;i<g->numvertices;i++){
		// Tao mot node de tro den gia tri dau.
		PNode temp=g->lists[i]->next;
		// Duyet mang tung phan
		printf("Dinh %d noi voi cac phan tu: ",g->lists[i]->vertex);
		while(temp){
			printf("%d ",temp->vertex);
			temp=temp->next;
		}
		printf("\n");
	}
}

int main(){
	PGraph graph = createGraph(4);
    AddEdge(graph, 0, 1);
    AddEdge(graph, 0, 2);
    AddEdge(graph, 0, 3);
    AddEdge(graph, 1, 2);
 
    printGraph(graph);
 	DFS(graph,0);
    return 0;
}
