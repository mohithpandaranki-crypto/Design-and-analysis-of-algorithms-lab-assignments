#include<stdio.h>
#include<math.h>

int main(){
	 int x,n,sum=0;
	 int i=1;
	 printf("Enter the value of x and n:");
	 scanf("%d %d",&x,&n);
for(i=0;i<=n;i++){
		 sum+=pow(x,i);
}
	 printf("The sum of the values of gp upto n:%d",sum);
	 return 0;
}
