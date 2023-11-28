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
void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
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
void Insertion_Sort(DLinklist &l){
	PDNode p,i;
	for(i=l.H;i->next!=NULL;i=i->next){
		p=i;
		while((p->prev->data > p->data)&& (p->prev!=NULL)){
			p=p->prev;
			printf("%d",p->data);
		}
	
	swap(p->data,i->data);
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
	int a[]={2,0,2,1,4,1,2,7};
	for(int i=0;i<8;i++){
		InsertHead(l,a[i]);
	}
	Traverse(l);
	Insertion_Sort(l);
	Traverse(l);
}
