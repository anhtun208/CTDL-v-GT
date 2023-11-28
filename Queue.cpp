// Chuyen doi day tu 1234 sang 4123
#include <stdio.h>
/*void Enqueue(int a[],int x, int &rear, int arraySize){
	if(rear==arraySize){
		printf("Queue is Full");
	}else{
		a[rear]=x;
		rear++;
	}
}
void Dequeue(int a[],int &front,int rear){
	if(front==rear){
		printf("Queue is Empty");
	}
	else{
		a[front]=0;
		front++;
	}
}
int Front(int a[],int front){
	return a[front];
}
int main(){
	int a[20]={1,2,3,4};
	int front=0, rear=4;
	int arraySize=20;
	int i,n=3,k;
	for(i=0;i<n;i++){
		k=Front(a,front);
		Enqueue(a,k,rear,arraySize);
		Dequeue(a,front,rear);
	}
	printf("%d, %d",front,rear);
	for(i=front;i<rear;i++){
		printf("%d",a[i]);
		
	}
	
}*/
// Hàng doi hai dau: du lieu co the duoc them hoac xoa o dau hoac cuoi hang doi
// Them du lieu vao cuoi
void AddLastQueue(int queue[], int element, int & rear, int arraySize){
	if(rear==arraySize){
		printf("Queue is FUll");	
	}
	else{
		queue[rear]=x;
		rear++;
	}
}
// Xoa du lieu cuoi cung queue
void DeleteLastQueue(int queue[], int &rear, int front){
	if(front==rear)
		printf(" Queue is Empty");
	else{
		rear--;
		queue[rear]=0;
	}
}
// Them du lieu o dau
void AddFirstQueue(int queue[],int &rear,int &front,int arraySize,int element){
	if(rear=arraySize){
		printf(" Queue is Full");	
	}else{
		int i;
		for(i=rear;i>front;i--){
			queue[i]=queue[i-1];
		}
		queue[front]=element;
		rear=rear+1;
	}
}
// Xoa du lieu o dau
void DeleteFirstQueue(int queue[], int &front, int rear){
	if(front==rear){
		printf(" Queue is Empty");
	}else{
		queue[front]=0;
		front++;
	}
}
// Lay gia tri o dau
int GetFirstQueue(int queue[], int front){
	return queue[front];
}
// Lay gia tri o cuoi
int GetLastQueue(int queue[], int rear){
	return queue[rear-1];
}
// Hang doi vong: Su dung cac vi tri ma da bi xoa di de them phan tu vao. Can them mot bien la bien count de dem so phan tu

void AddQueue(int queue[], int element, int& rear, int &count, int arraySize){
	if(count==arraySize){
		printf(" Is Full");
	}
	else{
		queue[rear]=element;
		rear=(rear+1)%arraySize;
		count++;
	}
}
// Hang doi vong xoa
void DeQueue(int queue[], int &front, int &count, int arraySize){
	if(count ==0){
		printf(" Is Empty");
	}
	else{
		queue[front]=0;
		front=(front+1)%arraySize;
		count--;
	}
}
