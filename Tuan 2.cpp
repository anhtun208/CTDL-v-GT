#include <stdio.h>
#include <math.h>
int main (){
	/*int n,i,max;
	int a[n];
	scanf("%d",&n);
	for (i=0;i<n;i++){
		printf ("Nhap phan tu thu %d ", i+1); 
		scanf("%d",&a[i]);
		 
	}  
	max=a[0];
	for (i=1;i<n;i++){
		if (a[i] > max){
			max=a[i];
		} 
		
	}
	printf ("So lon nhat trong day so la: %d", max);*/
	int n,i;
	printf("Nhap gia tri n: ");
	scanf("%d",&n);
	if(n==1){
		printf(" %d khong  la so nguyen to", n);return 0;
	}
	else if ( n < 4){
		printf(" %d la so nguyen to", n);return 0;
	}
	else {
		for(i=2;i <= sqrt(n);i++){
		if( n%i==0){
			printf(" %d khong la so nguyen to", n);
			return 0;
		}	
		}
		printf("%d la so nguyen to", n);
	}
} 
