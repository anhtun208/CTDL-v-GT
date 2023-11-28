#include <stdio.h>
int main(){
	int n,m,i,j;
	printf("Nhap so phan tu trong mang 1: ");
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++){
		printf("Nhap gia tri phan tu thu %d: ",i+1);
		scanf("%d",&a[i]);
	}
	// Tim phan tu nho nhat.
	/*int min, cnt;
	min=a[0],cnt=1;
	for(i=1;i<n;i++){
		if(a[i]<min){
			a[i]=min;
			cnt=i+1;
		}
	}
	printf("Vi tri so be nhat nam o so thu %d.",cnt);*/
	// Chen mot so vao mot vi tri cho truoc trong mang.
	/*int c,d;
	printf("Nhap so can chen.");
	scanf("%d",&c);
	printf("Nhap vi tri can chen.");
	scanf("%d",&d);
	n++;
	for(i=n-1;i>d-1;i--){
		a[i]=a[i-1];
		
	};a[d-1]=c;
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
	}*/
	// Chon phan tu de xóa.
/*	int d;
	printf("Nhap vi tri phan tu de xoa.");
	scanf("%d",&d);
	
	for(i=d-1;i<n;i++){
		a[i]=a[i+1];
		
	};n--;
	for(int i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	*/
	// Gop hai mang thanh mot mang có sap xep
	printf("Nhap so phan tu trong mang 2: ");
	scanf("%d",&m);
	int b[m];
	for(j=0;j<m;j++){
		printf("Nhap gia tri phan tu thu %d: ",j+1);
		scanf("%d",&b[j]);
	}
	int c[m+n], nb;
	nb=0;
	for(i=0;i<n;i++){
		c[nb]=a[i];
		nb++;
	}
	for(int j=0;j<n;j++){
		c[nb]=b[j];
		nb++;
	}int tg;
    for(int i = 0; i < (m+n) - 1; i++){
        for(int j = i + 1; j < (m+n); j++){
            if(c[i] > c[j]){
                // Hoan vi 2 so c[i] va c[j]
                tg = c[i];
                c[i] = c[j];
                c[j] = tg;        
            }
        }
    }
	/*i=0,j=0,k=0;
	int c[m+n];
	while( i<n && j<m){
		if(a[i]<b[j]){
			c[k]=a[i];
			i++;
		}
		else{
			c[k]=b[j];
			j++;
		}
		k++;
	}
	while (i < n ){
		c[k]=a[i];
		k++,i++;
	}
	while (j < m ){
		
		c[k]=b[j];
		k++,j++;
	}
	for(k=0;k<(m+n);k++){
		printf("%d ",c[k]);
	}*/
	for(i=0;i<m+n;i++){
		printf("%d",c[i]);
	}
}
