#include <stdio.h>
#include <stdlib.h>
// Sap xep chon- Selection Sort
struct Node{
	int data;
	Node*next;
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
	return p;
}
void InsertHead(Linklist&l, int x){
	PNode p=createNode(x);
	if(l.H==NULL){
		l.H=l.T=p;
	}
	else{
		p->next=l.H;
		l.H=p;
	}
}
void swap(int &xp, int &yp)
{
    int temp = xp;
    xp = yp;
    yp = temp;
}
void Selection_Sort(int a[], int n){
	int Min,i,j;
	for(i=0;i<n-1;i++){
		Min=i;
		for(j=i+1;j<n;j++){
			if(a[j]<a[Min]) Min=j;
		if(Min!=i){
		swap(a[Min], a[i]);
		}
	}
}
}
// Sap xep chen
void Insertion_Sort(int a[], int n){
	int i;
	for(i=1;i<n;i++){
		int temp=a[i];
		int j=i-1;
		while((temp<a[j])&&(j>=0)){
			a[j+1]=a[j];
			--j;
		}
	a[j+1]=temp;
	}
}
// Dao hai phan tu
void swap(int x, int y)
{
    int temp = x;
    x = y;
    y = temp;
}

// Sap xep noi bot
void Bubble_Sort(int arr[], int n)
{
    int i, j;
    bool haveSwap = false;
    for (i = 0; i < n-1; i++){
        haveSwap = false;
        for (j = 0; j < n-i-1; j++){
            if (arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                haveSwap = true;
            }
        }
        if(haveSwap == false){
            break;
        }
    }
}
//QuickSort
int qsPartitonLomuto(int a[], int l, int r){
	int pivot=a[r];
	int i=l,j=l;
	for(i=l,j=l;j<r;j++){
		if(a[j] < pivot){
			swap(a[i],a[j]);
			i++;
		}
	}
	swap(a[i], a[r]);
	return i;
}
int qsPartitionHoare(int a[], int l, int r){
	int pivot=a[r];
	int i,j;
	for(i=l,j=r-l;i<j;){
		for(;a[i] < pivot && i <j;i++);
		for(;a[j] >= pivot && i <j;j--);
		swap(a[i], a[j]);
	}
	if(a[r] > a[i]) return r;
	swap(a[i], a[r]);
	return i;
}
void sortQuickRange(int a[],int l, int r){
	if(l<r){
		int c=qsPartitionHoare(a,l,r);
		sortQuickRange(a,l,c-1);
		sortQuickRange(a,c+1,r);
	}
}
// Sap xep tron
// Tron hai day su dung bo nho tam
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
    /* T?o các m?ng t?m */
    int L[n1], R[n2];
 
    /* Copy d? li?u sang các m?ng t?m */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
 
    /* G?p hai m?ng t?m v?a r?i vào m?ng arr*/
    i = 0; // Kh?i t?o ch? s? b?t d?u c?a m?ng con d?u tiên
    j = 0; // Kh?i t?o ch? s? b?t d?u c?a m?ng con th? hai
    k = l; // IKh?i t?o ch? s? b?t d?u c?a m?ng luu k?t qu?
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    /* Copy các ph?n t? còn l?i c?a m?ng L vào arr n?u có */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    /* Copy các ph?n t? còn l?i c?a m?ng R vào arr n?u có */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
/* l là ch? s? trái và r là ch? s? ph?i c?a m?ng c?n du?c s?p x?p */
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        // Tuong t? (l+r)/2, nhung cách này tránh tràn s? khi l và r l?n
        int m = l+(r-l)/2;
 
        // G?i hàm d? quy ti?p t?c chia dôi t?ng n?a m?ng
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
 
        merge(arr, l, m, r);
    }
}
// Heap Sort
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(arr[i],arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}



int main(){
	int a[]={16,30,9,8,5,12,7};
	Selection_Sort(a,7);
	for(int i=0;i<7;i++){
		printf("%d ",a[i]);
	}
	
	/*Insertion_Sort(a,12);
	for(int i=0;i<13;i++){
		printf("%d ",a[i]);
	}*/
	/*mergeSort(a,0,11);
	for(int i=0;i<12;i++){
		printf("%d ",a[i]);
	}*/
/*(	heapSort(a,12);
	for(int i=0;i<12;i++){
		printf("%d ",a[i]);}*/
}
