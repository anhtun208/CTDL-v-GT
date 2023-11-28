#include <stdio.h>
#include <stdlib.h>
struct Node{
int data;
Node*next;
Node*prev;
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
p->prev=NULL;
return p;
}
PNode getTail(PNode h){
if(h==NULL|| h->next==NULL){
return h;
}
PNode current = h;
while(current->next!=NULL){
current=current->next;
}
return current;
}
void InsertHead(Linklist&l, int x){
PNode p=createNode(x);
if(l.H==NULL){
l.H=l.T=p;
}
else{
l.H->prev=p;
p->next=l.H;
l.H=p;
}
}
void swap(int &x, int &y)
{
 int temp = x;
 x = y;
 y = temp;
}
PNode qsPartiton(PNode h, PNode t, PNode *newH,PNode *newT){
PNode pivot,prev,current,tail;
pivot = t;
prev=NULL;
current=h;
tail=pivot;
while(current!=pivot){
if(current->data < pivot->data){
if(*newH==NULL){
*newH=current;
}
prev=current;
current = current->next;
}
else{
if(prev){
prev->next=current->next;
}
PNode temp=current->next;
current->next=NULL;
tail->next=current;
tail=current;
current=temp;
}
}
if(*newH==NULL){
*newH=pivot;
}
*newT=tail;
return pivot;
}
PNode sortQuickRange(PNode h, PNode t){
if(h==NULL||h==t){ 
return h;
} 
PNode newH=NULL;
PNode newT=NULL;
PNode c=qsPartiton(h,t,&newH,&newT);
if(newH!=c){
PNode temp=newH;
while(temp->next!=c){
temp=temp->next;
}
temp->next=NULL;
newH=sortQuickRange(newH,temp);
temp=getTail(newH);
temp->next=c;
} 
c->next=sortQuickRange(c->next,newT);
return newH; 
}
void Traverse(Linklist l){
PNode temp=l.H;
while(temp!=NULL){
printf("%d ",temp->data);
temp=temp->next;
}
}
int main(){
int a[]={1,2,4,6,0,8,9,3};
Linklist l;
int i;
for(i=0;i<8;i++){
InsertHead(l,a[i]);
}
Traverse(l);
printf("\n");
sortQuickRange(l.H,l.T);
Traverse(l);
}

