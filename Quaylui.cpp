#include <stdio.h>
					// 	THUAT TOAN QUAY LUI
/*
Ma gia
Backtracking(k) {
	for([M?i phuong án ch?n i(thu?c t?p D)]) {
		if ([Ch?p nh?n i]) {
			[Ch?n i cho X[k]];
			if ([Thành công]) {
				[Ðua ra k?t qu?];
			} else {
				Backtracking(k+1);
				[B? ch?n i cho X[k]];
			}
		}
	}
}
*/
// Bai 1 Thuat toan quay lui xau nhi phan co do dai n
/*int N,X[100];

void inkq(){
	for(int i=1;i<=N;i++){
		printf("%d",X[i]);
	}
	printf("\t");
}
void Try(int i){
	int j;
	for(int j=0;j<=1;j++){
		X[i]=j;
		if(i==N){
			inkq();
		}
		else{
			Try(i+1);
		}
	}
}
int main(){
	scanf("%d",&N);
	Try(1);
}*/

//Bai 2 Bai toan quay lui sinh to hop chap k cua n
int N,X[100],k;
void inkq(){
	int i;
	for(i=1;i<=k;i++){
		printf("%d",X[i]);
	}
		printf("\t");
}
void Try(int i){
	int j;
	for(j=X[i-1]+1;j<=N-k+i;j++){
		X[i]=j;
		if(i==k){
			inkq();
		}
		else{
			Try(i+1);
		}
	}
}
int main(){
	scanf("%d %d",&N,&k);
	Try(1);
}

