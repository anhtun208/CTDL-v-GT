#include <stdio.h>
#include <stdlib.h>
struct Node{
	int data;
	Node*next=NULL;
	Node*prev=NULL;// Con tro lien ket voi node truoc
	
};typedef struct Node*PDNode;
typedef struct{
	PDNode H;// Tro phan tu dau
	PDNode T;// Tro phan tu cuoi
}DLinklist;
Node*createNode(int x){
	PDNode p=(Node*)malloc(sizeof(Node));
	p->data=x;
	p->next=NULL;
	p->prev=NULL;
	return p;
}
void InsertHead(DLinklist&l, int x){
	PDNode p=createNode(x);
	if(l.H==NULL){
		l.H=l.T=p;
	}
	else{
		l.H->prev=p;
		p->next=l.H;
		l.H=p;
	}
}
void InsertTail(DLinklist&l, int x){
	PDNode p=createNode(x);
	if(l.H==NULL){
		l.H=l.T=p;
	}
	else{
		p->prev=l.T;
		l.T->next=p;
		l.T=p;
	}
}
void DelHead(DLinklist&l){
	if(l.H==NULL){
		printf("Linklist is Empty");
		
	}else{
		
		l.H=l.H->next;
		l.H->prev=NULL;
	}
}
void DelTail(DLinklist&l){
	if(l.H==NULL){
		printf("Linklist is Empty");
	}else{
		l.T=l.T->prev;
		l.T->next=NULL;
	}
}
void Traverse(DLinklist l){
	PDNode temp=l.H;
	while(temp!=NULL){
		printf("%d ",temp->data);
		temp=temp->next;
	}
}
int main(){
	DLinklist l;
	int a[]={1,2,3,4,5,6,7,8,9};
	for(int i=0;i<9;i++){
		InsertHead(l,a[i]);
	}
	Traverse(l);
	DelHead(l);DelTail(l);Traverse(l);
	return 0;
}
