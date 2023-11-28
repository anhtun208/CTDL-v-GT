#include <stdio.h>
#include <stdlib.h>

/*void Enqueue(int queue[],int x, int &rear,int arraysize){
	if(rear==arraysize){
		printf("Queue is full");
	}else{
		queue[rear]=x;
		rear++;
	}
}
void Dequeue(int queue[], int&front, int rear){
	if(front==rear){
		printf("Queue is empty");
	}
	else{
		queue[front]=0;
		++front;
		
	}
}
int Front(int queue[],int front){
	return queue[front];}
void Print(int queue[], int front,int rear){
	for(int i=front; i<rear;i++){
		printf("%d -",queue[i]);
	}
}
int main(){
	int front,rear;
	front =rear=0;
	const int Max=100;
	int queue[100];
	int a[]={1,2,4,5,2,1,4,5};
	for(int i=0;i<8;i++){
		
		Enqueue(queue,a[i],rear,Max);
	}
	printf("%d %d",rear,front);
	// Dao lai mang do
	for(int i=0;i<8;i++){
		int x;
		x=Front(queue,i);
	
		Enqueue(queue, x, rear, Max);
		Dequeue(queue, front,rear);
	}
	Print(queue, front, rear);
		
}*/

// Cai dat bang ctlt moc noi
struct Node{
	int data;
	Node*next;
};
typedef struct Node*PNode;
typedef struct{
	PNode F,R;
	
}Queue;
void Khoitao(Queue q){
	q.F=q.R=NULL;
	
}

Node*createNode(int x){
	Node*p=(Node*)malloc(sizeof(Node));
	p->data=x;
	p->next=NULL;
	return p;
}
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
		x=q.F->data;
		q.F=q.F->next;
		return x;
	}
}
int Top(Queue q){
	return q.F->data;
}

int main(){
	Queue q;
	AddQueue(q,10);
	printf("%d",Top(q));
	int a[]={1,2,3,4,5,6,8};
	for(int i=0;i<7;i++){
		AddQueue(q,a[i]);
	}
	DeQueue(q);
	printf("%d",Top(q));
}


