#include <stdio.h>
int main(){
	int n,m;
	printf("Nhap so dinh: ");
	scanf("%d",&n);
	printf("Nhap so canh: ");
	scanf("%d",&m);
	int i,j,a[1001][1001];
	for(i=0;i<m;i++){
		int b,c;
		printf("Nhap dinh 1: ");scanf("%d",&b);
		printf("Nhap dinh 2: ");scanf("%d",&c);
		a[b][c]=1;
	}
	//Tao ma tran co n hang n cot
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
	return 0;
}
