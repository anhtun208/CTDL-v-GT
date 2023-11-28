#include <stdio.h>
#include <stdlib.h>

struct Node{// Khai bao mot Node
	int data;
	Node* left;
	Node* right;
};
typedef struct Node Node;
typedef Node*Tree;
void Khoitaocay(Tree t){
	t=NULL;
}
void createTree(Tree&t,int x){// Ham them Node
	if(t==NULL){
		Node*p=(Node*)malloc(sizeof(Node));
		p->data=x;
		p->left=NULL;
		p->right=NULL;
		t=p;
	}
	else{
		if(t->data>x){
			createTree(t->left,x);
		}
		else if(t->data<x){
			createTree(t->right,x);
		}
	}
}
void NLR(Tree t){
	if(t==NULL)return;
	else{
		printf("%d -> ",t->data);
		NLR(t->left);
		NLR(t->right);
	}
}
void inorderTravesall(Tree t){// XUat thu tu LNR
	if(t==NULL) return;
	else{
		inorderTravesall(t->left);
		printf("%d -> ",t->data);
		inorderTravesall(t->right);
		
	}
	
}
void posorderTravesall(Tree t){// Xuat node theo thu tu LRN
	if(t==NULL) return;
	else{
		posorderTravesall(t->left);
		posorderTravesall(t->right);
		printf("%d -> ",t->data);
		
	}
	
}
int  Timkiem(Tree t, int x){ // Ham tim kiem node
	if(t==NULL) return NULL;
	if(t->data > x) Timkiem(t->left,x);
	if(t->data < x) Timkiem(t->right,x);
	if(t->data == x) return 1;
}
void Node2con(Tree t){ // Tim Node 2 con
	if(t!=NULL){
	if(t->left!=NULL&&t->right!=NULL) printf("%d ; ",t->data);
	Node2con(t->left);
	Node2con(t->right);
	}
}
void Node1con(Tree t){ // Tim node 1 con
	if(t!=NULL){
	if((t->left!=NULL&&t->right==NULL)||(t->left==NULL&&t->right!=NULL)) {
	printf("%d ; ",t->data);}
	Node1con(t->left);
	Node1con(t->right);
	}
}
void Nodela(Tree t){ // Tim node la
	if(t!=NULL){
	if(t->left==NULL&&t->right==NULL) printf("%d ; ",t->data);
	Nodela(t->left);
	Nodela(t->right);
	}
}
void NodeMax(Tree t){ // Ham tim Node lon nhat
	if(t->right==NULL){
		printf("%d",t->data);
		return;
	}
	NodeMax(t->right);
}
void NodeMin(Tree t){// Ham tim Node be nhat
	if(t->left==NULL){
		printf("%d",t->data);
		return;
	}
	NodeMin(t->left);
}
void XoaNode(Tree &t,int x){// Ham xoa Node

if (t==NULL) {return;}
else{
	if(t->data > x){
		XoaNode(t->left,x);
	}
	else if(t->data < x){
		XoaNode(t->right,x);
	}
	else{
		Node*X,*Y;
		if(t->right==NULL){
			X=t;
			t=t->left;
		}
		else if(t->left==NULL){
			X=t;
			t=t->right;
		}
		else{
			X=t->left;
			if(X->right==NULL){
				t->data=X->data;
				t->left=X->left;
			}
			else{
				do{
					Y=X;
					X=X->right;
				}while(X->right!=NULL);
				t->data=X->data;
				Y->right=X->left;
			}
			
		}
		delete X;
		}
	}
}

int Height(Tree t){
	if(t==NULL) return 0;
	int a=Height(t->left);
	int b=Height(t->right);
	if(a>b) 
	{return (a+1);}
	else {
	return (b+1);}
}
void DestroyTree(Tree&t){
	if(t){
		DestroyTree(t->left);
		DestroyTree(t->right);
		delete t;
	}
}


int main(){
	Tree t;
	int i, a[]={1,3,4,2,-1,-2,0,3,21,-20};
	for(i=0;i<10;i++){
		createTree(t,a[i]);
	}
	NLR(t);
	printf("\t");
	inorderTravesall(t);
	printf("\t");
	posorderTravesall(t);
	printf("\n");
	Timkiem(t,100);
	printf("\n");
	Node1con(t);printf("\n");Node2con(t);printf("\n");Nodela(t);printf("\n");
	NodeMax(t);printf("\n");NodeMin(t);printf("\n");
	XoaNode(t,3);
	NLR(t);printf("\n");
	printf("%d",Height(t));
	DestroyTree(t);
	
	
}
