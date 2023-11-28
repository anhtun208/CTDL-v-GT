#include<stdio.h>
#include <stdlib.h>
struct Node{
struct Node *next;
int data;
};
typedef Node *PNode;
typedef PNode List;
PNode createNode( int x ){
PNode p = (PNode)malloc(sizeof(struct Node));
p->data = x;
p->next = NULL;
return p;
}
void addTail( List &l, int x ){
PNode p = createNode(x);
if(!l) l = p;
else{
PNode r = l;
while(r->next) r = r->next;
r->next = p;
r = p;
}
}
void xuat( List l ){
while(l){
if(l->next) printf("%d -->",l->data);
else printf("%d",l->data);
l = l->next;
}
printf("\n");
}
void nhap(List &l ){
int n, x,i;
scanf("%d",&n);

for( i = 0; i< n; i++ ){
printf(" Nhap phan tu thu %d: ",i+1);
scanf("%d",&x);
addTail( l, x );
}
}
// tron hai danh sach da sap xep thanh danh sach sap xep.
// lan luot k tra hai phan tu dau l1,l2, chon lay phan tu co gia tri nho hon
// chen vao cuoi l. thuc hien cho toi khi 1 trong hai danh sach rong.
PNode merge( List l1, List l2 ){
if(!l2) return l1;
else if( !l1 ) return l2;
List l = NULL;
if( l1->data < l2->data ){
l = l1;
l->next = merge(l1->next, l2);
}
else{
l = l2;
l->next = merge(l1, l2->next);
}
return l;
}
// tim phan tu middle cua danh sach lien ket.
// dung hai bien chay Node *p, *q. trong do p tang 1:1, q tang 2:1
// khi q->phan tu cuoi cung cua danh sach thi p chinh la phan tu mid can tim.
PNode getMid( List l ){
if(!l) return l;
PNode p,q;
p = q = l;
while(q->next && q->next->next){
p = p->next;
q = q->next->next;
}
return p;
}
void tach( List l, List &l1, List &l2 ){
PNode mid = getMid(l);
l1 = l;
l2 = mid->next;
mid->next = NULL;
}
void mergeSort( List &l ){
List l1 = NULL, l2 = NULL;
if( !l || !l->next ) return;
tach(l, l1, l2 );
mergeSort(l1);
mergeSort(l2);
l = merge( l1, l2);
}
int main(){
List l1;
l1 = NULL;
nhap(l1);
xuat(l1);
mergeSort(l1);
xuat(l1);
return 0;
}

