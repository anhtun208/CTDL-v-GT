#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
// C?u trúc nút c?a cây bi?u th?c
struct Node {
 char data;
 struct Node* left;
 struct Node* right;
};
// Hàm t?o m?t nút m?i
struct Node* createNode(char data) {
 struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
 newNode->data = data;
 newNode->left = NULL;
 newNode->right = NULL;
 return newNode;
}
// Hàm ki?m tra xem m?t ký t? có ph?i là toán t? hay không
bool isOperator(char ch) {
 if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
 return true;
 }
 return false;
}
// Hàm chuy?n d?i bi?u th?c chu?i sang cây bi?u th?c
struct Node* convertToExpressionTree(char* expression) {
 struct Node* stack[50];
 int top = -1;
 for (int i = 0; expression[i] != '\0'; i++) {
 if (isalnum(expression[i])) { // N?u là toán h?ng (s? ho?c ch?)
 struct Node* operandNode = createNode(expression[i]);
 stack[++top] = operandNode;
 } else if (isOperator(expression[i])) { // N?u là toán t?
 struct Node* operatorNode = createNode(expression[i]);
 operatorNode->right = stack[top--];
 operatorNode->left = stack[top--];
 stack[++top] = operatorNode;
 }
 }
 return stack[top];
}
// Duy?t cây bi?u th?c theo th? t? tru?c
void preorderTraversal(struct Node* root) {
 if (root != NULL) {
 printf("%c ", root->data);
 preorderTraversal(root->left);
 preorderTraversal(root->right);
 }
}
// Duy?t cây bi?u th?c theo th? t? gi?a
void inorderTraversal(struct Node* root) {
 if (root != NULL) {
 inorderTraversal(root->left);
 printf("%c ", root->data);
 inorderTraversal(root->right);
 }
}
// Duy?t cây bi?u th?c theo th? t? sau
void postorderTraversal(struct Node* root) {
 if (root != NULL) {
 postorderTraversal(root->left);
 postorderTraversal(root->right);
 printf("%c ", root->data);
 }
}
int main() {
 char expression[] = "ab+cde+**";
 struct Node* root = convertToExpressionTree(expression);
 printf("Preorder traversal: ");
 preorderTraversal(root);
 printf("\nInorder traversal: ");
 inorderTraversal(root);
 printf("\nPostorder traversal: ");
 postorderTraversal(root);
 return 0;
}

