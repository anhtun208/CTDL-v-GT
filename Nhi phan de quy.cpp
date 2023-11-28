#include <stdio.h> 

void NhiPhan(int n)
{
      if(n!=0)
       {
             NhiPhan (n/2);
            printf("%d",n%2);
        }
}
int main(){
	int n; 
	scanf("%d",&n); 
	NhiPhan(n); 
} 
