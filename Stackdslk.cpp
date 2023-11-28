#include <stdio.h>
#include <stdlib.h>
// Stack Ngan xep
// C1 Su dung mang.
/*push: thêm phan tu vao cuoi cua mang.
pop: Xoa phan tu cuoi cua mang
top: Lay ra phan tu cuoi cua mang.*/
// Cai dat
/*int n=0, st[100001];

void push(int x){
	st[n]=x;
	n++;
}
void pop(){
	if(n>1){
		--n;
	}
}
int top(){
	return st[n-1];
}
int main(){
	while(1){
		printf("1: push \n 2: pop \n 3: top");
		int lc;
		printf("Moi nhap lua chon:"); scanf("%d",&lc);
		if(lc==1){
			int x;printf("Nhap phan tu can them: ");scanf("%d",&x);
			push(x);
		}
		else if(lc==2){
			pop();
		}
		else if(lc==3){
			top();
		}
		else{
			break;
		}
	}
}*/
//C2 Su dung danh sach lien ket
struct Node{
	int data;
	Node* next;
};

typedef struct Node*stack;
int isEmpty(stack s){
	return (s==NULL);
}

Node*createNode(int data){
	Node*p=(Node*)malloc(sizeof(Node));
	if(p==NULL){
		return NULL;
	}
	else{
		p->data=data;
		p->next=NULL;
	}
	return p;
}
void push(stack&s,int data){
	Node*ptr=createNode(data);
	if(isEmpty(s)){
		s=ptr;
	}
	else{
		ptr->data=data;
		ptr->next=s;
		s=ptr;
	}
}
int top(stack s){
	if(!isEmpty(s)){
		return s->data;
	}
	else{
		printf(" Is empty");
	}
}
int pop(stack &s){
	if(!isEmpty(s)){
		int data=s->data;
		Node*x=s;
		s=s->next;
		delete(x);// Giai phong bo nho
		return data;
	}
	else{ 
	printf("Stack is Empty");
	}
}
int main(){
	stack s;
	/*push(s,100);
	push(s,200);
	push(s,300);
	top(s);
	pop(s);
	while(!isEmpty(s)){
		int data=top(s);
		pop(s);
		printf(" %d <--",data);
	}*/
	// Bien doi mot so bat ki sang co so 2
	int x;
	printf("Nhap so can bien doi: ");
	scanf("%d",&x);
	while(x){
		push(s,x%2);
		x=x/2;
	}
	while(!isEmpty(s)){
		int data=top(s);
		pop(s);
		printf(" %d <--",data);
	}
	
}
