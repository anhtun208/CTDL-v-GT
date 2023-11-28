#include <stdio.h>
void merge(int a[], int l, int m, int r){
	int i=0,j=0;
	int n1=m-l+1;
	int n2=r-m;
	int x[n1],y[n2];
	for(;i<n1;i++){
		x[i]=a[l+i];
	}
	for(;j<r;j++){
		y[j]=a[m+1+j];
	}
	
	// Copy du lieu ra mang tam.
	while(i<n1&&j<n2){
		if(x[i]<=y[j]){
			a[l]=x[i];
			++i,++l;
		}
		else{
			a[l]=y[j];
			++j,++l;
		}
	}
	while(i<n1){
		a[l]=x[i];
		++i,++l;
	}
	while(j<n2){
		a[l]=y[j];
		++j,++l;
	}
}
int main(){
	
}
