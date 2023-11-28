#include <stdio.h>
// Stack
int current_size =-1;
const int MAX_SIZE = 100;
int stack[MAX_SIZE];
int isempty(){
	return (current_size ==-1);// Kiem tra stack rong.
}
int isfull(){
	return (current_size == MAX_SIZE);// Kiem tra stack day hay chua.
}
// Day phan tu vao trong stack
void push(int data){// Them du lieu vao stack.
	if(!isfull()){
		current_size++;
		stack[current_size]=data;
	}
	else{
		printf("Stack is full");
		
	}
}
int top(){// Lay phan tu top nhung khong xoa
	if(!isempty()){
		int data = stack[current_size];
		return data;
	}
	else{
		printf("Stack is empty");
	}
}
int pop(){ // Lay phan tu top nhung co xoa
	if(!isempty()){
		int data = stack[current_size];
		current_size--;
		return data;
	}
	else{
		printf("Stack is empty");
		
	}
}
int main(){
	push(100);
	push(-255);
	push(-25);
	printf("TOP: %d", top());
	printf("POP: %d", pop());
	
}

