#include <stdio.h>
#include <stdlib.h>
// Sap xep chon- Selection Sort
struct Node{
	int data;
	Node*next;
};
typedef struct Node*PNode;
typedef struct{
	PNode H;
	PNode T;
}Linklist;
PNode createNode(int x){
	PNode p=(PNode)malloc(sizeof(Node));
	p->data=x;
	p->next=NULL;
	return p;
}
// Dao hai phan tu
void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}
void InsertHead(Linklist&l, int x){
	PNode p=createNode(x);
	if(l.H==NULL){
		l.H=l.T=p;
	}
	else{
		p->next=l.H;
		l.H=p;
	}
}
void Selection_Sort(Linklist&l){
	PNode p,q,min;
	for(p=l.H;p!=NULL;p=p->next){
		min=p;
		for(q=p->next;q!=NULL;q=q->next){
			if(q->data<min->data){
				min=q;
			} 	
		}
		swap(min->data,p->data);
	}
}
// Sap xep chen
void Insertion_Sort(Linklist&l){
	if(l.H==NULL||l.H->next==NULL) return;
	PNode p=NULL;
	PNode q=l.H;
	while(q!=NULL){
		PNode nextNode=q->next;
		if(p==NULL|| q->data < p->data){
			q->next=p;
			p=q;
		}
		else{
			PNode temp=p;
			while(temp->next!=NULL && temp->next->data < q->data){
				temp=temp->next;
			}
			q->next=temp->next;
			temp->next=q;
		}
		q=nextNode;
	}
	l.H=p;
}

// Sap xep noi bot
void Bubble_Sort(Linklist&l)
{
    PNode i, j;
    int  haveSwap;
    for (i = l.H; i!=NULL; i=i->next){
        haveSwap = 0;
        for (j=l.H; j->next!=NULL; j=j->next){
            if (j->next->data < j->data){
                swap(j->data, j->next->data);
                haveSwap = 1;
            }
            if(j->next->data==l.T->data){
            	l.T=j;
            	
			}
			
        }
        if(haveSwap == 0){
            break;
        }
        
    }
}
// In mang
void printArray(Linklist l)
{
    PNode p;
    for(p=l.H;p!=NULL;p=p->next){
    	printf("%d-",p->data);
	}
}


int main(){
	Linklist l;
	int a[]={1,2,5,6,7,3,4,10,9,11};
	for(int i=0;i<10;i++){
		InsertHead(l,a[i]);
	}
	printArray(l);
	printf("\n");
	//Selection_Sort(l);
	//Bubble_Sort(l);
	Insertion_Sort(l);
	printArray(l);
}
