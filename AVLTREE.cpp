#include <stdio.h>
						// CAY CAN BANG- AVL TREE
//Xay dung cay can bang
//B1 Dinh nghia kieu du lieu Node
struct Node{
	int data;
	Node*Left;
	Node*Right;
	int height;
};
typedef struct Node Node;
typedef Node*Tree;
// Ham tinh chieu cao cua mot Node
int Height(Tree t){
	if(t==NULL) return 0;
	int a=Height(t->left);
	int b=Height(t->right);
	if(a>b) 
	{return (a+1);}
	else {
	return (b+1);}
}
// Cac ky thuat quay cay
// Ky thuat  quay phai khi cay bi lech trai
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
Node* rightRotate(Node* root){
 Node* x = root->left;
 
 // B?t d?u quay ph?i
 root->left = x->right;
 x->right = root;
 
 // Thi?t l?p chi?u cao
 root->height = 1 + max(getHeight(root->left), getHeight(root->right));
 x->height = 1 + max(getHeight(x->left), getHeight(x->right));
 
 // Return x - tr? v? root m?i
 return x;
}
Node* leftRotate(Node* root) {
	Node* y = root->right;

	// B?t d?u quay trái
	root->right = y->left;
	y->left = root;

	// Thi?t l?p chi?u cao
	root->height = 1 + max(getHeight(root->left), getHeight(root->right));
	y->height = 1 + max(getHeight(y->left), getHeight(y->right));

	// Return y - tr? v? root m?i
	return y;
}
int main(){
	
	return 0;
}
