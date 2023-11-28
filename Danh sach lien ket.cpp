#include <stdio.h>
#include <stdlib.h>
					//Danh sach lien ket
//KHoi tao mot struct Linklist
struct Linklist{
	int data;
	struct Linklist*next;
};
typedef struct Linklist* Node;
// Tao moi mot Node
Node createnode(int x){
	Node p;
	p=(Node)malloc(sizeof(struct Linklist));// Cap phat dong cho mot Node
	p->data=x;
	p->next=NULL;
	return p;
}
// Them node vao  dau DSLK (thay doi head)
Node AddHead(Node head,int x){
	Node temp=createnode(x);// Khoi tao mot node
	if(head==NULL) head=temp;
	else{
		temp->next=head;
		head=temp;
	}
	return head;
}
void Selection_Sort(Linklist&l){
	PNode p,q;
	for(p=l.H;p!=NULL;p=p->next){
		
		for(q=p->next;q!=NULL;q=q->next){
			if(q->data<p->data){
				swap(q->data,p->data);
			}	
		}
	}
}
Node AddTail(Node head, int x){
	Node temp,p;
	temp=createnode(x);
	if(head==NULL){
		head=temp;
	}else{
		p=head;
		while(p->next!=NULL){
			p=p->next;
		}
		p->next=temp;
	}
	return head;
}
Node Add(Node head,int x,int position){// position: vi tri can chen Node
	if(position==0|| head== NULL){
		head=AddHead(head,x);
	}
	else{
		int k=1;// Tao mot bien de do ra vi tri can them
		Node p=head;
		while(k!=position && p!=NULL){
			p=p->next;
			++k;
		}
		if(k!=position){
			head=AddTail(head,x);
		}
		else{
			Node temp;
			temp=createnode(x);
			temp->next=p->next;
			p->next=temp;
			
		}
	}
	return head;
}
Node DelHead(Node head){

	
	if(head==NULL){
		printf("Danh sach rong !! \n");
	}
	else{
	head=head->next;}
	return head;
}
Node DelTail(Node head){
	if(head==NULL|head->next==NULL){
		return DelHead(head);
	}
		Node p=head;
		while(p->next->next==NULL){
			p=p->next;
		}
		p->next=NULL;
		return head;
}
Node Del(Node head, int position){
	 if(position==0|| head==NULL || head->next==NULL){
	 	head= DelHead(head);
	 }
	 else{
	 	int k=1;
	 	Node p=head;
	 	while(k!=position|| p->next->next==NULL){
	 		p=p->next;
	 		k++;
		 }
		 if(k!=position){
		 	head = DelTail(head);
		 }else{
		 	p->next=p->next->next;
		 }
	 }
	 return head;
}
int Get(Node head, int index ){
	int k=0;
	Node p=head;
	while(k!=index && p->next!=NULL){
		p=p->next;
	}
	return p->data;
}
int Search(Node head, int x){
	int k=0;
	Node p;
	for(p=head;p!=NULL;p=p->next){
		if(p->data=x){
			return k;
		}
		++k;
	}
	return -1;
}
void Traverser(Node head){
	Node p;
	for(p=head;p!=NULL;p=p->next){
		printf("%d -",p->data);
	}
}
Node Inithead(){
	Node head;
	head=NULL;
	return head;
}
Node Input(){
	Node head= Inithead();
	int n, value;
	do {
		printf("Nhap so luong phan tu: ");
		scanf("%d",&n);
	}while(n<=0);
	for(int i=0;i<n;i++){
		printf("Nhap gia tri can them");
		scanf("%d",&value);
		head=AddTail(head,value);
	}
	
	return head;
}


int main(){
	Node head=Input();
	Traverser(head);
	printf("Them mot phan tu \n");
	head=Add(head,100,2);
	Traverser(head);
	head=AddHead(head,200);
	Traverser(head);
	
	
	
	
	
}
