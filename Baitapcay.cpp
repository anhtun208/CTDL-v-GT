#include <stdio.h>
struct Node{
	char data;
	Node*left;
	Node*right;
};
typedef struct Node*Node;
typedef Node*Tree;
void createTree(Tree t){
	t==NULL;
}
void insertTree(Tree&t,char x){
	if(t==NULL){
		Node p=(Node*)malloc(sizeof(Node));
		p->data=x;
		p->left=NULL;
		p->right=NULL;
	}
	else{
		if(x < t->data){
			insertTree(t->)
		}
	}
}
int main(){
	
}
